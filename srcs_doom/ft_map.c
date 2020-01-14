/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_map.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:40:07 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 11:42:14 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	count_width(t_setmap *set)
{
	int	open;
	int	close;

	open = ft_countchar(set->line, '[');
	close = ft_countchar(set->line, ']');

	if (open == close)
		set->tmp = open;
}

int		set_map_size(t_info *info)
{
	t_setmap	set;
	int			ret;

	set.line = NULL;
	set.h = 0;
	set.w = 0;
	if (!(set.fd = open(info->map.name, O_RDONLY)))
		return (-1);
	while ((ret = ft_get_next_line(set.fd, &set.line)) > 0)
	{
		count_width(&set);
		//set.tp = ft_countchar(set.line, '3');
		if (set.tmp > set.w)
			set.w = set.tmp;
		ft_strdel(&set.line);
		set.h++;
	}
	if (ret == -1)
		return (-1);
	info->map.height = set.h + 1;
	info->map.width = set.w + 1;
	/*if (info->map.height < 4 || info->map.width < 4)
		ft_usage("La taille de la map est insufisante !");*/
	//printf("w = %d\nh = %d\n\n", info->map.width, info->map.height);
	return (0);
}

int		create_map(t_info *info)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = malloc(sizeof(t_form *) * info->map.width + 1)))
		return (-1);
	while (i < info->map.width)
	{
		if (!(map[i++] = malloc(sizeof(t_form) * info->map.height + 1)))
			return (-1);
	}
	info->map.map = map;
	return (0);
}

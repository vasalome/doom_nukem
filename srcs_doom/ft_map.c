/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_map.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:40:07 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 17:28:12 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	count_width(t_setmap *set)
{
	set->tmp = ft_countchar(set->line, '0');
	set->tmp += ft_countchar(set->line, '1');
	set->tmp += ft_countchar(set->line, '2');
	set->tmp += ft_countchar(set->line, '3');
	set->tmp += ft_countchar(set->line, '4');
	set->tmp += ft_countchar(set->line, '5');
	set->tmp += ft_countchar(set->line, '6');
	set->tmp += ft_countchar(set->line, '7');
	set->tmp += ft_countchar(set->line, '8');
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
		set.tp = ft_countchar(set.line, '3');
		if (set.tmp > set.w)
			set.w = set.tmp;
		ft_strdel(&set.line);
		set.h++;
	}
	if (ret == -1)
		return (-1);
	info->map.height = set.h + 4;
	info->map.width = set.w + 4;
	if (info->map.height < 4 || info->map.width < 4)
		ft_usage("La taille de la map est insufisante !");
	return (0);
}

int		create_map(t_info *info)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = malloc(sizeof(char *) * info->map.width + 1)))
		return (-1);
	while (i < info->map.width)
	{
		if (!(map[i++] = malloc(sizeof(char) * info->map.height + 1)))
			return (-1);
	}
	info->map.map = map;
	return (0);
}

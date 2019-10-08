/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fill_map.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:40:07 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 17:28:52 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	fill_map_plus(t_fillmap *fill, t_info *info)
{
	if (fill->line[fill->i] == '0' || fill->line[fill->i] == '1'
	|| fill->line[fill->i] == '2' || fill->line[fill->i] == '3'
	|| fill->line[fill->i] == '4' || fill->line[fill->i] == '5'
	|| fill->line[fill->i] == '6' || fill->line[fill->i] == '7'
	|| fill->line[fill->i] == '8')
		info->map.map[fill->x++][fill->y] = fill->line[fill->i];
	if (fill->line[fill->i] == '3')
		tp_destination(fill, info, fill->line, &fill->i);
}

int		read_map(t_info *info, t_fillmap *fill)
{
	int			ret;

	while ((ret = ft_get_next_line(fill->fd, &fill->line)))
	{
		fill->x = 0;
		fill->i = 0;
		info->map.map[fill->x++][fill->y] = '1';
		while (fill->line[fill->i] != '\0')
		{
			fill_map_plus(fill, info);
			fill->i++;
		}
		while (fill->x < info->map.width - 1)
			info->map.map[fill->x++][fill->y] = '1';
		info->map.map[fill->x++][fill->y] = '\0';
		ft_strdel(&fill->line);
		fill->y++;
	}
	if (ret == -1)
		return (-1);
	return (0);
}

int		fill_map(t_info *info)
{
	t_fillmap	fill;

	fill.i = 0;
	fill.x = 0;
	fill.y = 1;
	fill.j = 0;
	fill.line = NULL;
	if (!(fill.fd = open(info->map.name, O_RDONLY)))
		return (-1);
	while (fill.x < info->map.width - 1)
		info->map.map[fill.x++][0] = '1';
	info->map.map[fill.x++][fill.y] = '\0';
	if (read_map(info, &fill) == -1)
		return (-1);
	fill.x = 0;
	while (fill.x < info->map.width - 1)
		info->map.map[fill.x++][fill.y] = '1';
	info->map.map[fill.x][fill.y] = '\0';
	return (0);
}

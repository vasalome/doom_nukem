/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_spawn.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:39:26 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 17:36:30 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

/*
** Spawn player
*/

int		def_spawn(t_info *info)
{
	int		x;
	int		y;

	y = 0;
	info->map.x_spawn = 1.5;
	info->map.y_spawn = 1.5;
	while (y < info->map.height - 1)
	{
		x = 0;
		while (x < info->map.width - 1)
		{
			if (info->map.map[x][y].wall == 0 || info->map.map[x][y].wall == 4 ||\
				info->map.map[x][y].wall == 5 || info->map.map[x][y].wall == 6)
			{
				info->map.x_spawn = x + 0.5;
				info->map.y_spawn = y + 0.5;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		get_spawn(t_info *info)
{
	int		x;
	int		y;

	def_spawn(info);
	x = 0;
	while (x < info->map.width)
	{
		y = 0;
		while (y < info->map.height)
		{
			if (info->map.map[x][y].wall == 2)
			{
				info->map.x_spawn = x + 0.5;
				info->map.y_spawn = y + 0.5;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

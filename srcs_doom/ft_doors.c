/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_doors.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 18:20:06 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 18:20:14 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	move_doors(t_info *info)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < info->map.width)
	{
		while (y < info->map.height)
		{
			if (info->map.map[x][y].wall == 11)
			{
				if (info->map.door_state[x][y] == 1) // Si ma porte est en train de s'ouvrir
				{
					info->map.door_offset[x][y] += info->delta_time / 100;
					info->raycast = 1;
					if (info->map.door_offset[x][y] > 1)
					{
						info->map.door_offset[x][y] = 1;
						info->map.door_state[x][y] = 2; // ma porte est ouverte
						info->map.map[x][y].clip = 1;
					}
				}
				else if (info->map.door_state[x][y] == 3) // en train de se fermer
				{
					info->map.door_offset[x][y] -= info->delta_time / 100;
					info->raycast = 1;
					if (info->map.door_offset[x][y] < 0)
					{
						info->map.door_offset[x][y] = 0;
						info->map.door_state[x][y] = 0;
						info->map.map[x][y].clip = 0;
					}
				}
			}
			y++;
		}
		y = 0;
		x++;
	}
}

void	open_doors(t_info *info)
{
	int		check_x;
	int		check_y;
	int		check_x2;
	int		check_y2;

	check_x = floor(info->player.x_pos + info->player.x_dir);
	check_y = floor(info->player.y_pos + info->player.y_dir);
	check_x2 = floor(info->player.x_pos + info->player.x_dir * 2);
	check_y2 = floor(info->player.y_pos + info->player.y_dir * 2); // peut etre pas besoin de ca comme pas de push wall
	if (info->map.map[check_x][check_y].wall == 11 && info->map.door_state[check_x][check_y] == 0)
		info->map.door_state[check_x][check_y] = 1;
	if (info->map.map[check_x2][check_y2].wall == 11 && info->map.door_state[check_x2][check_y2] == 0)
		info->map.door_state[check_x2][check_y2] = 1;
	if (info->map.map[check_x][check_y].wall == 11 && info->map.door_state[check_x][check_y] == 2)
		info->map.door_state[check_x][check_y] = 3;
	if (info->map.door_state[(int)info->player.x_pos][(int)info->player.y_pos] == 3) // en train de se fermer
		info->map.door_state[(int)info->player.x_pos][(int)info->player.y_pos] = 1;
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_teleport.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/19 14:37:15 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 17:27:54 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	tp_destination_2(t_info *info, char *str, int *i, int x)
{
	if (str[*i + 1] != ' ' && str[*i + 1] != '\0')
		info->player.tp[x] *= 10;
	else
	{
		info->player.tp[x] -= str[*i] - 48;
		info->player.tp[x] *= 10;
		info->player.tp[x] += str[*i] - 48;
	}
}

void	tp_destination(t_fillmap *fill, t_info *info, char *str, int *i)
{
	int		x;

	info->ten = 1;
	*i += 1;
	x = fill->x * 100 + fill->y;
	info->player.tp[x] = 0;
	while (str[*i] != ',' && (str[*i] >= '0' && str[*i] <= '9'))
	{
		info->player.tp[x] += str[*i] - 48;
		if (str[*i + 1] != ',')
			info->player.tp[x] *= 10;
		*i += 1;
	}
	*i += 1;
	info->player.tp[x] = (info->player.tp[x] + 1) * 10;
	while (str[*i] != ' ' && str[*i] != '\0' && (str[*i] >= '0'\
		&& str[*i] <= '9'))
	{
		info->player.tp[x] += str[*i] - 48;
		if (info->ten--)
			tp_destination_2(info, str, i, x);
		*i += 1;
	}
	info->player.tp[x]++;
	fill->j += 2;
}

void	teleport_2(t_info *info)
{
	int		x;
	int		y;
	int		tpx;

	info->player.x_pos -= info->player.x_dir * info->player.move_speed;
	tpx = (int)(info->player.x_pos + 1) * 100 + (int)info->player.y_pos;
	x = (int)(info->player.tp[tpx] / 100);
	y = (int)(info->player.tp[tpx] % 100);
	if (!(x > info->map.width || y > info->map.height || y < 0 || x < 0)\
		&& (info->map.map[x][y].wall == 0 || info->map.map[x][y].wall == 4))
	{
		info->player.x_pos = x + (info->player.x_pos -\
			(int)info->player.x_pos);
		info->player.y_pos = y + (info->player.y_pos -\
			(int)info->player.y_pos);
	}
}

void	teleport(t_info *info)
{
	int		x;
	int		y;
	int		tpx;

	info->player.x_pos += info->player.x_dir * info->player.move_speed;
	tpx = (int)(info->player.x_pos + 1) * 100 + (int)info->player.y_pos;
	x = (int)(info->player.tp[tpx] / 100);
	y = (int)(info->player.tp[tpx] % 100);
	if (!(x > info->map.width || y > info->map.height || y < 0 || x < 0)\
		&& (info->map.map[x][y].wall == 0 || info->map.map[x][y].wall == 4))
	{
		info->player.x_pos = x + (info->player.x_pos -\
			(int)info->player.x_pos);
		info->player.y_pos = y + (info->player.y_pos -\
			(int)info->player.y_pos);
	}
}
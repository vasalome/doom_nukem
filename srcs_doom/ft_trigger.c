/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_trigger.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/04 18:41:04 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 18:56:06 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	ft_trigger(t_info *info)
{
	if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.y_dir * info->player.move_speed)].sp == 1)
	{
		if (info->item.reload < 99)
		{
			info->item.reload += 6;
			if (info->item.reload > 99)
				info->item.reload = 99;
			info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
			+ info->player.y_dir * info->player.move_speed)].sp = 0;
		}
	}
	else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.y_dir * info->player.move_speed)].sp == 2)
	{
		info->item.reload += 1;
		info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.y_dir * info->player.move_speed)].sp = 0;
	}
}

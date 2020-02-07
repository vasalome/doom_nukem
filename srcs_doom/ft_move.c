/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:33:41 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 16:51:32 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

/*
** TESTS INIT POUR COLLISION
*/

void	init_clip(t_info *info) {
	info->player.x_bef = floor(info->map.x_spawn);
	info->player.y_bef = floor(info->map.y_spawn);
	info->player.x_save = floor(info->player.x_pos);
	info->player.y_save = floor(info->player.y_pos);
}

void	bef_save(t_info *info)
{
	if (info->player.x_save == info->player.x_bef)
		info->player.x_save = floor(info->player.x_pos);
	else if (info->player.x_save != floor(info->player.x_pos))
	{
		info->player.x_bef = info->player.x_save;
		info->player.x_save = floor(info->player.x_pos);
	}

	if (info->player.y_save == info->player.y_bef)
		info->player.y_save = floor(info->player.y_pos);
	else if (info->player.y_save != floor(info->player.y_pos))
	{
		info->player.y_bef = info->player.y_save;
		info->player.y_save = floor(info->player.y_pos);
	}
}


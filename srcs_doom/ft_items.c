/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_items.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/03 13:52:14 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 18:55:46 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	reload(t_info *info)
{
	if (info->item.ammo != 6 && info->item.reload > 0)
	{
		if (info->item.ammo > 0)
		{
			while (info->item.ammo != 6 && info->item.reload != 0)
			{
				info->item.reload -= 1;
				info->item.ammo += 1;
			}
		}
		else if (info->item.ammo == 0)
		{
			if (info->item.reload >= 6)
			{
				info->item.ammo = 6;
				info->item.reload -= 6;
			}
			else
			{
				info->item.ammo = info->item.reload;
				info->item.reload = 0;
			}
		}
	}
}

void	shot(t_info *info)
{
	if (info->item.weapon == 1)
	{
		if (info->item.ammo != 0)
		{
			info->item.ammo -= 1;
			// PROJECTILE
			// IMPACT
		}
	}
	else if (info->item.weapon == 2)
	{
		if (info->item.hp > 0 && info->player.life > 0\
				&& info->player.life < 100)
		{
			info->item.hp -= 1;
			info->player.life += 50;
			if (info->player.life > 100)
				info->player.life = 100;
		}
	}
}

void	init_items(t_info *info)
{
	info->item.weapon = 1;
	info->item.ammo = 6;
	info->item.reload = 0;
	info->item.hp = 0;
	info->item.key = 0;
}

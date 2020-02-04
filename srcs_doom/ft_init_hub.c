/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_hub.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/19 13:53:37 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 13:13:27 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	hub_life(t_info *info)
{
	// info->menu[1].img = IMG_Load("hub/Doom_logo.png");
	// info->menu[4].img = IMG_Load("hub/40_hub_2.png");
	// info->menu[5].img = IMG_Load("hub/50_hub_2.png");
	// info->menu[6].img = IMG_Load("hub/60_hub_2.png");
	// info->menu[7].img = IMG_Load("hub/70_hub_2.png");
	// info->menu[8].img = IMG_Load("hub/80_hub_2.png");
	// info->menu[9].img = IMG_Load("hub/90_hub_2.png");
	// info->menu[10].img = IMG_Load("hub/100_hub_2.png");

	info->menu[0].button = IMG_Load("menu/doom_menu.xpm");
	info->menu[0].button = IMG_Load("menu/button_menu.xpm");
	info->menu[0].button = IMG_Load("menu/doom_logo.xpm");
	info->menu[0].button = IMG_Load("menu/doom_logo.xpm");
	info->menu[0].button = IMG_Load("menu/doom_logo.xpm");
}

void	icon_2(t_info *info)
{
	info->wp[5].icon = IMG_Load("weapon/pistol/pistol_icon.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/icon/cg_icon.xpm", &info->wp[5].iconx,\
		&info->wp[5].icony);*/
	info->wp[6].icon = IMG_Load("weapon/pistol/pistol_icon.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/icon/pl_icon.xpm", &info->wp[6].iconx,\
		&info->wp[6].icony);*/
	info->wp[8].icon = IMG_Load("weapon/pistol/pistol_icon.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/icon/rock_icon.xpm", &info->wp[8].iconx,\
		&info->wp[8].icony);*/
	info->wp[9].icon = IMG_Load("weapon/pistol/pistol_icon.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/icon/bfg_icon.xpm", &info->wp[9].iconx,\
		&info->wp[9].icony);*/
}

void	icon(t_info *info)
{
	info->wp[0].icon = IMG_Load("weapon/pistol/pistol_icon.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/icon/finger_icon.xpm", &info->wp[0].iconx,\
		&info->wp[0].icony);*/
	info->wp[1].icon = IMG_Load("weapon/pistol/pistol_icon.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/icon/p_icon.xpm", &info->wp[1].iconx,\
		&info->wp[1].icony);*/
	info->wp[2].icon = IMG_Load("weapon/pistol/pistol_icon.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/icon/cs_icon.xpm", &info->wp[2].iconx,\
		&info->wp[2].icony);*/
	info->wp[3].icon = IMG_Load("weapon/pistol/pistol_icon.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/icon/shot_icon.xpm", &info->wp[3].iconx,\
		&info->wp[3].icony);*/
	info->wp[4].icon = IMG_Load("weapon/pistol/pistol_icon.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/icon/s_s_icon.xpm", &info->wp[4].iconx,\
		&info->wp[4].icony);*/
	icon_2(info);
}

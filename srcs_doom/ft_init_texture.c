/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_texture.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/19 13:53:37 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 17:11:22 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void			init_textures(t_info *info)
{
	info->menu[0] = IMG_Load("menu/doom_menu.xpm");
	info->menu[1] = IMG_Load("menu/button_menu.xpm");
	info->menu[2] = IMG_Load("menu/doom_logo.xpm");

	info->pistol[0] = IMG_Load("items/gun.png");
	info->pistol[1] = IMG_Load("items/leech.png");
	info->pistol[2] = IMG_Load("items/kick.png");

	info->wt[0].img = IMG_Load("wall/tex/wall1.xpm");
	info->wt[1].img = IMG_Load("wall/tex/wall2.xpm");
	info->wt[2].img = IMG_Load("wall/tex/wall3.xpm");
	info->wt[3].img = IMG_Load("wall/tex/wall4.xpm");
	info->wt[4].img = IMG_Load("wall/tex/wall5.xpm");
	info->wt[5].img = IMG_Load("wall/tex/wall6.xpm");
	info->wt[6].img = IMG_Load("wall/tex/wall7.xpm");
	info->wt[7].img = IMG_Load("wall/tex/wall8.xpm");
	info->wt[8].img = IMG_Load("wall/tex/grillage.xpm");

	info->wt[9].img = IMG_Load("wall/tex/floor1.xpm");
	info->wt[10].img = IMG_Load("wall/tex/floor2.xpm");
	
	info->wt[12].img = IMG_Load("wall/tex/door.xpm");

	////
	// info->wall_tex[0] = IMG_Load("wall/tex/wall1.xpm");
	// info->wall_tex[1] = IMG_Load("wall/tex/wall2.xpm");
	// info->wall_tex[2] = IMG_Load("wall/tex/wall3.xpm");
	// info->wall_tex[3] = IMG_Load("wall/tex/wall4.xpm");
	// info->wall_tex[4] = IMG_Load("wall/tex/wall5.xpm");
	// info->wall_tex[5] = IMG_Load("wall/tex/wall6.xpm");
	// info->wall_tex[6] = IMG_Load("wall/tex/wall7.xpm");
	// info->wall_tex[7] = IMG_Load("wall/tex/wall8.xpm");
	// info->wall_tex[8] = IMG_Load("wall/tex/grillage.xpm");

	// info->floor_tex[9] = IMG_Load("wall/tex/floor1.xpm");
	// info->floor_tex[10] = IMG_Load("wall/tex/floor2.xpm");
}

// void	textures_list(t_info *info)
// {
// 	info->wt[0].img = IMG_Load("wall/scpwall.png");
// 	info->wt[1].img = IMG_Load("wall/scpwall3.png");
// 	info->wt[2].img = IMG_Load("wall/scpwall3-1.png");
// 	info->wt[3].img = IMG_Load("wall/scpwall3.png");
// 	info->wt[4].img = IMG_Load("wall/floor2.png");
// 	info->wt[5].img = 0;
// 	info->wt[6].img = IMG_Load("wall/door.png");
// 	info->wt[7].img = 0;
// 	info->wt[8].img = 0;
// 	info->wt[9].img = 0;

// 	//sol et transparent
// 	info->wt[16].img = IMG_Load("wall/scpfloor2.png");
// 	info->wt[17].img = IMG_Load("wall/scpfloor.png");
// 	info->wt[18].img = IMG_Load("wall/transparent.png");
// 	info->wt[19].img = 0;

// 	20 a 30 dans skybox pour l'instant
// 	info->wt[20].img = ;
// 	info->wt[21].img = ;
// 	info->wt[22].img = ;
// 	info->wt[23].img = ;
// 	info->wt[24].img = ;
// 	info->wt[25].img = ;
// 	info->wt[26].img = ;
// 	info->wt[27].img = ;
// 	info->wt[28].img = ;
// 	info->wt[29].img = ;
// 	info->wt[30].img = ;
// }

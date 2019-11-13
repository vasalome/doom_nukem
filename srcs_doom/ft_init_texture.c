/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_texture.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/19 14:00:48 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 16:27:05 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	textures_sky(t_info *info)
{
	//int		i = 25;
	
	// info->wt[25].img = IMG_Load("wall/floor2.png");
	// info->wt[26].img = IMG_Load("wall/floor2.png");
	// info->wt[27].img = IMG_Load("wall/floor2.png");
	// info->wt[28].img = IMG_Load("wall/floor2.png");
	// info->wt[29].img = IMG_Load("wall/floor2.png");
	// info->wt[30].img = IMG_Load("wall/floor2.png");

	// SDL_Surface	*ecran, *test;
	// SDL_Rect	pos_img;
	// pos_img.x = 0;
	// pos_img.y = 0;
	// test = IMG_Load("wall/floor2.png");
	// ecran = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);
	// SDL_BlitSurface(test, NULL, ecran, &pos_img);
}

void	textures_floor(t_info *info)
{
	info->wt[16].img = IMG_Load("wall/scpfloor2.png");
	info->wt[17].img = IMG_Load("wall/scpfloor.png");
}

void	textures_door_2(t_info *info)
{
	info->wt[12].img = IMG_Load("wall/scpwall3-1.png");
	info->wt[13].img = IMG_Load("wall/scpwall3-1.png");
	info->wt[14].img = IMG_Load("wall/scpwall3-1.png");
	info->wt[15].img = IMG_Load("wall/scpwall3-1.png");
}

void	textures_door_1(t_info *info)
{
	info->wt[4].img = IMG_Load("wall/scpwall3-1.png");
	info->wt[5].img = IMG_Load("wall/scpwall3-1.png");
	info->wt[6].img = IMG_Load("wall/scpwall3-1.png");
	info->wt[7].img = IMG_Load("wall/scpwall3-1.png");
}

void	textures_wall_2(t_info *info)
{					
	info->wt[8].img = IMG_Load("wall/scpwall.png");
	info->wt[9].img = IMG_Load("wall/scpwall.png");
	info->wt[10].img = IMG_Load("wall/scpwall.png");
	info->wt[11].img = IMG_Load("wall/scpwall.png");
}

void	textures_wall_1(t_info *info)
{
	info->wt[0].img = IMG_Load("wall/scpwall3.png");
	info->wt[1].img = IMG_Load("wall/scpwall3.png");
	info->wt[2].img = IMG_Load("wall/scpwall3.png");
	info->wt[3].img = IMG_Load("wall/scpwall3.png");
}

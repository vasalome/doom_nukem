/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hud.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 15:54:11 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 17:26:10 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void    lifebar()
{
    
}

void    draw_hud(t_info *info)
{
    info->wt[19].img = IMG_Load("wall/bars.png");
    info->wt[19].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
		info->wt[19].img);
    info->wt[19].rect.x = 0;
	info->wt[19].rect.y = 0;
	info->wt[19].rect.w = WIDTH;
	info->wt[19].rect.h = HEIGHT;
}

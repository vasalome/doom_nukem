/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hud.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 15:54:11 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 16:56:46 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void    lifebar()
{
    
}

void	render_hud(t_info *info)
{
	if (info->item.key == 1)
		SDL_RenderCopy(info->win.renderer, info->hud[1].texture, NULL, &info->hud[1].rect);
	SDL_RenderCopy(info->win.renderer, info->hud[0].texture, NULL, &info->hud[0].rect);

	SDL_RenderCopy(info->win.renderer, info->hud[3].texture, NULL, &info->hud[3].rect);
}

void	draw_head(t_info *info)
{
	info->hud[3].img = IMG_Load("hud/hud_face_ex.png");
	info->hud[3].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
		info->hud[3].img);
	info->hud[3].rect.x = 0;
	info->hud[3].rect.y = 0;
	info->hud[3].rect.w = WIDTH;
	info->hud[3].rect.h = HEIGHT;
}

void    draw_hud(t_info *info)
{
    info->hud[0].img = IMG_Load("hud/hud_gen.png");
	info->hud[0].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
		info->hud[0].img);
	info->hud[0].rect.x = 0;
	info->hud[0].rect.y = 0;
	info->hud[0].rect.w = WIDTH;
	info->hud[0].rect.h = HEIGHT;

	info->hud[1].img = IMG_Load("hud/hud_key.png");
	info->hud[1].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
		info->hud[1].img);
	info->hud[1].rect.x = 0;
	info->hud[1].rect.y = 0;
	info->hud[1].rect.w = WIDTH;
	info->hud[1].rect.h = HEIGHT;

	draw_head(info);
}

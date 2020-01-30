/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hud.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 15:54:11 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 16:08:13 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void    lifebar()
{
    
}

void	render_hud(t_info *info, SDL_Event *event)
{
	if (info->item.key == 1)
		SDL_RenderCopy(info->win.renderer, info->hud[1].texture, NULL, &info->hud[1].rect);
	SDL_RenderCopy(info->win.renderer, info->hud[0].texture, NULL, &info->hud[0].rect);
	// I NEED TO REPAIR HEAD
	
	// if (// TIME POUR CLIGNER DES YEUX  )
	// 	SDL_RenderCopy(info->win.renderer, info->hud[6].texture, NULL, &info->hud[6].rect);
	// else
	// {
		if (event->motion.xrel <= -2 && event->motion.xrel >= 2)//info->player.head == 1)
			{printf("%d\n",event->motion.xrel);
			SDL_RenderCopy(info->win.renderer, info->hud[3].texture, NULL, &info->hud[3].rect);}
		else if (event->motion.xrel < 2)
			{printf("%d\n",event->motion.xrel);
			SDL_RenderCopy(info->win.renderer, info->hud[4].texture, NULL, &info->hud[4].rect);}
		else if (event->motion.xrel > 2)
			{printf("%d\n",event->motion.xrel);
			SDL_RenderCopy(info->win.renderer, info->hud[5].texture, NULL, &info->hud[5].rect);}
	// }
}

void	draw_head(t_info *info)
{
	info->hud[3].img = IMG_Load("hud/head/1/fst_m.png");
	info->hud[3].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
		info->hud[3].img);
	info->hud[3].rect.x = 75;
	info->hud[3].rect.y = 537;
	info->hud[3].rect.w = 120;
	info->hud[3].rect.h = 145;

	info->hud[4].img = IMG_Load("hud/head/1/fst_r.png");
	info->hud[4].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
		info->hud[4].img);
	info->hud[4].rect.x = 75;
	info->hud[4].rect.y = 535;
	info->hud[4].rect.w = 120;
	info->hud[4].rect.h = 145;

	info->hud[5].img = IMG_Load("hud/head/1/fst_l.png");
	info->hud[5].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
		info->hud[5].img);
	info->hud[5].rect.x = 75;
	info->hud[5].rect.y = 535;
	info->hud[5].rect.w = 120;
	info->hud[5].rect.h = 145;

	info->hud[6].img = IMG_Load("hud/head/1/fst_c.png");
	info->hud[6].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
		info->hud[6].img);
	info->hud[6].rect.x = 75;
	info->hud[6].rect.y = 536;
	info->hud[6].rect.w = 120;
	info->hud[6].rect.h = 145;
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

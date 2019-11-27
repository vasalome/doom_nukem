/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_skybox.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/19 14:00:48 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 16:38:50 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	layer_2(double front_offset, t_info *info)
{
	info->wt[25].rect.x = front_offset * 2;
	info->wt[25].rect.y = (info->fps.rect.y) - 200;
	info->wt[25].rect.w = WIDTH;
	info->wt[25].rect.h = HEIGHT;
	info->wt[26].rect.x = (front_offset * 2) - WIDTH;
	info->wt[26].rect.y = (info->fps.rect.y) - 200;
	info->wt[26].rect.w = WIDTH;
	info->wt[26].rect.h = HEIGHT;
	info->wt[27].rect.x = (front_offset * 2) - (WIDTH * 2);
	info->wt[27].rect.y = (info->fps.rect.y)- 200;
	info->wt[27].rect.w = WIDTH;
	info->wt[27].rect.h = HEIGHT;
	info->wt[28].rect.x = (front_offset * 2) - (WIDTH * 3);
	info->wt[28].rect.y = (info->fps.rect.y)- 200;
	info->wt[28].rect.w = WIDTH;
	info->wt[28].rect.h = HEIGHT;
}

void	layer_1(double front_offset, t_info *info)
{
	info->wt[20].rect.x = front_offset * 4;
	info->wt[20].rect.y = (info->fps.rect.y) - 200;
	info->wt[20].rect.w = WIDTH;
	info->wt[20].rect.h = HEIGHT;
	info->wt[21].rect.x = (front_offset * 4) - WIDTH;
	info->wt[21].rect.y = (info->fps.rect.y) - 200;
	info->wt[21].rect.w = WIDTH;
	info->wt[21].rect.h = HEIGHT;
	info->wt[22].rect.x = (front_offset * 4) - (WIDTH * 2);
	info->wt[22].rect.y = (info->fps.rect.y) - 200;
	info->wt[22].rect.w = WIDTH;
	info->wt[22].rect.h = HEIGHT;
	info->wt[23].rect.x = (front_offset * 4) - (WIDTH * 3);
	info->wt[23].rect.y = (info->fps.rect.y) - 200;
	info->wt[23].rect.w = WIDTH;
	info->wt[23].rect.h = HEIGHT;
	info->wt[24].rect.x = (front_offset * 4) - (WIDTH * 4);
	info->wt[24].rect.y = (info->fps.rect.y) - 200;
	info->wt[24].rect.w = WIDTH;
	info->wt[24].rect.h = HEIGHT;
}

void	init_sky_2(t_info *info)
{
	info->wt[20].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
			info->wt[20].img);
	info->wt[21].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
			info->wt[21].img);
	info->wt[22].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
			info->wt[22].img);
	info->wt[23].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
			info->wt[23].img);
	info->wt[24].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
			info->wt[24].img);
	info->wt[25].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
			info->wt[25].img);
	info->wt[26].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
			info->wt[26].img);
	info->wt[27].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
			info->wt[27].img);
	info->wt[28].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
			info->wt[28].img);
	info->wt[29].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
			info->wt[29].img);
	info->wt[30].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
			info->wt[30].img);
}

void	init_sky_1(t_info *info)
{
	info->wt[20].img = IMG_Load("wall/skybox1.png");
	info->wt[21].img = IMG_Load("wall/skybox1.png");
	info->wt[22].img = IMG_Load("wall/skybox1.png");
	info->wt[23].img = IMG_Load("wall/skybox1.png");
	info->wt[24].img = IMG_Load("wall/skybox1.png");
	info->wt[25].img = IMG_Load("wall/skybox2.png");
	info->wt[26].img = IMG_Load("wall/skybox2.png");
	info->wt[27].img = IMG_Load("wall/skybox2.png");
	info->wt[28].img = IMG_Load("wall/skybox2.png");
	info->wt[29].img = IMG_Load("wall/testciel3.png");
	info->wt[30].img = IMG_Load("wall/testciel3.png");
}

void	draw_skybox(t_info *info)
{
	double dir_offset;
	double fore_offset;
	double front_offset;

	dir_offset = (atan2(info->player.y_dir, info->player.x_dir) + M_PI) / M_PI;
	fore_offset = floor(dir_offset * WIDTH);
	front_offset = floor(fore_offset / 2);
	init_sky_1(info);
	init_sky_2(info);
	layer_1(front_offset, info);
	layer_2(front_offset, info);
	info->wt[29].rect.x = front_offset;
	info->wt[29].rect.y = (info->fps.rect.y) - 200;
	info->wt[29].rect.w = WIDTH;
	info->wt[29].rect.h = HEIGHT;
	info->wt[30].rect.x = front_offset - WIDTH;
	info->wt[30].rect.y = (info->fps.rect.y) - 200;
	info->wt[30].rect.w = WIDTH;
	info->wt[30].rect.h = HEIGHT;
}

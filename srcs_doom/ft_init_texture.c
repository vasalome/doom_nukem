/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_texture.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/19 14:00:48 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 13:46:11 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	draw_skybox(t_info *info)
{
	double dirOffset = (atan2(info->player.y_dir, info->player.x_dir) + M_PI) / M_PI;
	double foreOffset = floor(dirOffset * WIDTH);
	double frontOffset = floor(foreOffset / 2);
	double midOffset = floor(foreOffset / 4);
	double backOffset = floor(foreOffset / 8);

<<<<<<< HEAD
	//double hHalf = round(HEIGHT / 2);
	//double midWidth = WIDTH / 1.5;
	//double midHeight = hHalf / 1.5;
	//double mapWidth = WIDTH * 4;
	//double midYPos = (hHalf / 3 - mapWidth) + distedge; // mapWidth is la valeur max de distedge
	//double backWidth = WIDTH / 2;
	//double backHeight = hHalf / 2;


	info->wt[25].img = IMG_Load("wall/bars.png");
	info->wt[26].img = IMG_Load("wall/bars.png");
	info->wt[27].img = IMG_Load("wall/skybox1.png");
	info->wt[28].img = IMG_Load("wall/skybox1.png");
	info->wt[29].img = IMG_Load("wall/skybox2.png");
	info->wt[30].img = IMG_Load("wall/skybox2.png");

=======
	info->wt[20].img = IMG_Load("wall/skybox1.png");
	info->wt[21].img = IMG_Load("wall/skybox1.png");
	info->wt[22].img = IMG_Load("wall/skybox2.png");
	info->wt[23].img = IMG_Load("wall/skybox2.png");
	info->wt[24].img = IMG_Load("wall/skybox2.png");
	info->wt[25].img = IMG_Load("wall/skybox2.png");
	info->wt[26].img = IMG_Load("wall/skybox3.png");
	info->wt[27].img = IMG_Load("wall/skybox3.png");
	info->wt[28].img = IMG_Load("wall/skybox3.png");
	info->wt[29].img = IMG_Load("wall/skybox3.png");
	info->wt[30].img = IMG_Load("wall/skybox3.png");

	info->wt[20].texture = SDL_CreateTextureFromSurface(info->win.renderer, info->wt[20].img);
	info->wt[21].texture = SDL_CreateTextureFromSurface(info->win.renderer, info->wt[21].img);
	info->wt[22].texture = SDL_CreateTextureFromSurface(info->win.renderer, info->wt[22].img);
	info->wt[23].texture = SDL_CreateTextureFromSurface(info->win.renderer, info->wt[23].img);
	info->wt[24].texture = SDL_CreateTextureFromSurface(info->win.renderer, info->wt[24].img);
>>>>>>> 44caafc65b4a78e1cdabc8ec4e7813c6fd9a84fc
	info->wt[25].texture = SDL_CreateTextureFromSurface(info->win.renderer, info->wt[25].img);
	info->wt[26].texture = SDL_CreateTextureFromSurface(info->win.renderer, info->wt[26].img);
	info->wt[27].texture = SDL_CreateTextureFromSurface(info->win.renderer, info->wt[27].img);
	info->wt[28].texture = SDL_CreateTextureFromSurface(info->win.renderer, info->wt[28].img);
	info->wt[29].texture = SDL_CreateTextureFromSurface(info->win.renderer, info->wt[29].img);
	info->wt[30].texture = SDL_CreateTextureFromSurface(info->win.renderer, info->wt[30].img);

	info->wt[20].rect.x = frontOffset;
	info->wt[20].rect.y = (info->fps.rect.y * 0.15);// + 40;
	info->wt[20].rect.w = WIDTH;
	info->wt[20].rect.h = HEIGHT;

	info->wt[21].rect.x = frontOffset - WIDTH;
	info->wt[21].rect.y = (info->fps.rect.y * 0.15);// + 40;
	info->wt[21].rect.w = WIDTH;
	info->wt[21].rect.h = HEIGHT;

	info->wt[22].rect.x = frontOffset * 2;
	info->wt[22].rect.y = (info->fps.rect.y * 0.10);// + 40;
	info->wt[22].rect.w = WIDTH;
	info->wt[22].rect.h = HEIGHT;

	info->wt[23].rect.x = (frontOffset*2) - WIDTH;
	info->wt[23].rect.y = (info->fps.rect.y * 0.10);// + 40;
	info->wt[23].rect.w = WIDTH;
	info->wt[23].rect.h = HEIGHT;

	info->wt[24].rect.x = (frontOffset*2) - (WIDTH * 2);
	info->wt[24].rect.y = (info->fps.rect.y * 0.10);// + 40;
	info->wt[24].rect.w = WIDTH;
	info->wt[24].rect.h = HEIGHT;

	info->wt[25].rect.x = (frontOffset*2) - (WIDTH * 3);
	info->wt[25].rect.y = (info->fps.rect.y * 0.10);// + 40;
	info->wt[25].rect.w = WIDTH;
	info->wt[25].rect.h = HEIGHT;

	info->wt[26].rect.x = frontOffset * 4;
	info->wt[26].rect.y = (info->fps.rect.y * 0.10);// + 40;
	info->wt[26].rect.w = WIDTH;
	info->wt[26].rect.h = HEIGHT;

	info->wt[27].rect.x = (frontOffset*4) - WIDTH;
	info->wt[27].rect.y = (info->fps.rect.y * 0.10);// + 40;
	info->wt[27].rect.w = WIDTH;
	info->wt[27].rect.h = HEIGHT;

	info->wt[28].rect.x = (frontOffset*4) - (WIDTH * 2);
	info->wt[28].rect.y = (info->fps.rect.y * 0.10);// + 40;
	info->wt[28].rect.w = WIDTH;
	info->wt[28].rect.h = HEIGHT;

	info->wt[29].rect.x = (frontOffset*4) - (WIDTH * 3);
	info->wt[29].rect.y = (info->fps.rect.y * 0.10);// + 40;
	info->wt[29].rect.w = WIDTH;
	info->wt[29].rect.h = HEIGHT;

	info->wt[30].rect.x = (frontOffset*4) - (WIDTH * 4);
	info->wt[30].rect.y = (info->fps.rect.y * 0.10);// + 40;
	info->wt[30].rect.w = WIDTH;
	info->wt[30].rect.h = HEIGHT;
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

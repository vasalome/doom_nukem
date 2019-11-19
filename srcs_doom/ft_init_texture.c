/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_texture.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/19 14:00:48 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 15:05:12 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	draw_skybox(t_info *info)
{
	/*double dx = 12 - info->player.x_pos;
	double dy = 12 - info->player.y_pos;

	double rx = 12 * info->player.x_pos;
	double ry = 12 * info->player.y_pos;

	double edgevecx = dx + rx;
	double edgevecy = dy + ry;

	double edgex = info->player.x_pos + edgevecx;
	double edgey = info->player.y_pos + edgevecy;

	double distedge = sqrt((edgex - info->player.x_pos)*(edgex - info->player.x_pos) + (edgey - info->player.y_pos)*(edgey - info->player.y_pos));
	double distedge2 = distedge + distedge;*/

	double dirOffset = (atan2(info->player.y_dir, info->player.x_dir) + M_PI) / M_PI;
	double foreOffset = floor(dirOffset * WIDTH);
	double frontOffset = floor(foreOffset / 2);
	double midOffset = floor(foreOffset / 4);
	double backOffset = floor(foreOffset / 8);

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

	info->wt[25].texture = SDL_CreateTextureFromSurface(info->win.renderer, info->wt[25].img);
	info->wt[26].texture = SDL_CreateTextureFromSurface(info->win.renderer, info->wt[26].img);
	info->wt[27].texture = SDL_CreateTextureFromSurface(info->win.renderer, info->wt[27].img);
	info->wt[28].texture = SDL_CreateTextureFromSurface(info->win.renderer, info->wt[28].img);
	info->wt[29].texture = SDL_CreateTextureFromSurface(info->win.renderer, info->wt[29].img);
	info->wt[30].texture = SDL_CreateTextureFromSurface(info->win.renderer, info->wt[30].img);
	//printf("frontOffset: %f\nmidOffset: %f\nbackOffset: %f\n", frontOffset, midOffset, backOffset);

	info->wt[25].rect.x = frontOffset;
	info->wt[25].rect.y = (info->fps.rect.y * 0.15);// + 40;
	info->wt[25].rect.w = WIDTH;
	info->wt[25].rect.h = HEIGHT;

	info->wt[26].rect.x = frontOffset - WIDTH;
	info->wt[26].rect.y = (info->fps.rect.y * 0.15);// + 40;
	info->wt[26].rect.w = WIDTH;
	info->wt[26].rect.h = HEIGHT;

	info->wt[27].rect.x = midOffset;
	info->wt[27].rect.y = (info->fps.rect.y * 0.10);// + 40;
	info->wt[27].rect.w = WIDTH;
	info->wt[27].rect.h = HEIGHT;

	info->wt[28].rect.x = midOffset - WIDTH;
	info->wt[28].rect.y = (info->fps.rect.y * 0.10);// + 40;
	info->wt[28].rect.w = WIDTH;
	info->wt[28].rect.h = HEIGHT;

	info->wt[29].rect.x = backOffset;
	info->wt[29].rect.y = (info->fps.rect.y * 0.05);// + 40;
	info->wt[29].rect.w = WIDTH;
	info->wt[29].rect.h = HEIGHT;

	info->wt[30].rect.x = backOffset - WIDTH;
	info->wt[30].rect.y = (info->fps.rect.y * 0.05);// + 40;
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

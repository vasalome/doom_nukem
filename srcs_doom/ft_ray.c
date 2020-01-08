/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ray.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:35:35 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 11:59:51 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

int     ray_circ(t_inter *inter, double p1x, double p1y, double p2x, double p2y, double scx, double scy, double r)
{
    double a, b, c;
    double bb4ac;
	double dp1 = 0;
	double dp2 = 0;
	
    dp1 = p2x - p1x;
    dp2 = p2y - p1y;
    a = dp1 * dp1 + dp2 * dp2;
    b = 2 * (dp1 * (p1x - scx) + dp2 * (p1y - scy));
    c = scx * scx + scy * scy;
    c += p1x * p1x + p1y * p1y;
    c -= 2 * (scx * p1x + scy * p1y);
    c -= r * r;
    bb4ac = b * b - 4 * a * c;
    if (bb4ac < 0)
	{
    	return(0);
	}
    inter->x = (-b + sqrt(bb4ac)) / (2 * a);
    inter->y = (-b - sqrt(bb4ac)) / (2 * a);
    return(1);
}

void	intersectLine(t_inter *inter)
{
	double	A1 = inter->p1y - inter->p0y;
	double	B1 = inter->p0x - inter->p1x;
	double	C1 = A1 * inter->p0x + B1 * inter->p0y;
	double	A2 = inter->p3y - inter->p2y;
	double	B2 = inter->p2x - inter->p3x;
	double	C2 = A2 * inter->p2x + B2 * inter->p2y;
	double	denominator = A1 * B2 - A2 * B1;

	inter->x = (B2 * C1 - B1 * C2) / denominator;
	inter->y = (A1 * C2 - A2 * C1) / denominator;
}

void	ray_casting_init(t_info *info, int x)
{
	int angleSide = 0;
	info->player.x_camera = 2 * x / (double)(info->win.w) - 1;
	info->ray.x_ray_position = info->player.x_pos;
	info->ray.y_ray_position = info->player.y_pos;
	info->ray.x_ray_direction = info->player.x_dir + info->player.x_plane *\
		info->player.x_camera;
	info->ray.y_ray_direction = info->player.y_dir + info->player.y_plane *\
		info->player.x_camera;
	
	info->map.x = (int)info->player.x_pos;
	info->map.y = (int)info->player.y_pos;
	info->wall.alpha = 0;
	
	wall_detection_init_x(info);
	
	while((info->map.hit == 0) && ((info->map.x >= 0 && info->map.x < info->map.width) && (info->map.y >= 0 && info->map.y < info->map.height)))
	{
		/*printf("pass\n");
	fflush(stdout);*/
		info->map.hit = 0;
		info->map.yOffset = 0;
		info->map.xOffset = 0;
		if (info->ray.x_side_distance < info->ray.y_side_distance)
		{
			info->ray.x_side_distance += info->ray.x_delta_distance;
			info->map.x += info->map.x_step;
			info->wall.side = 0;
			
		}
		else
		{
			info->ray.y_side_distance += info->ray.y_delta_distance;
			info->map.y += info->map.y_step;
			info->wall.side = 1;
		}
	/*printf("%d %d\n", info->map.x, info->map.y);
	fflush(stdout);*/
		int rayTex = info->map.map[info->map.x][info->map.y].wall;
		
		if (rayTex == 11)// && info->map.door_state[info->map.x][info->map.y] != 2)// Et que doorState != ouverte // Portes
		{
			info->map.hit = 1;
			if (info->wall.side == 1)
			{
				info->map.yOffset = 0.5 * info->map.y_step;
				info->wall.wall_distance = info->map.y - info->player.y_pos + info->map.yOffset + (1 - info->map.y_step) / 2 / info->ray.y_ray_direction;
				info->wall.wall_x = info->player.x_pos + info->wall.wall_distance * info->ray.x_ray_direction;
				info->wall.wall_x -= floor(info->wall.wall_x);
				if (info->ray.y_side_distance - (info->ray.y_delta_distance / 2) < info->ray.x_side_distance)
				{
					if (1 - info->wall.wall_x <= info->map.door_offset[info->map.x][info->map.y])
					{
						info->map.hit = 0;
						info->map.yOffset = 0;
					}
				}
				else // Si superieur alors on fait passer le rayon derriere la porte
				{
					info->map.x += info->map.x_step;
					info->wall.side = 0;
					rayTex = 1; //door frame = côté des portes // autre texture
					info->map.yOffset = 0;
				}
			}
			else
			{
				info->map.xOffset = 0.5 * info->map.x_step;
				info->wall.wall_distance = info->map.x - info->player.x_pos + info->map.xOffset + (1 - info->map.x_step) / 2 / info->ray.x_ray_direction;
				info->wall.wall_x = info->player.y_pos + info->wall.wall_distance * info->ray.y_ray_direction;
				info->wall.wall_x -= floor(info->wall.wall_x);
				if (info->ray.x_side_distance - (info->ray.x_delta_distance / 2) < info->ray.y_side_distance)
				{
					if (1 - info->wall.wall_x < info->map.door_offset[info->map.x][info->map.y])
					{
						info->map.hit = 0;
						info->map.xOffset = 0;
					}
				}
				else
				{
					info->map.y += info->map.y_step;
					info->wall.side = 1;
					rayTex = 1;
					info->map.xOffset = 0;
				}
			}
		}
		if (rayTex == 7)
		{
			double wallX1 = info->map.x;
			double wallY1 = info->map.y + 1;
			double wallX2 = info->map.x + 1;
			double wallY2 = info->map.y;
			t_inter inter;
			inter.p0x = info->ray.x_ray_position;
			inter.p0y = info->ray.y_ray_position;
			inter.p1x = info->ray.x_ray_position + info->ray.x_ray_direction;
			inter.p1y = info->ray.y_ray_position + info->ray.y_ray_direction;
			inter.p2x = wallX1;
			inter.p2y = wallY1;
			inter.p3x = wallX2;
			inter.p3y = wallY2;
			intersectLine(&inter);
			if(inter.x >= info->map.x && inter.x <= info->map.x + 1 && inter.y >= info->map.y && inter.y <= info->map.y + 1)
			{
				info->map.hit = 1;
				info->wall.side = 2;
				info->wall.wall_distance = ((inter.x - info->ray.x_ray_position + inter.y - info->ray.y_ray_position) / 2) / ((info->ray.x_ray_direction + info->ray.y_ray_direction) / 2);
			}
		}
		else if (rayTex == 8)
		{
			double wallX1 = info->map.x;
			double wallY1 = info->map.y;
			double wallX2 = info->map.x + 1;
			double wallY2 = info->map.y + 1;
			t_inter inter;
			inter.p0x = info->ray.x_ray_position;
			inter.p0y = info->ray.y_ray_position;
			inter.p1x = info->ray.x_ray_position + info->ray.x_ray_direction;
			inter.p1y = info->ray.y_ray_position + info->ray.y_ray_direction;
			inter.p2x = wallX1;
			inter.p2y = wallY1;
			inter.p3x = wallX2;
			inter.p3y = wallY2;
			intersectLine(&inter);
			if(inter.x >= info->map.x && inter.x <= info->map.x + 1 && inter.y >= info->map.y && inter.y <= info->map.y + 1)
			{
				info->map.hit = 1;
				info->wall.side = 2;
				info->wall.wall_distance = ((inter.x - info->ray.x_ray_position + inter.y - info->ray.y_ray_position) / 2) / ((info->ray.x_ray_direction + info->ray.y_ray_direction) / 2);
			}
		}
		else if (rayTex == 9)
		{
			int		intersectDist;
			t_inter inter;

			intersectDist = ray_circ(&inter, info->player.x_pos, info->player.y_pos, info->player.x_pos + info->ray.x_ray_direction, info->player.y_pos + info->ray.y_ray_direction, info->map.x + 0.5, info->map.y + 0.5, 0.5);
			if (intersectDist != 0)
			{
				info->map.hit = 1;
			 	info->wall.side = 3;
				t_inter interse;
				interse.x = info->player.x_pos + info->ray.x_ray_direction * inter.y;
				interse.y = info->player.y_pos + info->ray.y_ray_direction * inter.y;
				info->wall.wall_distance = ((interse.x - info->player.x_pos + interse.y - info->player.y_pos) / 2) / ((info->ray.x_ray_direction + info->ray.y_ray_direction) / 2);
				info->wall.wall_x = atan2(info->map.y + 0.5 - interse.y, info->map.x + 0.5 - interse.x) / (M_PI * 2);
			 	info->wall.wall_x += info->wall.wall_x;
			}
		}
		else if (rayTex == 10)
		{
			if (info->wall.side == 1)
			{
				if (info->map.y_step == -1)
					if (info->ray.y_side_distance - (info->ray.y_delta_distance / 2) < info->ray.x_side_distance)
					{
						info->map.hit = 1;
						info->map.yOffset = 0.5 + info->map.y_step;
					}
				/*else if (info->map.y_step == 1)
					if (info->ray.y_side_distance - (info->ray.y_delta_distance / 2) < info->ray.x_side_distance)
					{
						info->map.hit = 1;
						info->map.yOffset = -0.5 + info->map.y_step;
					}*/
			}
			else if (info->wall.side == 0)
			{
				if (info->map.x_step == -1)
					if (info->ray.x_side_distance - (info->ray.x_delta_distance / 2) < info->ray.y_side_distance)
					{
						info->map.hit = 1;
						info->map.xOffset = 0.5 + info->map.x_step;
					}
				/*else if (info->map.x_step == 1)
					if (info->ray.x_side_distance - (info->ray.x_delta_distance / 2) < info->ray.y_side_distance)
					{
						info->map.hit = 1;
						info->map.xOffset = -0.5 + info->map.x_step;
					}*/
			}
		}
		
		 /* else if (rayTex == 1)
		  {
		 	if (info->wall.side == 1 && info->map.map[info->map.x][info->map.y - info->map.y_step].wall == 11)
		 		rayTex = 1;
			 if (info->wall.side == 0 && info->map.map[info->map.x - info->map.x_step][info->map.y].wall == 11)
		 		rayTex = 1;
		 	info->map.hit = 1;
		  }*/
		else if (rayTex == 1)
		{
			info->map.hit = 1;
		}
		choose_texture_1(info);
		
	}
		if(info->map.hit == 0)
		info->wall.alpha = 0;
		if (info->map.x < 0)
		info->map.x = 0;
		if (info->map.x >= info->map.width)
		info->map.x = info->map.width - 1;
		if (info->map.y < 0)
		info->map.y = 0;
		if (info->map.y >= info->map.height)
		info->map.y = info->map.height - 1;
		info->map.hit = 1;
		if (info->wall.side == 0)
		{
			info->wall.wall_distance = (info->map.x - info->ray.x_ray_position + info->map.xOffset +
			(1 - info->map.x_step) / 2) / info->ray.x_ray_direction;
		}
		else if (info->wall.side == 1)
		{
			info->wall.wall_distance = (info->map.y - info->ray.y_ray_position + info->map.yOffset +
			(1 - info->map.y_step) / 2) / info->ray.y_ray_direction;
		}
	/*	else
		{
			info->wall.floor_distance = (info->map.x - info->ray.x_ray_position +\
			(1 - info->map.x_step) / 2) / info->ray.x_ray_direction;
		}*/
	//sol et plafond
	if (info->min != -1)
	{
		wall_detection_init_x(info);

		wall_detection(info);
	
	
		if (info->floor.side == 0)
		{
			info->wall.floor_distance = (info->map.x - info->ray.x_ray_position +\
			(1 - info->map.x_step) / 2) / info->ray.x_ray_direction;
		}
		else if (info->floor.side == 1)
		{
			info->wall.floor_distance = (info->map.y - info->ray.y_ray_position +\
			(1 - info->map.y_step) / 2) / info->ray.y_ray_direction;
		}
	}

}

int		ray_casting(t_info *info)
{
	info->wall.x = -1;
	while (++info->wall.x < info->win.w)
	{
		info->min = 255;
		ray_casting_init(info, info->wall.x);
			
		info->wall.line_height = (int)(info->win.h / info->wall.wall_distance);
		info->wall.draw_end = info->win.h / 2 + info->wall.line_height / 2 ;
		if (info->wall.draw_end >= info->win.h)\
			info->wall.draw_end = info->win.h - 1;
		info->wall.draw_start = info->win.h / 2 - (info->wall.line_height / 2);
		if (info->wall.draw_start < 0)
			info->wall.draw_start = 0;
		
		texture_calc(info);
		
		//printf("asdfghjkl        %f\n", info->wall.wall_x);
		draw_wall(info->wall.x, info->wall.draw_start - 1,\
				info->wall.draw_end, info);
	}

	/*info->wall.x = -1;
	while (++info->wall.x < info->win.w)
	{
		info->min = -1;
		
		ray_casting_init(info, info->wall.x);
			
		info->wall.line_height = (int)(info->win.h / info->wall.wall_distance);
		info->wall.draw_end = info->win.h / 2 + info->wall.line_height / 2 ;
		if (info->wall.draw_end >= info->win.h)\
			info->wall.draw_end = info->win.h - 1;
		info->wall.draw_start = info->win.h / 2 - (info->wall.line_height / 2);
		if (info->wall.draw_start < 0)
			info->wall.draw_start = 0;
		
		texture_calc(info);
		
		//printf("asdfghjkl        %f\n", info->wall.wall_x);
		
		draw_wall(info->wall.x, info->wall.draw_start - 1,\
				info->wall.draw_end, info);
	}*/
	
	return (0);
}

/*int		threadAnim(void*	data)
{
	t_info *info = data;
	info->win.texture2 = SDL_CreateTextureFromSurface(info->win.renderer, info->head[info->ii].img);
		SDL_QueryTexture(info->win.texture2, NULL, NULL, &info->head[2].w, &info->head[2].h);
		info->head[2].rect.x = info->head[2].w;
		info->head[2].rect.y = 0;
		info->head[2].rect.w = info->head[2].w;
		info->head[2].rect.h = info->head[2].h;
		if (info->ii > 0)
			info->ii--;
		else
			info->ii = 10;
	SDL_Delay(10);
	if (!info->quit)
		threadAnim((t_info*)info);
	return (0);
}
int		threadAnim2(void*	data)
{
	t_info *info = data;
	info->win.texture3 = SDL_CreateTextureFromSurface(info->win.renderer, info->head[info->iii].img);
		SDL_QueryTexture(info->win.texture3, NULL, NULL, &info->head[4].w, &info->head[4].h);
		info->head[4].rect.x = info->head[4].w * 2;
		info->head[4].rect.y = 0;
		info->head[4].rect.w = info->head[4].w;
		info->head[4].rect.h = info->head[4].h;
		if (info->iii > 0)
			info->iii--;
		else
			info->iii = 10;
	SDL_Delay(5000);
	if (!info->quit)
		threadAnim2((t_info*)info);
	return (0);
}*/

void	hud(t_info *info)
{
	

		info->fps.texture2 = SDL_CreateTextureFromSurface(info->win.renderer, info->head[info->i].img);
		SDL_QueryTexture(info->fps.texture2, NULL, NULL, &info->head[3].w, &info->head[3].h);
		info->head[3].rect.x = 0;
		info->head[3].rect.y = 0;
		info->head[3].rect.w = info->head[3].w;
		info->head[3].rect.h = info->head[3].h;
		if (info->i < 10)
			info->i++;
		else
			info->i = 0;
	//mlx_put_image_to_window(info->win.mlx, info->win.win,\
	//	info->head[info->player.life - 1].img, 0, 0);
	//mlx_put_image_to_window(info->win.mlx, info->win.win,\
	//	info->wp[info->w_i].img, info->win.w / 2 - \
	//	info->wp[info->w_i].img->w / 2 - 4 + (rand() % 8),\
	//	info->win.h - info->wp[info->w_i].img->h);
	//mlx_put_image_to_window(info->win.mlx, info->win.win, \
	//info->wp[info->w_i].icon, 5, 315);
	//SDL_UpdateWindowSurface(info->win.win);
	//SDL_Delay(2000);
	//mlx_destroy_image(info->win.mlx, info->fps.img);
}

void	its_a_trap(t_info *info)
{
	if (info->map.map[(int)info->player.x_pos][(int)info->player.y_pos].wall == 5)
	{
		if (info->player.can_trap)
		{
			info->player.can_trap = 0;
			info->player.life -= 1;
			//flash(info);
		}
		/* OOF image */

		//mlx_put_image_to_window(info->win.mlx, info->win.win,\
		//info->wp[10].img, info->win.w / 2 - info->wp[10].img->w\
		//2, info->win.h / 2 - info->wp[10].img->h / 2);
	}
	else
		info->player.can_trap = 1;
}

void	ray_casting_image(t_info *info)
{
	if (!(info->player.life - 1 <= 0))
	{
		create_img(info);
		
		ray_casting(info);
		
		//printf("x=%d y=%d\n\n", info->map.x, info->map.y);
		//fflush(stdout);
		draw_skybox(info);
		
		/* Main frame */

		//mlx_put_image_to_window(info->win.mlx, info->win.win,\
		//info->fps.img, 0, 0);
		if (info->map.map[(int)info->player.x_pos]\
		[(int)info->player.y_pos].wall == 4 && info->action)
		/* Victory image */
		{
			/*info->fps.texture2 = SDL_CreateTextureFromSurface(info->win.renderer, info->head[info->i].img);
			SDL_QueryTexture(info->fps.texture2, NULL, NULL, &info->head[3].w, &info->head[3].h);
			
			info->head[3].rect.x = 0;
			info->head[3].rect.y = 0;
			info->head[3].rect.w = info->head[3].w;
			info->head[3].rect.h = info->head[3].h;*/;
		}
			//mlx_put_image_to_window(info->win.mlx, info->win.win,\
			//info->wp[7].img, info->win.w / 2 - info->wp[7].img->w / 2,\
			//info->win.h / 2 - info->wp[7].img->h / 2);
		its_a_trap(info);
		//hud(info);

	}
	else
		game_over(info);
}

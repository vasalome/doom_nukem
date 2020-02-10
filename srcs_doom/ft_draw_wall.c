/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw_wall.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 20:04:09 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 14:57:14 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void			calc_floor_ceil(t_info *info, int idtext)
{
	info->floor.weight = info->floor.dist / info->wall.floor_distance;
	info->floor.currentFloorX = info->floor.weight * info->floor.floorXWall +
			(1.0 - info->floor.weight) * info->player.x_pos;
	info->floor.currentFloorY = info->floor.weight * info->floor.floorYWall +
			(1.0 - info->floor.weight) * info->player.y_pos;
	info->floor.floorTexX = (int)(info->floor.currentFloorX *
			info->wt[idtext].img->w) % info->wt[idtext].img->w;
	info->floor.floorTexY = (int)(info->floor.currentFloorY *
			info->wt[idtext].img->h) % info->wt[idtext].img->h;
	info->floor.texId = info->map.map[(int)(info->floor.currentFloorX)]
			[(int)(info->floor.currentFloorY)].ceilTexId;
	info->floor.texId2 = info->map.map[(int)(info->floor.currentFloorX)]
			[(int)(info->floor.currentFloorY)].floorTexId;
}

void			draw_floor(t_info *info, int draw_start, int draw_end, int x)
{
	int			y;
	SDL_Color	col;
	Uint32		data;
	int			semi_height;

	semi_height = HEIGHT * 2.5;//(0.5 + (info->testHeight * 0.00111111));
	y = info->player.fov;
	if (info->floor.texId != 0)
		while (++y <= draw_start)
		{
			info->floor.dist = HEIGHT / (((semi_height) - y) * 2);
			calc_floor_ceil(info, info->floor.texId);
			data = get_pixel(info->wt[info->floor.texId].img, info->floor.floorTexX, info->floor.floorTexY);
			SDL_GetRGBA(data, info->wt[info->floor.texId].img->format, &col.r, &col.g, &col.b, &col.a);
			if (info->floor.texId == 18)
				;
			else
				pixel_put(info, x, y, (t_rgb){col.r, col.g, col.b, col.a});
		}
	// else
	// {
	// 	y = draw_end - 1;
	// 	while (++y < HEIGHT)
	// 	{
	// 		info->floor.dist = HEIGHT / (2 * (y - (semi_height)));
	// 		calc_floor_ceil(info, 10);
	// 		data = get_pixel(info->wt[info->floor.texId2].img, info->floor.floorTexX, info->floor.floorTexY);
	// 		SDL_GetRGB(data, info->wt[info->floor.texId2].img->format, &col.r, &col.g, &col.b);
	// 		pixel_put(info, x, y, (t_rgb){col.r, col.g, col.b, 255});
	// 		/*info->fps.data[x * 4 + 4 * WIDTH * y + 1] = (char)120;
	// 		info->fps.data[x * 4 + 4 * WIDTH * y + 2] = (char)120;
	// 		info->fps.data[x * 4 + 4 * WIDTH * y + 3] = (char)0;*/
	// 	}
	// }
}

void			init_and_draw_floor(t_info *info, int draw_s, int draw_e, int x)
{
	if (info->min != -1)
	{
		if (info->floor.side == 0 && info->ray.x_ray_direction > 0)
		{
			info->floor.floorXWall = info->map.x;
			info->floor.floorYWall = info->map.y + info->wall.floor_x;
		}
		else if (info->floor.side == 0 && info->ray.x_ray_direction < 0)
		{
			info->floor.floorXWall = info->map.x + 1;
			info->floor.floorYWall = info->map.y + info->wall.floor_x;
		}
		else if (info->floor.side == 1 && info->ray.y_ray_direction > 0)
		{
			info->floor.floorXWall = info->map.x + info->wall.floor_x;
			info->floor.floorYWall = info->map.y;
		}
		else
		{
			info->floor.floorXWall = info->map.x + info->wall.floor_x;
			info->floor.floorYWall = info->map.y + 1;
		}
		draw_floor(info, draw_s, draw_e, x);
	}
}

void			draw_wall(int x, int draw_start, int draw_end, t_info *info)
{
	int			d;
	int			tex_y;
	Uint32		data;
	SDL_Color	col;
	int			y;

	y = info->player.fov;
	tex_y = 0;
	init_and_draw_floor(info, draw_start, draw_end, x);
	while (++draw_start < draw_end)
	{
		d = draw_start * 256 - (info->win.h + info->testHeight * 2) * 128 +
				info->wall.line_height * 128;
		tex_y = (d * info->wt[info->w_j].img->h / info->wall.line_height) / 256;
		data = get_pixel(info->wt[info->w_j].img, info->wt[info->w_j].tex_x, tex_y);
		SDL_GetRGBA(data, info->wt[info->w_j].img->format, &col.r, &col.g, &col.b, &col.a);
		pixel_put(info, x, draw_start, (t_rgb){col.r, col.g, col.b, col.a});
	}
}

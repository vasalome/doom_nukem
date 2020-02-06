/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wall.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:37:11 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 19:06:20 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	create_img(t_info *info)
{
	info->fps.texture = SDL_CreateTexture(info->win.ren, SDL_PIXELFORMAT_RGBA8888, \
		SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
	info->fps.format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
	SDL_LockTexture(info->fps.texture, NULL, &info->fps.tmp, &info->fps.pitch);
	/*info->fps.img = mlx_new_image(info->win.mlx, WIDTH, HEIGHT);
	info->fps.data = mlx_get_data_addr(info->fps.img, &info->fps.bpp,\
		&info->fps.sizeline, &info->fps.endian);*/
}

void	wall_detection_init_y(t_info *info)
{
	info->ray.y_delta_distance = sqrt(1 + (info->ray.x_ray_direction *\
		info->ray.x_ray_direction) / (info->ray.y_ray_direction *\
		info->ray.y_ray_direction));
	if (info->ray.y_ray_direction < 0)
	{
		info->map.y_step = -1;
		info->ray.y_side_distance = (info->ray.y_ray_position -\
			info->map.y) * info->ray.y_delta_distance;
	}
	else
	{
		info->map.y_step = 1;
		info->ray.y_side_distance = (info->map.y + 1.0 -\
			info->ray.y_ray_position) * info->ray.y_delta_distance;
	}
}

void	wall_detection_init_x(t_info *info)
{
	info->map.hit = 0;
	info->ray.x_delta_distance = sqrt(1 + (info->ray.y_ray_direction *\
		info->ray.y_ray_direction) / (info->ray.x_ray_direction *\
		info->ray.x_ray_direction));
	if (info->ray.x_ray_direction < 0)
	{
		info->map.x_step = -1;
		info->ray.x_side_distance = (info->ray.x_ray_position -\
			info->map.x) * info->ray.x_delta_distance;
	}
	else
	{
		info->map.x_step = 1;
		info->ray.x_side_distance = (info->map.x + 1.0 -\
			info->ray.x_ray_position) * info->ray.x_delta_distance;
	}
	wall_detection_init_y(info);
}

void	wall_detection_plus(t_info *info)
{
	if (info->map.map[info->map.x][info->map.y].wall == 5)
		info->wall.trap = 1;
	else if (info->map.map[info->map.x][info->map.y].wall == 6)
		info->wall.trap = 2;
	else if (info->map.map[info->map.x][info->map.y].wall == 8)
		info->wall.trap = 3;
	else if (info->map.map[info->map.x][info->map.y].wall == 7)
		info->wall.trap = 3;
	else
		info->wall.trap = 0;
}

void	wall_detection(t_info *info)
{
	info->map.hit = 0;
	while (info->map.hit == 0)
	{
		if (info->map.map[info->map.x][info->map.y].wall == 1 ||\
			info->map.x < 0 || info->map.y < 0)
		{
			info->map.hit = 1;
			if (info->map.x < 0)
				info->map.x = 0;
			if (info->map.y < 0)
				info->map.y = 0;
		}
		if (info->ray.x_side_distance < info->ray.y_side_distance)
		{
			info->ray.x_side_distance += info->ray.x_delta_distance;
			info->map.x += info->map.x_step;
			info->floor.side = 0;
		}
		else
		{
			info->ray.y_side_distance += info->ray.y_delta_distance;
			info->map.y += info->map.y_step;
			info->floor.side = 1;
		}
		if (info->map.x < 0)
			info->map.x = 0;

		if (info->map.y < 0)
			info->map.y = 0;

		if (info->map.x >= info->map.width)
			info->map.x = info->map.width - 2;

		if (info->map.y >= info->map.height)
			info->map.y = info->map.height - 2;
	}
}
/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_textures.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 17:20:38 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 10:48:46 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	choose_texture_2(t_info *info)
{
	if (info->wall.trap == 4)
	{
		if (info->wall.side == 0 && info->ray.x_ray_direction > 0)
			info->w_j = 2;
		else if (info->wall.side == 0 && info->ray.x_ray_direction < 0)
			info->w_j = 2;
		else if (info->wall.side == 1 && info->ray.y_ray_direction > 0)
			info->w_j = 2;
		else
			info->w_j = 2;
	}
	if (info->wall.trap == 3)
	{
		if (info->wall.side == 0 && info->ray.x_ray_direction > 0)
			info->w_j = 2;
		else if (info->wall.side == 0 && info->ray.x_ray_direction < 0)
			info->w_j = 2;
		else if (info->wall.side == 1 && info->ray.y_ray_direction > 0)
			info->w_j = 2;
		else
			info->w_j = 2;
	}
}

void	choose_texture_1(t_info *info)
{
	info->w_j = 0;
		if (info->wall.side == 0 && info->ray.x_ray_direction > 0)
		{
			info->w_j = info->map.map[(int)info->map.x][(int)info->map.y].n_tex;
			//printf("n=%d\n", info->map.map[(int)info->map.x][(int)info->map.y].n_tex);
		}
		else if (info->wall.side == 0 && info->ray.x_ray_direction < 0)
		{
			info->w_j = info->map.map[(int)info->map.x][(int)info->map.y].e_tex;
			//printf("e=%d\n", info->map.map[(int)info->map.x][(int)info->map.y].e_tex);
		}
		else if (info->wall.side == 1 && info->ray.y_ray_direction > 0)
		{
			info->w_j = info->map.map[(int)info->map.x][(int)info->map.y].s_tex;
			//printf("s=%d\n", info->map.map[(int)info->map.x][(int)info->map.y].s_tex);
		}
		else
		{
			info->w_j = info->map.map[(int)info->map.x][(int)info->map.y].w_tex;
			//printf("w=%d\n", info->map.map[(int)info->map.x][(int)info->map.y].w_tex);
		}
	if (info->w_j < 0 || info->w_j > 7)
		if (info->w_j < 16 || info->w_j > 18)
			info->w_j = 0;
	info->wall.alpha = info->map.map[(int)info->map.x][(int)info->map.y].wall_h;

	//printf("tex=%d\n", info->w_j);
	//fflush(stdout);
	/*if (info->wall.trap == 1 || info->wall.trap == 2)
	  {
	  if (info->wall.side == 0 && info->ray.x_ray_direction > 0)
	  info->w_j = 18;
	  else if (info->wall.side == 0 && info->ray.x_ray_direction < 0)
	  info->w_j = 2;
	  else if (info->wall.side == 1 && info->ray.y_ray_direction > 0)
	  info->w_j = 2;
	  else
	  info->w_j = 2;
	  }
	  else
	  choose_texture_2(info);*/
}

void	texture_calc(t_info *info)
{
	//printf("QRQRRQRQRQR-----> %f\n", info->wall.wall_x);
	if (info->wall.side == 0)
		info->wall.wall_x = info->ray.y_ray_position + \
							info->wall.wall_distance * info->ray.y_ray_direction;
	else if (info->wall.side == 2 || info->wall.side == 1)
		info->wall.wall_x = info->ray.x_ray_position + \
							info->wall.wall_distance * info->ray.x_ray_direction;
	info->wall.wall_x -= floor((info->wall.wall_x));
	/*	if (info->map.map[info->map.x][info->map.y].wall == 11)
		{
		printf("mapx = %d y = %d\n", info->map.x, info->map.y);
		info->wall.wall_x += info->map.door_offset[info->map.x][info->map.y];
		}*/
	//xTexture sol et plafond
	if (info->floor.side == 0)
		info->wall.floor_x = info->ray.y_ray_position + \
							 info->wall.floor_distance * info->ray.y_ray_direction;
	else if (info->floor.side == 1)
		info->wall.floor_x = info->ray.x_ray_position + \
							 info->wall.floor_distance * info->ray.x_ray_direction;
	info->wall.floor_x -= floor((info->wall.floor_x));

	info->wt[info->w_j].tex_x = (int)(info->wall.wall_x * (float)info->wt[info->w_j].img->w);
	if (info->wall.side == 0 && info->ray.x_ray_direction > 0)
		info->wt[info->w_j].tex_x = info->wt[info->w_j].img->w - \
									info->wt[info->w_j].tex_x - 1;
	if (info->wall.side == 1 && info->ray.y_ray_direction < 0)
		info->wt[info->w_j].tex_x = info->wt[info->w_j].img->w - \
									info->wt[info->w_j].tex_x - 1;
}

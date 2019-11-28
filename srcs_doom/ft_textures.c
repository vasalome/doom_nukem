/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_textures.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:35:35 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 17:29:34 by vasalome    ###    #+. /#+    ###.fr     */
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
	if (info->wall.side == 0 && info->ray.x_ray_direction > 0)
		info->w_j = info->wall.w_choice1;
	else if (info->wall.side == 0 && info->ray.x_ray_direction < 0)
		info->w_j = info->wall.w_choice2;
	else if (info->wall.side == 1 && info->ray.y_ray_direction > 0)
		info->w_j = info->wall.w_choice3;
	else
		info->w_j = info->wall.w_choice4;
	if (info->wall.trap == 1 || info->wall.trap == 2)
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
	else
		choose_texture_2(info);
}

void	texture_calc(t_info *info)
{
	//printf("QRQRRQRQRQR-----> %f\n", info->wall.ux);
	if (info->wall.side == 0)
		info->wall.ux = info->ray.y_ray_position + \
		info->wall.wall_distance * info->ray.y_ray_direction;
	else if (info->wall.side == 2 || info->wall.side == 1)
		info->wall.ux = info->ray.x_ray_position + \
		info->wall.wall_distance * info->ray.x_ray_direction;
	info->wall.ux -= floor((info->wall.ux));

	//xTexture sol et plafond
	if (info->wall.side2 == 0)
		info->wall.ux2 = info->ray.y_ray_position + \
		info->wall.wall_distance2 * info->ray.y_ray_direction;
	else if (info->wall.side2 == 1)
		info->wall.ux2 = info->ray.x_ray_position + \
		info->wall.wall_distance2 * info->ray.x_ray_direction;
	info->wall.ux2 -= floor((info->wall.ux2));
	
	info->wt[info->w_j].tex_x = (int)(info->wall.ux * \
	(double)info->wt[info->w_j].img->w);
	if (info->wall.side == 0 && info->ray.x_ray_direction > 0)
		info->wt[info->w_j].tex_x = info->wt[info->w_j].img->w - \
		info->wt[info->w_j].tex_x - 1;
	if (info->wall.side == 1 && info->ray.y_ray_direction < 0)
		info->wt[info->w_j].tex_x = info->wt[info->w_j].img->w - \
		info->wt[info->w_j].tex_x - 1;
}

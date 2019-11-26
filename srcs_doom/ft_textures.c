/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_textures.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:35:35 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 15:30:48 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

/*void	skybox(t_info *info)
{
	int		offset;

	offset = 640;
	if (info->player.y_dir > 0)
		offset = -offset;
	info->tex.img = mlx_xpm_file_to_image(info->win.mlx, "img/square.xpm",\
		&info->tex.xhud, &info->tex.yhud);
	mlx_put_image_to_window(info->win.mlx, info->win.win,\
		info->tex.img, offset * info->player.x_dir, -150);
	mlx_put_image_to_window(info->win.mlx, info->win.win,\
		info->tex.img, offset * info->player.x_dir - info->tex.xhud, -150);
	mlx_put_image_to_window(info->win.mlx, info->win.win,\
		info->tex.img, offset * info->player.x_dir + info->tex.xhud, -150);
	mlx_put_image_to_window(info->win.mlx, info->win.win,\
		info->tex.img, offset * info->player.x_dir + \
		(info->tex.xhud * 2), -150);
	mlx_put_image_to_window(info->win.mlx, info->win.win,\
		info->tex.img, offset * info->player.x_dir - \
		(info->tex.xhud * 2), -150);
	mlx_put_image_to_window(info->win.mlx, info->win.win,\
		info->tex.img, offset * info->player.x_dir + \
		(info->tex.xhud * 3), -150);
	mlx_put_image_to_window(info->win.mlx, info->win.win,\
		info->tex.img, offset * info->player.x_dir - \
		(info->tex.xhud * 3), -150);
}*/

void	choose_texture_2(t_info *info)
{
	if (info->wall.trap == 4)
	{
		if (info->wall.side == 0 && info->ray.x_ray_direction > 0)
			info->w_j = 12;
		else if (info->wall.side == 0 && info->ray.x_ray_direction < 0)
			info->w_j = 13;
		else if (info->wall.side == 1 && info->ray.y_ray_direction > 0)
			info->w_j = 14;
		else
			info->w_j = 15;
	}
	if (info->wall.trap == 3)
	{
		if (info->wall.side == 0 && info->ray.x_ray_direction > 0)
			info->w_j = 0;
		else if (info->wall.side == 0 && info->ray.x_ray_direction < 0)
			info->w_j = 1;
		else if (info->wall.side == 1 && info->ray.y_ray_direction > 0)
			info->w_j = 2;
		else
			info->w_j = 3;
	}
}

void	choose_texture_1(t_info *info)
{
	if (info->wall.side == 0 && info->ray.x_ray_direction > 0)
		info->w_j = 8;
	else if (info->wall.side == 0 && info->ray.x_ray_direction < 0)
		info->w_j = 9;
	else if (info->wall.side == 1 && info->ray.y_ray_direction > 0)
		info->w_j = 10;
	else
		info->w_j = 11;
	if (info->wall.trap == 1 || info->wall.trap == 2)
	{
		if (info->wall.side == 0 && info->ray.x_ray_direction > 0)
			info->w_j = 4;
		else if (info->wall.side == 0 && info->ray.x_ray_direction < 0)
			info->w_j = 5;
		else if (info->wall.side == 1 && info->ray.y_ray_direction > 0)
			info->w_j = 6;
		else
			info->w_j = 7;
	}
	else
		choose_texture_2(info);
}

void	texture_calc(t_info *info)
{
	printf("QRQRRQRQRQR-----> %f\n", info->wall.ux);
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

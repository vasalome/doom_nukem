/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_textures.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:35:35 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 17:27:49 by vasalome    ###    #+. /#+    ###.fr     */
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
	if (info->wall.side == 0)
		info->wall.ux = info->player.y_pos + \
		info->wall.wall_distance * info->ray.y_ray_direction;
	else
		info->wall.ux = info->player.x_pos + \
		info->wall.wall_distance * info->ray.x_ray_direction;
	info->wall.ux -= floor((info->wall.ux));
	info->wt[info->w_j].tex_x = (int)(info->wall.ux * \
	(double)info->wt[info->w_j].xhud);
	if (info->wall.side == 0 && info->ray.x_ray_direction > 0)
		info->wt[info->w_j].tex_x = info->wt[info->w_j].xhud - \
		info->wt[info->w_j].tex_x - 1;
	if (info->wall.side == 1 && info->ray.y_ray_direction < 0)
		info->wt[info->w_j].tex_x = info->wt[info->w_j].xhud - \
		info->wt[info->w_j].tex_x - 1;
}

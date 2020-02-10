/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ray.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 17:20:23 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 16:25:56 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include_doom/doom.h"

void	dda(t_info *info)
{
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
}

void		which_wall_form(t_info *info)
{
	int		rayTex;

	rayTex = info->map.map[info->map.x][info->map.y].wall;
	if (rayTex == 11 && info->map.door_state[info->map.x][info->map.y] != 2)
	{
		info->map.hit = 1;
		if (info->wall.side == 1)
		{
			info->map.yOffset = 0.5 * info->map.y_step;
			info->wall.wall_distance = info->map.y - info->ray.y_ray_position + info->map.yOffset + (1 - info->map.y_step) / 2 / info->ray.y_ray_direction;
			info->wall.wall_x = info->ray.x_ray_position + info->wall.wall_distance * info->ray.x_ray_direction; // Pour gerer l'ouverture des portes differement c'est ici
			info->wall.wall_x -= floor(info->wall.wall_x);
			if (info->ray.y_side_distance - (info->ray.y_delta_distance / 2) < info->ray.x_side_distance)
			{
				if (1 - info->wall.wall_x <= info->map.door_offset[info->map.x][info->map.y])
				{
					info->map.hit = 0;
					info->map.yOffset = 0;
				}
				info->w_j = 6;
			}
			else // Si superieur alors on fait passer le rayon derriere la porte
			{
				info->map.x += info->map.x_step;
				info->wall.side = 0;
				rayTex = 1; //door frame = côté des portes // autre texture
				info->w_j = 1;
				info->map.yOffset = 0;
			}
		}
		else
		{
			info->map.xOffset = 0.5 * info->map.x_step;
		//	info->wall.wall_distance = fabs((info->map.x - info->ray.x_ray_position+ .5)  / fabs(info->ray.x_ray_direction)); Jean-Michel A peu pres (ouverture inversee dans un cas)
			info->wall.wall_distance = (info->map.x - info->ray.x_ray_position + info->map.xOffset)  / 2 / info->ray.x_ray_direction;
			info->wall.wall_x = info->ray.y_ray_position + info->wall.wall_distance * info->ray.y_ray_direction;
			info->wall.wall_x -= floor(info->wall.wall_x);
			if (info->ray.x_side_distance - (info->ray.x_delta_distance / 2) < info->ray.y_side_distance)
			{
				if (info->wall.wall_x < info->map.door_offset[info->map.x][info->map.y]) // piti soucy ici
				{
					info->map.hit = 0;
					info->map.xOffset = 0;
				}
				info->w_j = 6;
			}
			else
			{
				info->map.y +=  info->map.y_step;
				info->wall.side = 1;
				rayTex = 1;
				info->w_j = 1;
				info->map.xOffset = 0;
			}
		}
	}
	else if (rayTex == 7)
		make_flat_wall_7(info);
	else if (rayTex == 8)
		make_flat_wall_8(info);
	else if (rayTex == 9)
		make_pillar(info);
	else if (rayTex == 10)
	{
		if (info->wall.side == 0)
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
	else if (rayTex == 12)
	{
		if (info->wall.side == 1)
		{
			if (info->map.y_step == -1)
				if (info->ray.y_side_distance - (info->ray.y_delta_distance / 2) < info->ray.x_side_distance)
				{
					info->map.hit = 1;
					info->map.yOffset = 0.5 + info->map.y_step;
				}
		}
	}
	else if (rayTex == 1)
		info->map.hit = 1;
}

void		error_handling(t_info *info)
{
	if (info->map.hit == 0)
		info->wall.alpha = 0;
	if (info->map.x < 0)
		info->map.x = 0;
	if (info->map.x >= info->map.width)
		info->map.x = info->map.width - 1;
	if (info->map.y < 0)
		info->map.y = 0;
	if (info->map.y >= info->map.height)
	{
		info->map.y = info->map.height - 1;
		info->map.hit = 1;
	}
}

void		coordinates(t_info *info)
{
	if (info->wall.side == 0)
		info->wall.wall_distance = (info->map.x - info->ray.x_ray_position +
				info->map.xOffset + (1 - info->map.x_step) / 2) /
				info->ray.x_ray_direction;
	else if (info->wall.side == 1)
		info->wall.wall_distance = (info->map.y - info->ray.y_ray_position +
				info->map.yOffset + (1 - info->map.y_step) / 2) /
				info->ray.y_ray_direction;
}

void		floor_and_ceil_init(t_info *info)
{
	if (info->min != -1)
	{
		wall_detection_init_x(info);
		wall_detection(info);
		if (info->floor.side == 0)
			info->wall.floor_distance = (info->map.x - info->ray.x_ray_position
					+ (1 - info->map.x_step) / 2) / info->ray.x_ray_direction;
		else if (info->floor.side == 1)
			info->wall.floor_distance = (info->map.y - info->ray.y_ray_position
					+ (1 - info->map.y_step) / 2) / info->ray.y_ray_direction;
	}
}

void		ray_casting_init(t_info *info, int x)
{
	info->player.x_camera = 2 * x / (float)(info->win.w) - 1;
	info->ray.x_ray_position = info->player.x_pos;
	info->ray.y_ray_position = info->player.y_pos;
	info->ray.x_ray_direction = info->player.x_dir + info->player.x_plane *
			info->player.x_camera;
	info->ray.y_ray_direction = info->player.y_dir + info->player.y_plane * 
			info->player.x_camera;
	info->map.x = (int)info->player.x_pos;
	info->map.y = (int)info->player.y_pos;
	info->wall.alpha = 0;
	wall_detection_init_x(info);
	while (info->map.hit == 0 && info->map.x >= 0 &&
			info->map.x < info->map.width && info->map.y >= 0 &&
			info->map.y < info->map.height)
	{
		info->map.hit = 0;
		info->map.yOffset = 0;
		info->map.xOffset = 0;
		dda(info);
		which_wall_form(info);
		choose_texture_1(info);
	}
	error_handling(info);
	coordinates(info);
	floor_and_ceil_init(info);
}

int		ray_casting(t_info *info)
{
	info->wall.x = -1;
	while (++info->wall.x < info->win.w)
	{
		info->min = 255;
		ray_casting_init(info, info->wall.x);
		info->wall.line_height = (int)( info->win.h / info->wall.wall_distance);
		info->wall.draw_end = (info->win.h / 2 + info->testHeight + info->wall.line_height / 2);
		if (info->wall.draw_end >= info->win.h) info->wall.draw_end = info->win.h - 1;
			info->wall.draw_start = (info->win.h / 2 + info->testHeight - (info->wall.line_height / 2));
		if (info->wall.draw_start < 0)
			info->wall.draw_start = 0;
		texture_calc(info);
		draw_wall(info->wall.x, info->wall.draw_start - 1, info->wall.draw_end, info);
	}
	return (0);
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
	}
	else
		info->player.can_trap = 1;
}

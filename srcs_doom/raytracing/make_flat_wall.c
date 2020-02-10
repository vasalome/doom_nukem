/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_flat_wall.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 16:17:51 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 16:25:59 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include_doom/doom.h"

void	intersectLine(t_inter *inter)
{
	float	A1 = inter->p1y - inter->p0y;
	float	B1 = inter->p0x - inter->p1x;
	float	C1 = A1 * inter->p0x + B1 * inter->p0y;
	float	A2 = inter->p3y - inter->p2y;
	float	B2 = inter->p2x - inter->p3x;
	float	C2 = A2 * inter->p2x + B2 * inter->p2y;
	float	denominator = A1 * B2 - A2 * B1;

	inter->x = (B2 * C1 - B1 * C2) / denominator;
	inter->y = (A1 * C2 - A2 * C1) / denominator;
}

void		make_flat_wall_8(t_info *info)
{
    float	wallX1;
	float	wallY1;
	float	wallX2;
	float	wallY2;
	t_inter	inter;

    wallX1 = info->map.x;
    wallY1 = info->map.y;
    wallX2 = info->map.x + 1;
    wallY2 = info->map.y + 1;
	inter.p0x = info->ray.x_ray_position;
	inter.p0y = info->ray.y_ray_position;
	inter.p1x = info->ray.x_ray_position + info->ray.x_ray_direction;
	inter.p1y = info->ray.y_ray_position + info->ray.y_ray_direction;
	inter.p2x = wallX1;
	inter.p2y = wallY1;
	inter.p3x = wallX2;
	inter.p3y = wallY2;
	intersectLine(&inter);
	if(inter.x >= info->map.x && inter.x <= info->map.x + 1 && inter.y >=
			info->map.y && inter.y <= info->map.y + 1)
	{
		info->map.hit = 1;
		info->wall.side = 2;
		info->wall.wall_distance = ((inter.x - info->ray.x_ray_position +
				inter.y - info->ray.y_ray_position) / 2) /
				((info->ray.x_ray_direction + info->ray.y_ray_direction) / 2);
	}
}

void        make_flat_wall_7(t_info *info)
{
    float   wallX1;
	float   wallY1;
	float   wallX2;
	float   wallY2;
	t_inter inter;

    wallX1 = info->map.x;
    wallY1 = info->map.y + 1;
    wallX2 = info->map.x + 1;
    wallY2 = info->map.y;
	inter.p0x = info->ray.x_ray_position;
	inter.p0y = info->ray.y_ray_position;
	inter.p1x = info->ray.x_ray_position + info->ray.x_ray_direction;
	inter.p1y = info->ray.y_ray_position + info->ray.y_ray_direction;
	inter.p2x = wallX1;
	inter.p2y = wallY1;
	inter.p3x = wallX2;
	inter.p3y = wallY2;
	intersectLine(&inter);
	if(inter.x >= info->map.x && inter.x <= info->map.x + 1 && inter.y >=
            info->map.y && inter.y <= info->map.y + 1)
	{
		info->map.hit = 1;
		info->wall.side = 2;
		info->wall.wall_distance = ((inter.x - info->ray.x_ray_position +
                inter.y - info->ray.y_ray_position) / 2) /
                ((info->ray.x_ray_direction + info->ray.y_ray_direction) / 2);
	}
}

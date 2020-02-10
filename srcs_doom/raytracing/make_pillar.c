/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_pillar.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 15:35:35 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 15:56:15 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include_doom/doom.h"

int			ray_pillar(t_inter *inter, t_pillar p)
{
	float	a, b, c;
	float	bb4ac;
	float	dp1;
	float	dp2;

	dp1 = 0;
	dp2 = 0;
	dp1 = p.p2x - p.p1x;
	dp2 = p.p2y - p.p1y;
	a = dp1 * dp1 + dp2 * dp2;
	b = 2 * (dp1 * (p.p1x - p.scx) + dp2 * (p.p1y - p.scy));
	c = p.scx * p.scx + p.scy * p.scy;
	c += p.p1x * p.p1x + p.p1y * p.p1y;
	c -= 2 * (p.scx * p.p1x + p.scy * p.p1y);
	c -= p.rayon * p.rayon;
	bb4ac = b * b - 4 * a * c;
	if (bb4ac < 0)
		return(0);
	inter->x = (-b + sqrt(bb4ac)) / (2 * a);
	inter->y = (-b - sqrt(bb4ac)) / (2 * a);
	return(1);
}

void		make_pillar(t_info *info)
{
	int		intersectDist;
	t_inter inter;

	intersectDist = ray_pillar(&inter,
			(t_pillar){info->player.x_pos, info->player.y_pos,
			info->player.x_pos + info->ray.x_ray_direction,
			info->player.y_pos + info->ray.y_ray_direction,
			info->map.x + 0.5,
			info->map.y + 0.5,
			0.5});
	if (intersectDist != 0)
	{
		info->map.hit = 1;
	 	info->wall.side = 3;
		t_inter interse;
		interse.x = info->player.x_pos + info->ray.x_ray_direction * inter.y;
		interse.y = info->player.y_pos + info->ray.y_ray_direction * inter.y;
		info->wall.wall_distance = ((interse.x - info->player.x_pos + interse.y
				- info->player.y_pos) / 2) / ((info->ray.x_ray_direction +
				info->ray.y_ray_direction) / 2);
		info->wall.wall_x = atan2(info->map.y + 0.5 - interse.y, info->map.x +
				0.5 - interse.x) / (M_PI * 2);
	 	info->wall.wall_x += info->wall.wall_x;
	}
}

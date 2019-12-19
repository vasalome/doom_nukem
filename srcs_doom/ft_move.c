/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:33:41 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 00:03:50 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

/*
** Movements
*/

void	turn_left(t_info *info)
{
	if (info->player.turn_left == 1)
	{
		info->fps.rect.y += 500 * info->player.turn_rate_y;
		//printf("Y = %d\n motion = %d\n", info->fps.rect.y, event.motion.yrel);
		if (info->fps.rect.y > 0)
			info->fps.rect.y = 0;
		if (info->fps.rect.y < -400)
			info->fps.rect.y = -400;
		info->player.turn_left = 0;	
	}
}

void	turn_right(t_info *info)
{
	if (info->player.turn_right == 1)
	{
		info->player.x_old_direction = info->player.x_dir;
		info->player.x_dir = info->player.x_dir *\
			cos(-info->player.turn_rate) - info->player.y_dir *\
			sin(-info->player.turn_rate);
		info->player.y_dir = info->player.x_old_direction *\
			sin(-info->player.turn_rate) + info->player.y_dir *\
			cos(-info->player.turn_rate);
		info->player.x_old_plane = info->player.x_plane;
		info->player.x_plane = info->player.x_plane *\
			cos(-info->player.turn_rate) - info->player.y_plane *\
			sin(-info->player.turn_rate);
		info->player.y_plane = info->player.x_old_plane *\
			sin(-info->player.turn_rate) + info->player.y_plane *\
			cos(-info->player.turn_rate);
		info->player.turn_right = 0;
	}
	turn_left(info);
}

void	move_plus_4(t_info *info)
{
	if (info->map.map[(int)(info->player.x_pos + info->player.y_dir
		* info->player.move_speed)][(int)(info->player.y_pos)].wall != 1\
		&& info->map.map[(int)(info->player.x_pos + info->player.y_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall != 7\
		&& info->map.map[(int)(info->player.x_pos + info->player.y_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall != 8\
		&& info->map.map[(int)(info->player.x_pos + info->player.y_dir
		* info->player.move_speed)][(int)(info->player.y_pos)].wall != 9
		&& info->map.map[(int)(info->player.x_pos + info->player.y_dir
		* info->player.move_speed)][(int)(info->player.y_pos)].clip != 0)
		info->player.x_pos += info->player.y_dir * info->player.move_speed;

	if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.x_dir * info->player.move_speed)].wall != 1\
		&& info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.x_dir * info->player.move_speed)].wall != 7\
		&& info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.x_dir * info->player.move_speed)].wall != 8\
		&& info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.x_dir * info->player.move_speed)].wall != 9
		&& info->map.map[(int)(info->player.x_pos + info->player.y_dir
		* info->player.move_speed)][(int)(info->player.y_pos)].clip != 0)
		info->player.y_pos -= info->player.x_dir * info->player.move_speed;

	if (info->map.map[(int)(info->player.x_pos - info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].gg == 1)
		teleport_2(info);
}

void	move_plus_3(t_info *info)
{
	if (info->map.map[(int)(info->player.x_pos - info->player.y_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall != 1\
		&& info->map.map[(int)(info->player.x_pos - info->player.y_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall != 7\
		&& info->map.map[(int)(info->player.x_pos - info->player.y_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall != 8\
		&& info->map.map[(int)(info->player.x_pos - info->player.y_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall != 9
		&& info->map.map[(int)(info->player.x_pos + info->player.y_dir
		* info->player.move_speed)][(int)(info->player.y_pos)].clip != 0)
		info->player.x_pos -= info->player.y_dir * info->player.move_speed;

	if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.x_dir * info->player.move_speed)].wall != 1\
		&& info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.x_dir * info->player.move_speed)].wall != 7\
		&& info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.x_dir * info->player.move_speed)].wall != 8
		&& info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.x_dir * info->player.move_speed)].wall != 9
		&& info->map.map[(int)(info->player.x_pos + info->player.y_dir
		* info->player.move_speed)][(int)(info->player.y_pos)].clip != 0)
			info->player.y_pos += info->player.x_dir * info->player.move_speed;

	if (info->map.map[(int)(info->player.x_pos + info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].gg == 1)
		teleport(info);
}

void	move_plus_2(t_info *info)
{
	if (info->map.map[(int)(info->player.x_pos - info->player.x_dir
		* info->player.move_speed)][(int)(info->player.y_pos)].wall != 1\
		&& info->map.map[(int)(info->player.x_pos - info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall != 7\
		&& info->map.map[(int)(info->player.x_pos - info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall != 8\
		&& info->map.map[(int)(info->player.x_pos - info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall != 9
		&& info->map.map[(int)(info->player.x_pos + info->player.y_dir
		* info->player.move_speed)][(int)(info->player.y_pos)].clip != 0)
		info->player.x_pos -= info->player.x_dir * info->player.move_speed;

	if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.y_dir * info->player.move_speed)].wall != 1\
		&& info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.y_dir * info->player.move_speed)].wall != 7\
		&& info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.y_dir * info->player.move_speed)].wall != 8\
		&& info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.y_dir * info->player.move_speed)].wall != 9
		&& info->map.map[(int)(info->player.x_pos + info->player.y_dir
		* info->player.move_speed)][(int)(info->player.y_pos)].clip != 0)
		info->player.y_pos -= info->player.y_dir * info->player.move_speed;

	if (info->map.map[(int)(info->player.x_pos - info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].gg == 1)
		teleport_2(info);
}

void	move_plus_1(t_info *info)
{
	if (info->map.map[(int)(info->player.x_pos + info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall != 1\
		&& info->map.map[(int)(info->player.x_pos + info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall != 7\
		&& info->map.map[(int)(info->player.x_pos + info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall != 8\
		&& info->map.map[(int)(info->player.x_pos + info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall != 9/*\
		&& (info->player.x_pos + info->player.x_dir * info->player.move_speed) >= 0\
		/*&& (info->player.y_pos + info->player.y_dir * info->player.move_speed) < info->map.height*/
		&& info->map.map[(int)(info->player.x_pos + info->player.y_dir
		* info->player.move_speed)][(int)(info->player.y_pos)].clip != 0)
		info->player.x_pos += info->player.x_dir * info->player.move_speed;

	if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.y_dir * info->player.move_speed)].wall != 1\
		&& info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.y_dir * info->player.move_speed)].wall != 7\
		&& info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.y_dir * info->player.move_speed)].wall != 8\
		&& info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.y_dir * info->player.move_speed)].wall != 9/*\
		&& (info->player.y_pos + info->player.y_dir * info->player.move_speed) >= 0\
		/*&& (info->player.y_pos + info->player.y_dir * info->player.move_speed) < info->map.height*/
		&& info->map.map[(int)(info->player.x_pos + info->player.y_dir
		* info->player.move_speed)][(int)(info->player.y_pos)].clip != 0)
		info->player.y_pos += info->player.y_dir * info->player.move_speed;

	if (info->map.map[(int)(info->player.x_pos + info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].gg == 1)
		teleport(info);
}

int		move(t_info *info)
{
	if (info->player.move_up == 1)
		move_plus_1(info);
	if (info->player.move_down == 1)
		move_plus_2(info);
	if (info->player.move_left == 1)
		move_plus_3(info);
	if (info->player.move_right == 1)
		move_plus_4(info);
	turn_right(info);

	// printf("x = %f\nY = %f\n\n", info->player.x_pos, info->player.y_pos);
	// if ((info->player.move_up || info->player.move_down ||
	// 			info->player.turn_right || info->player.turn_left) == 1)
	// 	ray_casting_image(info);
	return (0);
}

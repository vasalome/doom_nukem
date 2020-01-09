/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:33:41 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 23:17:21 by vasalome    ###    #+. /#+    ###.fr     */
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
		// printf("Y = %d\n motion = %d\n", info->fps.rect.y, event.motion.yrel);
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
		* info->player.move_speed)][(int)(info->player.y_pos)].clip == 1)
		info->player.x_pos += info->player.y_dir * info->player.move_speed;
	else if (info->map.map[(int)(info->player.x_pos + info->player.y_dir
		* info->player.move_speed)][(int)(info->player.y_pos)].clip == 0)
	{
		// printf("\nclip = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].clip);
		// printf("wall = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].wall);
		// printf("x_pos = %f\n",info->player.x_pos);
		// printf("y_pos = %f\n",info->player.y_pos);
		// printf("x_dir = %f\n",info->player.x_dir);
		// printf("y_dir = %f\n",info->player.y_dir);
		
		if (info->map.map[(int)(info->player.x_pos + info->player.y_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall == 7)
		{
			info->player.x_pos += info->player.y_dir * info->player.move_speed;
			
		}
		else if (info->map.map[(int)(info->player.x_pos + info->player.y_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall == 8)
		{

		}
		else if (info->map.map[(int)(info->player.x_pos + info->player.y_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall == 9)
		{

		}
		else if (info->map.map[(int)(info->player.x_pos + info->player.y_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall == 10)
		{
			info->player.x_pos += info->player.y_dir * info->player.move_speed;
		}
	}

	if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.x_dir * info->player.move_speed)].clip == 1)
		info->player.y_pos -= info->player.x_dir * info->player.move_speed;
	else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.x_dir * info->player.move_speed)].clip == 0)
	{
		if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.x_dir * info->player.move_speed)].wall == 7)
		{
			info->player.y_pos -= info->player.x_dir * info->player.move_speed;
		}
		else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.x_dir * info->player.move_speed)].wall == 8)
		{

		}
		else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.x_dir * info->player.move_speed)].wall == 9)
		{

		}
		else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.x_dir * info->player.move_speed)].wall == 10)
		{
			info->player.y_pos -= info->player.x_dir * info->player.move_speed;
		}
	}

	if (info->map.map[(int)(info->player.x_pos - info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].tp == 1)
		teleport_2(info);
}

void	move_plus_3(t_info *info)
{
	if (info->map.map[(int)(info->player.x_pos - info->player.y_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].clip == 1)
		info->player.x_pos -= info->player.y_dir * info->player.move_speed;
	else if (info->map.map[(int)(info->player.x_pos - info->player.y_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].clip == 0)
	{
		// printf("\nclip = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].clip);
		// printf("wall = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].wall);
		// printf("x_pos = %f\n",info->player.x_pos);
		// printf("y_pos = %f\n",info->player.y_pos);
		// printf("x_dir = %f\n",info->player.x_dir);
		// printf("y_dir = %f\n",info->player.y_dir);

		if (info->map.map[(int)(info->player.x_pos - info->player.y_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall == 7)
		{
			info->player.x_pos -= info->player.y_dir * info->player.move_speed;
			
		}
		else if (info->map.map[(int)(info->player.x_pos - info->player.y_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall == 8)
		{

		}
		else if (info->map.map[(int)(info->player.x_pos - info->player.y_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall == 9)
		{

		}
		else if (info->map.map[(int)(info->player.x_pos - info->player.y_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall == 10)
		{
			info->player.x_pos -= info->player.y_dir * info->player.move_speed;
		}
	}

	if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.x_dir * info->player.move_speed)].clip == 1)
		info->player.y_pos += info->player.x_dir * info->player.move_speed;
	else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.x_dir * info->player.move_speed)].clip == 0)
	{
		if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.x_dir * info->player.move_speed)].wall == 7)
		{
			info->player.y_pos += info->player.x_dir * info->player.move_speed;
		}
		else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.x_dir * info->player.move_speed)].wall == 8)
		{

		}
		else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.x_dir * info->player.move_speed)].wall == 9)
		{

		}
		else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.x_dir * info->player.move_speed)].wall == 10)
		{
			info->player.y_pos += info->player.x_dir * info->player.move_speed;
		}
	}

	if (info->map.map[(int)(info->player.x_pos + info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].tp == 1)
		teleport(info);
}

void	move_plus_2(t_info *info)
{
	if (info->map.map[(int)(info->player.x_pos - info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].clip == 1)
		info->player.x_pos -= info->player.x_dir * info->player.move_speed;
	else if (info->map.map[(int)(info->player.x_pos - info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].clip == 0)
	{
		// printf("\nclip = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].clip);
		// printf("wall = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].wall);
		// printf("x_pos = %f\n",info->player.x_pos);
		// printf("y_pos = %f\n",info->player.y_pos);
		// printf("x_dir = %f\n",info->player.x_dir);
		// printf("y_dir = %f\n",info->player.y_dir);

		if (info->map.map[(int)(info->player.x_pos - info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall == 7)
		{
			info->player.x_pos -= info->player.x_dir * info->player.move_speed;
			

		}
		else if (info->map.map[(int)(info->player.x_pos - info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall == 8)
		{

		}
		else if (info->map.map[(int)(info->player.x_pos - info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall == 9)
		{

		}
		else if (info->map.map[(int)(info->player.x_pos - info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall == 10)
		{
			info->player.x_pos -= info->player.x_dir * info->player.move_speed;
		}
	}

	if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.y_dir * info->player.move_speed)].clip == 1)
		info->player.y_pos -= info->player.y_dir * info->player.move_speed;
	else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.y_dir * info->player.move_speed)].clip == 0)
	{
		if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.y_dir * info->player.move_speed)].wall == 7)
		{
			info->player.y_pos -= info->player.y_dir * info->player.move_speed;
		}
		else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.y_dir * info->player.move_speed)].wall == 8)
		{

		}
		else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.y_dir * info->player.move_speed)].wall == 9)
		{

		}
		else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.y_dir * info->player.move_speed)].wall == 10)
		{
			info->player.y_pos -= info->player.y_dir * info->player.move_speed;
		}
	}

	if (info->map.map[(int)(info->player.x_pos - info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].tp == 1)
		teleport_2(info);
}

void	move_plus_1(t_info *info)
{
	if (info->map.map[(int)(info->player.x_pos + info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].clip == 1
		/*&& (info->player.x_pos + info->player.x_dir * info->player.move_speed) >= 0\
		&& (info->player.y_pos + info->player.y_dir * info->player.move_speed) < info->map.height*/)
			info->player.x_pos += info->player.x_dir * info->player.move_speed;
	else if (info->map.map[(int)(info->player.x_pos + info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].clip == 0)
	{
		// printf("\nclip = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].clip);
		// printf("wall = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].wall);
		// printf("x_pos = %f\n",info->player.x_pos);
		// printf("y_pos = %f\n",info->player.y_pos);
		// printf("x_dir = %f\n",info->player.x_dir);
		// printf("y_dir = %f\n",info->player.y_dir);
		
		if (info->map.map[(int)(info->player.x_pos + info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall == 7)
		{
			// printf("\nclip = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].clip);
			// printf("wall = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].wall);
			// printf("x_pos = %f\n",info->player.x_pos);
			// printf("y_pos = %f\n",info->player.y_pos);
			// printf("x_dir = %f\n",info->player.x_dir);
			// printf("y_dir = %f\n",info->player.y_dir);

			// printf("\n==> x_pos = %f\n",info->player.x_pos);
			// printf("==> y_pos = %f\n",info->player.y_pos);
			info->player.x_lim = floor(info->player.x_pos) + 0.5;
			// printf("//////////////droit x_pos CALC = %f\n",info->player.x_lim);
			info->player.y_lim = floor(info->player.y_pos) + 0.5;
			// printf("//////////////droit y_pos CALC = %f\n",info->player.y_lim);

			if (info->player.x_dir < 0 && info->player.y_dir > 0)
				while (info->player.x_pos >= 6.5)
					info->player.x_pos += info->player.x_dir * info->player.move_speed;
			else if (info->player.x_dir > 0 && info->player.y_dir < 0)
				while (info->player.x_pos <= 6.5)
					info->player.x_pos += info->player.x_dir * info->player.move_speed;

			// hypotenuse_2 = cote1_2 + cote2_2
		}
		else if (info->map.map[(int)(info->player.x_pos + info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall == 8)
		{
			
		}
		else if (info->map.map[(int)(info->player.x_pos + info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall == 9)
		{
			
		}
		else if (info->map.map[(int)(info->player.x_pos + info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall == 10)
		{
			// printf("\nclip = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].clip);
			// printf("wall = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].wall);
			// printf("x_pos = %f\n",info->player.x_pos);
			// printf("y_pos = %f\n",info->player.y_pos);
			// printf("x_dir = %f\n",info->player.x_dir);
			// printf("y_dir = %f\n",info->player.y_dir);

			// printf("\n==> x_pos = %f\n",info->player.x_pos);
			// printf("==> y_pos = %f\n",info->player.y_pos);
			info->player.x_lim = floor(info->player.x_pos) + 0.5;
			// printf("////////////// x_pos CALC = %f\n",info->player.x_lim);
			
			if (1)
			{
				if (info->player.x_dir < 0 && info->player.y_dir > 0)
					while (info->player.x_pos >= 6.5)
						info->player.x_pos += info->player.x_dir * info->player.move_speed;
				else if (info->player.x_dir > 0 && info->player.y_dir < 0)
					while (info->player.x_pos <= 6.5)
						info->player.x_pos += info->player.x_dir * info->player.move_speed;
			/*}
			else if ()
			{*/
				if (info->player.x_dir < 0 && info->player.y_dir > 0)
					while (info->player.y_pos >= 8.5)
						info->player.y_pos += info->player.y_dir * info->player.move_speed;
				else if (info->player.x_dir > 0 && info->player.y_dir < 0)
					while (info->player.y_pos <= 8.5)
						info->player.y_pos += info->player.y_dir * info->player.move_speed;
			}
		}
	}
	if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.y_dir * info->player.move_speed)].clip == 1
		/*&& (info->player.y_pos + info->player.y_dir * info->player.move_speed) >= 0\
		&& (info->player.y_pos + info->player.y_dir * info->player.move_speed) < info->map.height*/)
			info->player.y_pos += info->player.y_dir * info->player.move_speed;
	else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.y_dir * info->player.move_speed)].clip == 0)
	{
		if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.y_dir * info->player.move_speed)].wall == 7)
		{
			// printf("\nclip = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].clip);
			// printf("wall = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].wall);
			// printf("x_pos = %f\n",info->player.x_pos);
			// printf("y_pos = %f\n",info->player.y_pos);
			// printf("x_dir = %f\n",info->player.x_dir);
			// printf("y_dir = %f\n",info->player.y_dir);

			// printf("\n==> x_pos = %f\n",info->player.x_pos);
			// printf("==> y_pos = %f\n",info->player.y_pos);
			info->player.x_lim = floor(info->player.x_pos) + 0.5;
			// printf("//////////////droit2 x_pos CALC = %f\n",info->player.x_lim);
			
			if (info->player.x_dir < 0 && info->player.y_dir > 0)
				while (info->player.x_pos >= 6.5)
					info->player.x_pos += info->player.x_dir * info->player.move_speed;
			else if (info->player.x_dir > 0 && info->player.y_dir < 0)
				while (info->player.x_pos <= 6.5)
					info->player.x_pos += info->player.x_dir * info->player.move_speed;
		}
		else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.y_dir * info->player.move_speed)].wall == 8)
		{
			
		}
		else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.y_dir * info->player.move_speed)].wall == 9)
		{
			
		}
		else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.y_dir * info->player.move_speed)].wall == 10)
		{
			// printf("\nclip = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].clip);
			// printf("wall = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].wall);
			// printf("x_pos = %f\n",info->player.x_pos);
			// printf("y_pos = %f\n",info->player.y_pos);
			// printf("x_dir = %f\n",info->player.x_dir);
			// printf("y_dir = %f\n",info->player.y_dir);
			
			// printf("\n==> x_pos = %f\n",info->player.x_pos);
			// printf("==> y_pos = %f\n",info->player.y_pos);
			info->player.x_lim = floor(info->player.x_pos) + 0.5;
			// printf("////////////// x_pos CALC = %f\n",info->player.x_lim);
			
			if (1)
			{
				if (info->player.x_dir < 0 && info->player.y_dir > 0)
					while (info->player.x_pos >= 6.5)
						info->player.x_pos += info->player.x_dir * info->player.move_speed;
				else if (info->player.x_dir > 0 && info->player.y_dir < 0)
					while (info->player.x_pos <= 6.5)
						info->player.x_pos += info->player.x_dir * info->player.move_speed;
			/*}
			else if ()
			{*/
				if (info->player.x_dir < 0 && info->player.y_dir > 0)
					while (info->player.y_pos >= 8.5)
						info->player.y_pos += info->player.y_dir * info->player.move_speed;
				else if (info->player.x_dir > 0 && info->player.y_dir < 0)
					while (info->player.y_pos <= 8.5)
						info->player.y_pos += info->player.y_dir * info->player.move_speed;
			}
		}
	}
	if (info->map.map[(int)(info->player.x_pos + info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].tp == 1)
		teleport(info);
}

int		move(t_info *info)
{
	// printf("move -- x_dir = %f\n",info->player.x_dir);
	// printf("move -- y_dir = %f\n",info->player.y_dir);
	if (info->player.move_up == 1)
		move_plus_1(info);
	if (info->player.move_down == 1)
		move_plus_2(info);
	if (info->player.move_left == 1)
		move_plus_3(info);
	if (info->player.move_right == 1)
		move_plus_4(info);
	turn_right(info);

	// printf("x = %d\nY = %d\n\n", info->player.x_pos, info->player.y_pos);
	// if ((info->player.move_up || info->player.move_down ||
	// 			info->player.turn_right || info->player.turn_left) == 1)
	// 	ray_casting_image(info);
	return (0);
}

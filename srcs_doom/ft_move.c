/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:33:41 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 18:19:56 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

/*
** Movements
*/

void	move_doors(t_info *info)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < info->map.width)
	{
		while (y < info->map.height)
		{
			if (info->map.map[x][y].wall == 11)
			{
				if (info->map.door_state[x][y] == 1) // Si ma porte est en train de s'ouvrir
				{
					info->map.door_offset[x][y] += info->delta_time / 100;
					if (info->map.door_offset[x][y] > 1)
					{
						info->map.door_offset[x][y] = 1;
						info->map.door_state[x][y] = 2; // ma porte est ouverte
					}
				}
				else if (info->map.door_state[x][y] == 3) // en train de se fermer
				{
					info->map.door_offset[x][y] -= info->delta_time / 100;
					if (info->map.door_offset[x][y] < 0)
					{
						info->map.door_offset[x][y] = 0;
						info->map.door_state[x][y] = 0;
					}
				}
			}
			y++;
		}
		y = 0;
		x++;
	}
}

void	open_doors(t_info *info)
{
	int		check_x;
	int		check_y;
	int		check_x2;
	int		check_y2;

	check_x = floor(info->player.x_pos + info->player.x_dir);
	check_y = floor(info->player.y_pos + info->player.y_dir);
	check_x2 = floor(info->player.x_pos + info->player.x_dir * 2);
	check_y2 = floor(info->player.y_pos + info->player.y_dir * 2); // peut etre pas besoin de ca comme pas de push wall
	if (info->map.map[check_x][check_y].wall == 11 && info->map.door_state[check_x][check_y] == 0)
		info->map.door_state[check_x][check_y] = 1;
//	if (info->map.map[check_x2][check_y2].wall == 11 && info->map.door_state[check_x2][check_y2] == 0)
//		info->map.door_state[check_x2][check_y2] = 1;
	if (info->map.map[check_x][check_y].wall == 11 && info->map.door_state[check_x][check_y] == 2)
		info->map.door_state[check_x][check_y] = 3;
	if (info->map.door_state[(int)info->player.x_pos][(int)info->player.y_pos] == 3) // en train de se fermer
		info->map.door_state[(int)info->player.x_pos][(int)info->player.y_pos] = 1;
}

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
		* info->player.move_speed)][(int)(info->player.y_pos)].clip == 1)
		info->player.x_pos += info->player.y_dir * info->player.move_speed;
	else if (info->map.map[(int)(info->player.x_pos + info->player.y_dir
		* info->player.move_speed)][(int)(info->player.y_pos)].clip == 0)
	{
		printf("\nclip = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].clip);
		printf("wall = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].wall);
		printf("x_pos = %f\n",info->player.x_pos);
		printf("y_pos = %f\n",info->player.y_pos);
		printf("x_dir = %f\n",info->player.x_dir);
		printf("y_dir = %f\n",info->player.y_dir);
		
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
		printf("\nclip = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].clip);
		printf("wall = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].wall);
		printf("x_pos = %f\n",info->player.x_pos);
		printf("y_pos = %f\n",info->player.y_pos);
		printf("x_dir = %f\n",info->player.x_dir);
		printf("y_dir = %f\n",info->player.y_dir);

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
		printf("\nclip = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].clip);
		printf("wall = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].wall);
		printf("x_pos = %f\n",info->player.x_pos);
		printf("y_pos = %f\n",info->player.y_pos);
		printf("x_dir = %f\n",info->player.x_dir);
		printf("y_dir = %f\n",info->player.y_dir);

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
		printf("\nclip = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].clip);
		printf("wall = %d\n",info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].wall);
		printf("x_pos = %f\n",info->player.x_pos);
		printf("y_pos = %f\n",info->player.y_pos);
		printf("x_dir = %f\n",info->player.x_dir);
		printf("y_dir = %f\n",info->player.y_dir);
		
		if (info->map.map[(int)(info->player.x_pos + info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall == 7)
		{
			printf("\n==> x_pos = %f\n",info->player.x_pos);
			printf("==> y_pos = %f\n",info->player.y_pos);
			while (info->player.x_pos > 6.5)
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
			printf("\n==> x_pos = %f\n",info->player.x_pos);
			printf("==> y_pos = %f\n",info->player.y_pos);
			while (info->player.x_pos > 6.5)
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
			
		}
	}
	if (info->map.map[(int)(info->player.x_pos + info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].tp == 1)
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

	// printf("x = %d\nY = %d\n\n", info->player.x_pos, info->player.y_pos);
	// if ((info->player.move_up || info->player.move_down ||
	// 			info->player.turn_right || info->player.turn_left) == 1)
	// 	ray_casting_image(info);
	return (0);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_event.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 16:46:18 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 16:57:00 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include_doom/doom.h"

// void	press_weapon_2(t_info *info)
// {
// 	info->wp[0].img = IMG_Load("weapon/pistol/pistol_1.png");
// 	info->wp[1].img = IMG_Load("weapon/pistol/pistol_1.png");
// 	info->wp[2].img = IMG_Load("weapon/pistol/pistol_1.png");
// 	info->wp[3].img = IMG_Load("weapon/pistol/pistol_1.png");
// 	info->wp[4].img = IMG_Load("weapon/pistol/pistol_1.png");
// 	info->wp[5].img = IMG_Load("weapon/pistol/pistol_1.png");
// 	info->wp[6].img = IMG_Load("weapon/pistol/pistol_1.png");
// 	info->wp[8].img = IMG_Load("weapon/pistol/pistol_1.png");
// 	info->wp[9].img = IMG_Load("weapon/pistol/pistol_1.png");
// 	info->shot += 1;
// }

// void	press_weapon(t_info *info)
// {
// 	if (info->shot == 1)
// 	{
// 		info->wp[0].img = IMG_Load("weapon/pistol/pistol_2_shot.png");
// 		info->wp[1].img = IMG_Load("weapon/pistol/pistol_2_shot.png");
// 		info->wp[2].img = IMG_Load("weapon/pistol/pistol_2_shot.png");
// 		info->wp[3].img = IMG_Load("weapon/pistol/pistol_2_shot.png");
// 		info->wp[4].img = IMG_Load("weapon/pistol/pistol_2_shot.png");
// 		info->wp[5].img = IMG_Load("weapon/pistol/pistol_2_shot.png");
// 		info->wp[6].img = IMG_Load("weapon/pistol/pistol_2_shot.png");
// 		info->wp[8].img = IMG_Load("weapon/pistol/pistol_2_shot.png");
// 		info->wp[9].img = IMG_Load("weapon/pistol/pistol_2_shot.png");
// 		info->shot -= 1;
// 	}
// 	else if (info->shot == 0)
// 		press_weapon_2(info);
// }

// int		key_press(int keycode, t_info *info)
// {
// 	if (keycode == KEY_W || keycode == KEY_UP)
// 		info->player.move_up = 1;
// 	else if (keycode == KEY_S || keycode == KEY_DOWN)
// 		info->player.move_down = 1;
// 	else if (keycode == KEY_D || keycode == KEY_RIGHT)
// 		info->player.turn_right = 1;
// 	else if (keycode == KEY_A || keycode == KEY_LEFT)
// 		info->player.turn_left = 1;
// 	else if (keycode == KEY_SHIFT_L || keycode == KEY_SHIFT_R)
// 		info->player.move_speed = 0.2;
// 	else if (keycode == KEY_SPACE)
// 	{
// 		press_weapon(info);
// 		//ray_casting_image(info);
// 	}
// 	else if (keycode == KEY_ESC)
// 	{
// 		exit(1);
// 		SDL_DestroyWindow(info->win.win);
// 	}
// 	return (0);
// }

// void	reset_weapon(t_info *info)
// {
// 	info->shot = 1;
// 	info->wp[0].img = IMG_Load("weapon/pistol/pistol_1.png");
// 	info->wp[1].img = IMG_Load("weapon/pistol/pistol_1.png");
// 	info->wp[2].img = IMG_Load("weapon/pistol/pistol_1.png");
// 	info->wp[3].img = IMG_Load("weapon/pistol/pistol_1.png");
// 	info->wp[4].img = IMG_Load("weapon/pistol/pistol_1.png");
// 	info->wp[5].img = IMG_Load("weapon/pistol/pistol_1.png");
// 	info->wp[6].img = IMG_Load("weapon/pistol/pistol_1.png");
// 	info->wp[8].img = IMG_Load("weapon/pistol/pistol_1.png");
// 	info->wp[9].img = IMG_Load("weapon/pistol/pistol_1.png");
// }

// int		key_release(int key, t_info *info)
// {
// 	else if (key == KEY_SPACE)
// 	{
// 		reset_weapon(info);
// 		//ray_casting_image(info);
// 	}
// 	else if (key == KEY_1_NUM || key == KEY_2_NUM || key == KEY_3_NUM ||\
// 		key == KEY_4_NUM || key == KEY_5_NUM || key == KEY_6_NUM ||\
// 		key == KEY_7_NUM || key == KEY_8_NUM || key == KEY_9_NUM)
// 	{
// 		info->w_i = key - KEY_1_NUM;
// 		//ray_casting_image(info);
// 	}
// 	return (0);
// }

/*
** Movements
*/

void	move_plus_4(t_info *info)
{
	if (info->map.map[(int)(info->player.x_pos + info->player.y_dir
		* info->player.move_speed)][(int)(info->player.y_pos)].clip == 1)
		info->player.x_pos += info->player.y_dir * info->player.move_speed;
	else if (info->map.map[(int)(info->player.x_pos + info->player.y_dir
		* info->player.move_speed)][(int)(info->player.y_pos)].clip == 0)
	{
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
		else if (info->map.map[(int)(info->player.x_pos + info->player.y_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall == 12)
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
		else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.x_dir * info->player.move_speed)].wall == 12)
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
		else if (info->map.map[(int)(info->player.x_pos - info->player.y_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall == 12)
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
		else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		+ info->player.x_dir * info->player.move_speed)].wall == 12)
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
		else if (info->map.map[(int)(info->player.x_pos - info->player.x_dir\
		* info->player.move_speed)][(int)(info->player.y_pos)].wall == 12)
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
		else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos\
		- info->player.y_dir * info->player.move_speed)].wall == 12)
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
	if (info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].clip == 1)
		/*&& (info->player.x_pos + info->player.x_dir * info->player.move_speed) >= 0\
		&& (info->player.y_pos + info->player.y_dir * info->player.move_speed) < info->map.height)*/
			info->player.x_pos += info->player.x_dir * info->player.move_speed;
	else if (info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].clip == 0)
	{	
		if (info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].wall == 7)
		{
			// hypotenuse_2 = cote1_2 + cote2_2
		}
		else if (info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].wall == 8)
		{
			
		}
		else if (info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].wall == 9)
		{
			
		}
		else if (info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].wall == 10)
			clip_10(info);
		else if (info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].wall == 12)
			clip_12(info);
	}
	if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos + info->player.y_dir * info->player.move_speed)].clip == 1)
		/*&& (info->player.y_pos + info->player.y_dir * info->player.move_speed) >= 0\
		&& (info->player.y_pos + info->player.y_dir * info->player.move_speed) < info->map.height)*/
		info->player.y_pos += info->player.y_dir * info->player.move_speed;
	else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos + info->player.y_dir * info->player.move_speed)].clip == 0)
	{
		if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos + info->player.y_dir * info->player.move_speed)].wall == 7)
		{

		}
		else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos + info->player.y_dir * info->player.move_speed)].wall == 8)
		{
			
		}
		else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos + info->player.y_dir * info->player.move_speed)].wall == 9)
		{
			
		}
		else if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos + info->player.y_dir * info->player.move_speed)].wall == 10)
		{
			clip_10(info);
		}
		else if (info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].wall == 12)
		{
			clip_12(info);
		}
	}
	if (info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].tp == 1)
		teleport(info);
}

void		keys_mouvements(t_info *info, const Uint8 *keyboard_state)
{
	if (keyboard_state[SDL_SCANCODE_W] || keyboard_state[SDL_SCANCODE_UP])
	{
		move_plus_1(info);
		//if (info->map.map[(int)(info->player.x_pos + info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].clip == 1)
		//	info->player.x_pos += info->player.x_dir * info->player.move_speed;
		//if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos + info->player.y_dir * info->player.move_speed)].clip == 1)
		//	info->player.y_pos += info->player.y_dir * info->player.move_speed;
	}
	if (keyboard_state[SDL_SCANCODE_S] || keyboard_state[SDL_SCANCODE_DOWN])
	{
		move_plus_2(info);
		//if (info->map.map[(int)(info->player.x_pos - info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].clip == 1)
		//	info->player.x_pos -= info->player.x_dir * info->player.move_speed;
		//if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos - info->player.y_dir * info->player.move_speed)].clip == 1)
		//	info->player.y_pos -= info->player.y_dir * info->player.move_speed;
	}
	if (keyboard_state[SDL_SCANCODE_D] || keyboard_state[SDL_SCANCODE_RIGHT])
	{
		move_plus_4(info);
		//if (info->map.map[(int)(info->player.x_pos + info->player.y_dir * info->player.move_speed)][(int)(info->player.y_pos)].clip == 1)
		//	info->player.x_pos += info->player.y_dir * info->player.move_speed;
		//if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos - info->player.x_dir * info->player.move_speed)].clip == 1)
		//	info->player.y_pos -= info->player.x_dir * info->player.move_speed;
	}
	if (keyboard_state[SDL_SCANCODE_A] || keyboard_state[SDL_SCANCODE_LEFT])
	{
		move_plus_3(info);
		//if (info->map.map[(int)(info->player.x_pos - info->player.y_dir * info->player.move_speed)][(int)(info->player.y_pos)].clip == 1)
		//	info->player.x_pos -= info->player.y_dir * info->player.move_speed;
		//if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos + info->player.x_dir * info->player.move_speed)].clip == 1)
		//	info->player.y_pos += info->player.x_dir * info->player.move_speed;
	}
}

void			key(t_info *info, const Uint8 *keyboard_state)
{
	if (keyboard_state[SDL_SCANCODE_ESCAPE])
		info->quit = 1;
	if (keyboard_state[SDL_SCANCODE_B])
		info->player.height += 0.1;
	if (keyboard_state[SDL_SCANCODE_N])
		info->player.height -= 0.1;
	if (keyboard_state[SDL_SCANCODE_LSHIFT])
		info->player.move_speed = 0.1;
	if (keyboard_state[SDL_SCANCODE_F])
		info->action = 1;
	if (keyboard_state[SDL_SCANCODE_E])
		open_doors(info);
	if (keyboard_state[SDL_SCANCODE_R])
		reload(info);
	if (keyboard_state[SDL_SCANCODE_H])
		info->testHeight -= 10;
	if (keyboard_state[SDL_SCANCODE_1])
		info->item.weapon = 1;
	if (keyboard_state[SDL_SCANCODE_2])
		change_item(info);
	if (keyboard_state[SDL_SCANCODE_V])
		info->item.kick = 1;
	else
		info->item.kick = 0;
}

// void			key_up(t_info *info, const Uint8 *keyboard_state)
// {
// 	printf("la\n");
// 	if (!keyboard_state[SDL_SCANCODE_LSHIFT])
// 		info->player.move_speed = 0.05;
// 	if (!keyboard_state[SDL_SCANCODE_F])
// 		info->action = 0;
// 	if (!keyboard_state[SDL_SCANCODE_C])
// 	{
// 		//if (info.testHeight < 0)
// 		//{
// 			info->testHeight = 0;
// 		//}
// 	}
// 	if (!keyboard_state[SDL_SCANCODE_SPACE])
// 	{
// 	    //if (info->testHeight < 0)
// 	    //{
// 	    	//while (info->testHeight != -300)
// 	    	//{
// 				info->testHeight = 300;
// 	    	//}
// 	    //}
// 	}
// 	if (!keyboard_state[SDL_SCANCODE_V])
// 	{
// 		info->item.kick = 0;
// 		printf("are u there\n");
// 	}
// }

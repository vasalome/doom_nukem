/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_event.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/03 18:39:09 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 13:12:00 by nrivoire    ###    #+. /#+    ###.fr     */
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
// 	if (key == KEY_W || key == KEY_UP)
// 		info->player.move_up = 0;
// 	else if (key == KEY_S || key == KEY_DOWN)
// 		info->player.move_down = 0;
// 	else if (key == KEY_D || key == KEY_RIGHT)
// 		info->player.turn_right = 0;
// 	else if (key == KEY_A || key == KEY_LEFT)
// 		info->player.turn_left = 0;
// 	else if (key == KEY_SHIFT_L || key == KEY_SHIFT_R)
// 		info->player.move_speed = 0.05;
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

static void		mouvement_on(t_info *info, const Uint8 *keyboard_state)
{
	if (keyboard_state[SDL_SCANCODE_W] || keyboard_state[SDL_SCANCODE_UP])
	{
	    info->player.move_up = 1;
	    //info->player.head = 1;
		printf("up\n");
	}
	if (keyboard_state[SDL_SCANCODE_S] || keyboard_state[SDL_SCANCODE_DOWN])
	{
	    info->player.move_down = 1;
	    //info->player.head = 1;
		printf("down\n");
	}
	if (keyboard_state[SDL_SCANCODE_D] || keyboard_state[SDL_SCANCODE_RIGHT])
	{
	    info->player.move_right = 1;
	    //info->player.head = 0;
		printf("right\n");
	}
	if (keyboard_state[SDL_SCANCODE_A] || keyboard_state[SDL_SCANCODE_LEFT])
	{
	    info->player.move_left = 1;
	    //info->player.head = 2;
		printf("left\n");
	}
}

void			key_down(t_info *info, const Uint8 *keyboard_state)
{
	mouvement_on(info, keyboard_state);
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
	if (keyboard_state[SDL_SCANCODE_C])
	{
	    //if (info->testHeight > -300)
	    //{
		
	        //while (info->testHeight != -300)
	        //{
				info->testHeight = -250;
				ray_casting_image(info);
	        //}
	    //}
	}
	if (keyboard_state[SDL_SCANCODE_SPACE])
	{
	    //if (info->testHeight < 0)
	    //{
		
	        //while (info->testHeight != -300)
	        //{
				info->testHeight = 300;
				ray_casting_image(info);
	        //}
	    //}
	}
	if (keyboard_state[SDL_SCANCODE_H])
		info->testHeight -= 10;
}

static void		mouvement_off(t_info *info, const Uint8 *keyboard_state)
{
	if (keyboard_state[SDL_SCANCODE_W] || keyboard_state[SDL_SCANCODE_UP])
	    info->player.move_up = 0;
	if (keyboard_state[SDL_SCANCODE_S] || keyboard_state[SDL_SCANCODE_DOWN])
	    info->player.move_down = 0;
	if (keyboard_state[SDL_SCANCODE_D] || keyboard_state[SDL_SCANCODE_RIGHT])
	    info->player.move_right = 0;
	if (keyboard_state[SDL_SCANCODE_A] || keyboard_state[SDL_SCANCODE_LEFT])
	    info->player.move_left = 0;
}

void			key_up(t_info *info, const Uint8 *keyboard_state)
{
	mouvement_off(info, keyboard_state);
	if (keyboard_state[SDL_SCANCODE_LSHIFT])
		info->player.move_speed = 0.05;
	if (keyboard_state[SDL_SCANCODE_F])
		info->action = 0;
	if (keyboard_state[SDL_SCANCODE_C])
	{
		//if (info.testHeight < 0)
		//{
			info->testHeight = 0;
			ray_casting_image(info);
		//}
	}
	if (keyboard_state[SDL_SCANCODE_SPACE])
	{
	    //if (info->testHeight < 0)
	    //{
	    	//while (info->testHeight != -300)
	    	//{
				info->testHeight = 300;
				ray_casting_image(info);
	    	//}
	    //}
	}
}

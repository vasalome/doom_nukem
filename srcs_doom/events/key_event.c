/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_event.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/03 18:39:09 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 19:20:35 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include_doom/doom.h"

static void		mouvement_on(t_info *info, const Uint8 *keyboard_state)
{
	if (keyboard_state[SDL_SCANCODE_W] || keyboard_state[SDL_SCANCODE_UP])
	{
	    info->player.move_up = 1;
	    //info->player.head = 1;
	}
	if (keyboard_state[SDL_SCANCODE_S] || keyboard_state[SDL_SCANCODE_DOWN])
	{
	    info->player.move_down = 1;
	    //info->player.head = 1;
	}
	if (keyboard_state[SDL_SCANCODE_D] || keyboard_state[SDL_SCANCODE_RIGHT])
	{
	    info->player.move_right = 1;
	    //info->player.head = 0;
	}
	if (keyboard_state[SDL_SCANCODE_A] || keyboard_state[SDL_SCANCODE_LEFT])
	{
	    info->player.move_left = 1;
	    //info->player.head = 2;
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
		open_doors(&info);
	if (keyboard_state[SDL_SCANCODE_R])
		reload(&info);
	if (keyboard_state[SDL_SCANCODE_C])
	{
	    //if (info->testHeight > -300)
	    //{
		
	        //while (info->testHeight != -300)
	        //{
				info->testHeight = -250;
				ray_casting_image(&info);
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
				ray_casting_image(&info);
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
			ray_casting_image(&info);
		//}
	}
	if (keyboard_state[SDL_SCANCODE_SPACE])
	{
	    //if (info->testHeight < 0)
	    //{
	    	//while (info->testHeight != -300)
	    	//{
				info->testHeight = 300;
				ray_casting_image(&info);
	    	//}
	    //}
	}
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_doom.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/04 12:31:45 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 15:17:23 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include_doom/doom.h"

void                which_window_to_display(t_info *info)
{
	if (info->game == 2)
	{
		
	}
	else if (info->game == 3)
	{

	}
	else
	{
		
	}
}

void				display_doom(t_info *info)
{
	const Uint8*	keyboard_state;
	SDL_Event		event;

	while (!info->quit)
	{
	    while (SDL_PollEvent(&event))
		{
			keyboard_state = SDL_GetKeyboardState(NULL);
			if (event.type == SDL_KEYDOWN)
				key_down(info, keyboard_state);
			if (event.type == SDL_KEYUP)
				key_up(info, keyboard_state);
			if (event.type == SDL_MOUSEBUTTONDOWN) 
				mouse_button_down(info, event);
			if (event.type == SDL_MOUSEBUTTONUP)
				mouse_button_up(info, event);
			if (event.type == SDL_MOUSEMOTION)
				mouse_motion_event(info, event);
            if (event.type == SDL_MOUSEWHEEL)
                mouse_wheel_event(info, event);
		}
		if (event.type == SDL_QUIT)
			info->quit = 1;
        which_window_to_display(info);
		SDL_UpdateTexture(info->textu, NULL, info->pixels, sizeof(uint32_t) * WIDTH);
		SDL_RenderCopy(info->win.ren, info->textu, NULL, NULL);
		SDL_RenderPresent(info->win.ren);
	}
	SDL_DestroyRenderer(info->win.ren);
	SDL_DestroyWindow(info->win.win);
	SDL_Quit();
}

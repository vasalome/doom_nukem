/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_doom.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 20:03:26 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 15:06:46 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include_doom/doom.h"

void				clear_pixels(t_info *info)
{
	int				i;
	int				j;

	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
			info->pixels[j * WIDTH + i] = 0;
	}
}

void                which_window_to_display(t_info *info, SDL_Event event, const Uint8*	keyboard_state)
{
	int				i;

	i = -1;
	if (info->game == 1)
	{
		keys_mouvements(info, keyboard_state);
		SDL_ShowCursor(SDL_DISABLE);
		clear_pixels(info);
		//draw_skybox(info);
		ray_casting(info);
		omg_he_got_a_gun(info);
		render_hud(info, &event);
	}
	else if (info->game == 3)
	{

	}
}

void			menu_button(t_info *info, int i)
{
	t_start		start;
	t_size		size;

	start.x = WIDTH - (WIDTH / 5 + WIDTH / 8);
	start.y = HEIGHT - (HEIGHT - (HEIGHT / 4 * i + HEIGHT / 32));
	size.x = info->menu[1]->w / 1.5;
	size.y = info->menu[1]->h / 5;
	put_texture(info, start, size, info->menu[1]);
}

void				menu(t_info *info)
{
	int				i;

	i = 0;
	put_texture(info, (t_start){0, 0}, (t_size){WIDTH, HEIGHT}, info->menu[0]);
	put_texture(info, (t_start){WIDTH - (WIDTH / 5 + WIDTH / 8),
								HEIGHT - (HEIGHT - (HEIGHT / 16))},
					(t_size){info->menu[2]->w / 1.5, info->menu[2]->h / 2},
					info->menu[2]);
	while (++i < 4)
		menu_button(info, i);
}

void				display_doom(t_info *info)
{
	const Uint8*	keyboard_state;
	SDL_Event		event;
	uint32_t		fps;

	menu(info);
	while (!info->quit)
	{
		fps = SDL_GetTicks();
		keyboard_state = SDL_GetKeyboardState(NULL);
	    while (SDL_PollEvent(&event))
		{
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
        which_window_to_display(info, event, keyboard_state);
		SDL_UpdateTexture(info->textu, NULL, info->pixels, sizeof(uint32_t) * WIDTH);
		SDL_RenderCopy(info->win.ren, info->textu, NULL, NULL);
		SDL_RenderPresent(info->win.ren);
		info->fps_now += (SDL_GetTicks() - fps);
        if (info->fps_now >= 1000)
        {
            info->fps_now = 0;
            printf("%u\n", 1000 / (SDL_GetTicks() - fps));
        }
	}
	SDL_DestroyRenderer(info->win.ren);
	SDL_DestroyWindow(info->win.win);
	TTF_Quit();
	SDL_Quit();
}

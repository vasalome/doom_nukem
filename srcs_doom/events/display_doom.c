/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_doom.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/04 12:31:45 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 17:56:40 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include_doom/doom.h"

// if (info.game == 2)
// {
//     SDL_SetTextureBlendMode(info.fps.texture, SDL_BLENDMODE_BLEND);
//     SDL_UnlockTexture(info.fps.texture);

//     SDL_RenderClear(info.win.ren);
//     render_skybox(&info);
//     SDL_RenderCopy(info.win.ren, info.fps.texture, NULL, &info.fps.rect);
//     // RENDER HUD
//     //SDL_RenderCopy(info.win.ren, info.hud[0].texture, NULL, &info.hud[0].rect);
// 	info.sur_hud[0] = IMG_Load("hud/head/1/fst_r.png");
// 	render_hud(&info, &event);
// }

void                which_window_to_display(t_info *info)
{
	int				i;

	i = -1;
	if (info->game == 2)
	{
		// render_skybox(info);
		// put_texture(info, )
	}
	else if (info->game == 3)
	{

	}
	else
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
	while (++i <= 4)
		menu_button(info, i);
}

void				display_doom(t_info *info)
{
	const Uint8*	keyboard_state;
	SDL_Event		event;

	menu(info);
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

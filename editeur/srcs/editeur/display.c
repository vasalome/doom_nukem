/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 15:57:04 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 15:22:49 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

int				get_hex_rgba(int r, int g, int b, int a)
{
	return ((r << 24) | (g << 16) | (b << 8) | (a));
}

void			pixel_put(t_env *v, int x, int y, t_rgb color)
{
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	v->pixels[y * WIDTH + x] = get_hex_rgba(color.r, color.g, color.b, color.a);
}

void			draw_pro_frame(t_env *v, SDL_Event event)
{
	make_grid_pattern(v, event);
	draw_in_grid_pattern(v);
	menu_squares_size(v);
	menu_form_part(v);
}

void			display(t_env *v)
{
	SDL_Event	event;
	const Uint8	*keyboard_state;

	while (1)
	{
		while (SDL_PollEvent(&event))
		{
			keyboard_state = SDL_GetKeyboardState(NULL);
			if (event.type == SDL_KEYDOWN)
				key_event(keyboard_state);
			if (event.type == SDL_MOUSEBUTTONDOWN ||
					event.type == SDL_MOUSEBUTTONUP)
				mouse_button_event(event, v);
			if (event.type == SDL_MOUSEMOTION)
				mouse_motion_event(event, v);
		}
		if (event.type == SDL_QUIT || key_event(keyboard_state))
			break ;
		draw_pro_frame(v, event);
		SDL_UpdateTexture(v->tex, NULL, v->pixels, sizeof(uint32_t) * WIDTH);
		SDL_RenderCopy(v->ren, v->tex, NULL, NULL);
		SDL_RenderPresent(v->ren);
	}
	SDL_DestroyRenderer(v->ren);
	SDL_DestroyWindow(v->win);
	SDL_Quit();
}

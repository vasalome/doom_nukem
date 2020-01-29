/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 15:57:04 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 18:45:40 by nrivoire    ###    #+. /#+    ###.fr     */
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
	if (x >= v->w || y >= v->h || x < 0 || y < 0)
		return ;
	v->pixels[y * v->w + x] = get_hex_rgba(color.r, color.g, color.b, color.a);
}

void			draw_pro_frame(t_env *v, SDL_Event event)
{
	if (v->window == 1)
	{
		v->chosen_tex.est = 0;
		v->chosen_tex.sud = 0;
		v->chosen_tex.est = 0;
		v->chosen_tex.ouest = 0;
		v->chosen_tex.flat_wall = 0;
		v->chosen_tex.pillar = 0;
		open_window(v);
	}
	else
	{
		make_grid_pattern(v, event);
		draw_in_grid_pattern(v);
	}
	menu_button(v);
}

void			display(t_env *v)
{
	SDL_Event	e;
	const Uint8	*keyboard_state;

	menu_text(v);
	while (1)
	{
		while (SDL_PollEvent(&e))
		{
			keyboard_state = SDL_GetKeyboardState(NULL);
			if (e.type == SDL_KEYDOWN)
				key_event(keyboard_state);
			if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
				mouse_button_event(e, v);
			if (e.type == SDL_MOUSEMOTION)
				mouse_motion_event(e, v);
		}
		if (e.type == SDL_QUIT || key_event(keyboard_state))
			break ;
		draw_pro_frame(v, e);
		SDL_UpdateTexture(v->tex, NULL, v->pixels, sizeof(uint32_t) * v->w);
		SDL_RenderCopy(v->ren, v->tex, NULL, NULL);
		SDL_RenderPresent(v->ren);
	}
	SDL_DestroyRenderer(v->ren);
	SDL_DestroyWindow(v->win);
	SDL_Quit();
}

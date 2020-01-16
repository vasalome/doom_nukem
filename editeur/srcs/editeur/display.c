/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 15:57:04 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 14:50:06 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/editeur.h"

void			pixel_put(t_env *v, int x, int y, t_rgb color)
{
	SDL_RenderDrawPoint(v->ren, x, y);
	SDL_SetRenderDrawColor(v->ren, color.r, color.g, color.b, color.a);
}

void			make_quadrillage(t_env *v, SDL_Event event)
{
	int			i;
	int			j;
	int			k;
	int			l;

	j = -1;
	while (++j < HEIGHT / CASES)
	{
		i = -1;
		while (++i < (WIDTH - 30 * 7) / CASES)
		{
			k = -1;
			while (++k <= CASES)
			{
				if (i < (WIDTH - 30 * 7) / CASES)
					pixel_put(v, i * CASES + k, j * CASES, make_rgb(63, 62, 65, 200));
				if (j < HEIGHT / CASES)
					pixel_put(v, i * CASES, j * CASES + k, make_rgb(63, 62, 65, 200));
			}
			if (event.motion.x > 0 && event.motion.x < WIDTH - 30 * 7 && event.motion.y > 0 && event.motion.y < HEIGHT)
			{
				k = 0;
				while (++k < CASES && !(l = 0))
					while (++l < CASES)
						pixel_put(v, i * CASES + k, j * CASES + l, make_rgb(event.motion.x / CASES == i && event.motion.y / CASES == j ? 0 : 191, event.motion.x / CASES == i && event.motion.y / CASES == j ? 179 : 190, event.motion.x / CASES == i && event.motion.y / CASES == j ? 0 : 193, 255));
			}
		}
	}
}

void			make_menu(t_env *v)
{
	TTF_Font	*police;
	SDL_Color	fond = {204, 203, 205, 255};
	SDL_Color	police_color = {0, 0, 0, 255};
	SDL_Surface	*sur;

	if (TTF_Init() == -1)
		ft_error("Initialisation error of TFT_Init");
	police = NULL;
	police = TTF_OpenFont("/srcs/editeur/h.ttf", 20);
	if (!police)
		ft_error("Police error");
	sur = TTF_RenderText_Shaded(police, "Formes", police_color, fond);
	v->text = SDL_CreateTextureFromSurface(v->ren, sur);
	SDL_FreeSurface(sur);
	TTF_CloseFont(police);
	TTF_Quit();
}

void			draw_pro_frame(t_env *v, SDL_Event event)
{
	make_menu(v);
	make_quadrillage(v, event);
}

void			display(t_env *v)
{
	SDL_Event	event;
	const Uint8	*keyboard_state;
	SDL_Rect position;
	position.x = WIDTH - 30 * 6;
	position.y = 30;

	while (1)
	{
		while (SDL_PollEvent(&event))
		{
			keyboard_state = SDL_GetKeyboardState(NULL);
			if (event.type == SDL_KEYDOWN)
				key_event(keyboard_state, v);
			if (event.type == SDL_MOUSEBUTTONDOWN)
				mouse_button_event(event, v);
			if (event.type == SDL_MOUSEMOTION)
				mouse_motion_event(event, v);
		}
		if (event.type == SDL_QUIT || key_event(keyboard_state, v))
			break ;
		draw_pro_frame(v, event);
		SDL_RenderCopy(v->ren, v->back, NULL, NULL);
		SDL_QueryTexture(v->text, NULL, NULL, &position.w, &position.h);
		SDL_RenderCopy(v->ren, v->text, NULL, &position);
		SDL_RenderPresent(v->ren);
	}
	SDL_DestroyRenderer(v->ren);
	SDL_DestroyWindow(v->win);
	SDL_Quit();
}

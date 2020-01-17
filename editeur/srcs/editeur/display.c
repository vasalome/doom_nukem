/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 15:57:04 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 17:40:54 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/editeur.h"

void			pixel_put(t_env *v, int x, int y, t_rgb color)
{
	SDL_RenderDrawPoint(v->ren, x, y);
	SDL_SetRenderDrawColor(v->ren, color.r, color.g, color.b, color.a);
}

void			make_form_cube(t_env *v, int start_x, int start_y, int square)
{
	drawline(make_point(start_x, start_y), make_point(start_x + square, start_y), make_rgb(0, 0, 153, 255), v);
	drawline(make_point(start_x, start_y + 1), make_point(start_x + square, start_y + 1), make_rgb(0, 0, 153, 255), v);
	drawline(make_point(start_x, start_y), make_point(start_x, start_y + square), make_rgb(0, 0, 153, 255), v);
	drawline(make_point(start_x + 1, start_y), make_point(start_x + 1, start_y + square), make_rgb(0, 0, 153, 255), v);
	drawline(make_point(start_x + square, start_y), make_point(start_x + square, start_y + square + 1), make_rgb(0, 0, 153, 255), v);
	drawline(make_point(start_x + square + 1, start_y), make_point(start_x + square + 1, start_y + square + 1), make_rgb(0, 0, 153, 255), v);
	drawline(make_point(start_x, start_y + square), make_point(start_x + square, start_y + square), make_rgb(0, 0, 153, 255), v);
	drawline(make_point(start_x, start_y + square + 1), make_point(start_x + square, start_y + square + 1), make_rgb(0, 0, 153, 255), v);
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
					pixel_put(v, i * CASES + k, j * CASES, make_rgb(63, 62, 65, 100));
				if (j < HEIGHT / CASES)
					pixel_put(v, i * CASES, j * CASES + k, make_rgb(63, 62, 65, 100));
			}
			if (event.motion.x > 0 && event.motion.x < WIDTH - 30 * 7 && event.motion.y > 0 && event.motion.y < HEIGHT)
			{
				k = 0;
				while (++k < CASES && !(l = 0))
					while (++l < CASES)
					{
						if (event.button.button == SDL_BUTTON_LEFT)
							pixel_put(v, i * CASES + k, j * CASES + l, make_rgb(event.motion.x / CASES == i && event.motion.y / CASES == j ? 0 : 191, event.motion.x / CASES == i && event.motion.y / CASES == j ? 102 : 190, event.motion.x / CASES == i && event.motion.y / CASES == j ? 0 : 193, 255));
						else
							pixel_put(v, i * CASES + k, j * CASES + l, make_rgb(event.motion.x / CASES == i && event.motion.y / CASES == j ? 0 : 191, event.motion.x / CASES == i && event.motion.y / CASES == j ? 179 : 190, event.motion.x / CASES == i && event.motion.y / CASES == j ? 0 : 193, 255));
					}
			}
		}
	}
}

SDL_Texture		*write_text(t_env *v, char *text, SDL_Color fond, SDL_Color police_color)
{
	TTF_Font	*police;
	SDL_Surface	*sur;
	SDL_Texture	*texture;

	if (TTF_Init() == -1)
		ft_error("Initialisation error of TFT_Init");
	police = NULL;
	police = TTF_OpenFont("/srcs/editeur/h.ttf", 20);
	if (!police)
		ft_error("Police error");
	sur = TTF_RenderText_Shaded(police, text, police_color, fond);
	texture = SDL_CreateTextureFromSurface(v->ren, sur);
	SDL_FreeSurface(sur);
	TTF_CloseFont(police);
	TTF_Quit();
	return (texture);
}

void			make_text(t_env *v, SDL_Texture *tex, int x, int y)
{
	SDL_Rect	pos;

	pos.x = WIDTH - 30 * 6;
	pos.y = 30;
	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(v->ren, tex, NULL, &pos);
}

void			menu(t_env *v)
{
	make_text(v, write_text(v, "Forme", (SDL_Color){204, 203, 205, 255}, (SDL_Color){0, 0, 0, 255}), WIDTH - 30 * 6, 30);
	make_form_cube(v, WIDTH - 30 * 6 + 5, 65, 20);
}

void			draw_in_quadrillage(t_env *v, SDL_Event event)
{
	int			g;
	int			t;

	t = -1;
	while (++t < HEIGHT / CASES)
	{
		g = -1;
		while (++g < (WIDTH - 30 * 7) / CASES)
		{
			if (v->tab[t][g].form != 0)
			{
				if (v->tab[t][g].form == 1)
					make_form_cube(v, g * CASES + 5, t * CASES + 5, 20);
			}
		}
	}
}

void			draw_pro_frame(t_env *v, SDL_Event event)
{
	make_quadrillage(v, event);
	menu(v);
	draw_in_quadrillage(v, event);
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
		SDL_RenderPresent(v->ren);
	}
	SDL_DestroyRenderer(v->ren);
	SDL_DestroyWindow(v->win);
	SDL_Quit();
}

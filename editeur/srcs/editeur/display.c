/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 15:57:04 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 16:16:32 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

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
	while (++j < HEIGHT / v->cases)
	{
		i = -1;
		while (++i < (WIDTH - 30 * 7) / v->cases)
		{
			k = -1;
			while (++k <= v->cases)
			{
				if (i < (WIDTH - 30 * 7) / v->cases)
					pixel_put(v, i * v->cases + k, j * v->cases, make_rgb(63, 62, 65, 100));
				if (j < HEIGHT / v->cases)
					pixel_put(v, i * v->cases, j * v->cases + k, make_rgb(63, 62, 65, 100));
			}
			if (event.motion.x > 0 && event.motion.x < WIDTH - 30 * 7 && event.motion.y > 0 && event.motion.y < HEIGHT)
			{
				k = 0;
				while (++k < v->cases && !(l = 0))
					while (++l < v->cases)
					{
						if (event.button.button == SDL_BUTTON_LEFT)
							pixel_put(v, i * v->cases + k, j * v->cases + l, make_rgb(event.motion.x / v->cases == i && event.motion.y / v->cases == j ? 0 : 191, event.motion.x / v->cases == i && event.motion.y / v->cases == j ? 102 : 190, event.motion.x / v->cases == i && event.motion.y / v->cases == j ? 0 : 193, 255));
						else
							pixel_put(v, i * v->cases + k, j * v->cases + l, make_rgb(event.motion.x / v->cases == i && event.motion.y / v->cases == j ? 0 : 191, event.motion.x / v->cases == i && event.motion.y / v->cases == j ? 179 : 190, event.motion.x / v->cases == i && event.motion.y / v->cases == j ? 0 : 193, 255));
					}
			}
		}
	}
}

SDL_Texture		*write_text(t_env *v, char *text, SDL_Color fond, SDL_Color police_color, int taille_police)
{
	TTF_Font	*police;
	SDL_Surface	*sur;
	SDL_Texture	*texture;

	if (TTF_Init() == -1)
		ft_error("Initialisation error of TFT_Init");
	police = NULL;
	police = TTF_OpenFont("/srcs/editeur/h.ttf", taille_police);
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

	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(v->ren, tex, NULL, &pos);
}

void			make_spawn(t_env *v, int start_x, int start_y, int taille)
{
	SDL_Rect	pos;

	pos.x = start_x;
	pos.y = start_y;
	pos.w = taille;
	pos.h = taille;
	if (!(v->sur = IMG_Load("./srcs/editeur/spawn.tga")))
		ft_error((char*)SDL_GetError());
	v->spawn = SDL_CreateTextureFromSurface(v->ren, v->sur);
	SDL_RenderCopy(v->ren, v->spawn, NULL, &pos);
}

// void			make_colonne()
// {
	
// }

void			draw_in_quadrillage(t_env *v)
{
	int			g;
	int			t;

	t = -1;
	while (++t < HEIGHT / v->cases)
	{
		g = -1;
		while (++g < (WIDTH - v->cases * 7) / v->cases)
		{
			if (v->tab[t][g].form != 0)
			{
				if (v->tab[t][g].form == 1)
					make_form_cube(v, g * v->cases + 5, t * v->cases + 5, v->cases - 10);
				if (v->tab[t][g].form == 2)
					make_spawn(v, g * v->cases + 5, t * v->cases + 5, v->cases - 10);
				//if (v->tab[t][g].form == 3)
				//	make_colonne();
			}
		}
	}
}

void			menu(t_env *v)
{
	make_text(v, write_text(v, "Nombre de cases:", (SDL_Color){204, 203, 205, 255}, (SDL_Color){0, 0, 0, 255}, 10), WIDTH - 30 * 5, 10);
	make_text(v, write_text(v, "-", (SDL_Color){204, 203, 205, 255}, (SDL_Color){0, 0, 0, 255}, 10), WIDTH - 45, 10);
	make_text(v, write_text(v, ft_itoa(v->cases), (SDL_Color){204, 203, 205, 255}, (SDL_Color){0, 0, 0, 255}, 10), WIDTH - 33, 10);
	make_text(v, write_text(v, "+", (SDL_Color){204, 203, 205, 255}, (SDL_Color){0, 0, 0, 255}, 10), WIDTH - 15, 10);
	make_text(v, write_text(v, "Forme", (SDL_Color){204, 203, 205, 255}, (SDL_Color){0, 0, 0, 255}, 20), WIDTH - 30 * 6, 30);
	make_form_cube(v, WIDTH - 30 * 6 + 5, 65, 20);
	make_spawn(v, WIDTH - 30 * 5 + 5, 65, 22);
}

void			draw_pro_frame(t_env *v, SDL_Event event)
{
	make_quadrillage(v, event);
	menu(v);
	draw_in_quadrillage(v);
}

void			display(t_env *v)
{
	SDL_Event	event;
	const Uint8	*keyboard_state;

	SDL_RenderCopy(v->ren, v->back, NULL, NULL);
	while (1)
	{
		while (SDL_PollEvent(&event))
		{
			keyboard_state = SDL_GetKeyboardState(NULL);
			if (event.type == SDL_KEYDOWN)
				key_event(keyboard_state);
			if (event.type == SDL_MOUSEBUTTONDOWN)
				mouse_button_event(event, v);
			if (event.type == SDL_MOUSEMOTION)
				mouse_motion_event(event, v);
		}
		if (event.type == SDL_QUIT || key_event(keyboard_state))
			break ;
		draw_pro_frame(v, event);
		SDL_RenderPresent(v->ren);
	}
	SDL_DestroyRenderer(v->ren);
	SDL_DestroyWindow(v->win);
	SDL_Quit();
}

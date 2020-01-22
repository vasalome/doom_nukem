/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 15:57:04 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 16:44:01 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

void			pixel_put(t_env *v, int x, int y, t_rgb color)
{
	SDL_RenderDrawPoint(v->ren, x, y);
	SDL_SetRenderDrawColor(v->ren, color.r, color.g, color.b, color.a);
}

void			draw_form_cube(t_env *v, int start_x, int start_y, int size)
{
	drawline(make_point(start_x, start_y), make_point(start_x + size, start_y), make_rgb(0, 0, 153, 255), v);
	drawline(make_point(start_x, start_y + 1), make_point(start_x + size, start_y + 1), make_rgb(0, 0, 153, 255), v);
	drawline(make_point(start_x, start_y), make_point(start_x, start_y + size), make_rgb(0, 0, 153, 255), v);
	drawline(make_point(start_x + 1, start_y), make_point(start_x + 1, start_y + size), make_rgb(0, 0, 153, 255), v);
	drawline(make_point(start_x + size, start_y), make_point(start_x + size, start_y + size + 1), make_rgb(0, 0, 153, 255), v);
	drawline(make_point(start_x + size + 1, start_y), make_point(start_x + size + 1, start_y + size + 1), make_rgb(0, 0, 153, 255), v);
	drawline(make_point(start_x, start_y + size), make_point(start_x + size, start_y + size), make_rgb(0, 0, 153, 255), v);
	drawline(make_point(start_x, start_y + size + 1), make_point(start_x + size, start_y + size + 1), make_rgb(0, 0, 153, 255), v);
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
					pixel_put(v, i * v->cases + k, j * v->cases, make_rgb(63, 62, 65, 150));
				if (j < HEIGHT / v->cases)
					pixel_put(v, i * v->cases, j * v->cases + k, make_rgb(63, 62, 65, 150));
			}
			if (event.motion.x > 0 && event.motion.x < WIDTH - 30 * 7 && event.motion.y > 0 && event.motion.y < HEIGHT)
			{
				k = 0;
				while (++k < v->cases && !(l = 0))
					while (++l < v->cases)
					{
						if (event.button.button == SDL_BUTTON_LEFT)
							pixel_put(v, i * v->cases + k, j * v->cases + l, make_rgb(event.motion.x / v->cases == i && event.motion.y / v->cases == j ? 0 : 191, event.motion.x / v->cases == i && event.motion.y / v->cases == j ? 102 : 190, event.motion.x / v->cases == i && event.motion.y / v->cases == j ? 0 : 193, 200));
						else
							pixel_put(v, i * v->cases + k, j * v->cases + l, make_rgb(event.motion.x / v->cases == i && event.motion.y / v->cases == j ? 0 : 191, event.motion.x / v->cases == i && event.motion.y / v->cases == j ? 179 : 190, event.motion.x / v->cases == i && event.motion.y / v->cases == j ? 0 : 193, 200));
					}
			}
		}
	}
}

SDL_Texture		*write_text(t_env *v, char *text, SDL_Color background, SDL_Color font_color, int size_font)
{
	TTF_Font	*font;
	SDL_Surface	*sur;
	SDL_Texture	*texture;

	if (TTF_Init() == -1)
		ft_error("Initialisation error of TFT_Init");
	font = NULL;
	font = TTF_OpenFont("/srcs/editeur/h.ttf", size_font);
	if (!font)
		ft_error("font error");
	sur = TTF_RenderText_Shaded(font, text, font_color, background);
	texture = SDL_CreateTextureFromSurface(v->ren, sur);
	SDL_FreeSurface(sur);
	TTF_CloseFont(font);
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

void			make_spawn(t_env *v, int start_x, int start_y, int size)
{
	SDL_Rect	pos;

	pos.x = start_x;
	pos.y = start_y;
	pos.w = size;
	pos.h = size;
	if (!(v->sur = IMG_Load("./srcs/editeur/stickman.xpm")))
		ft_error((char*)SDL_GetError());
	v->spawn = SDL_CreateTextureFromSurface(v->ren, v->sur);
	SDL_FreeSurface(v->sur);
	SDL_RenderCopy(v->ren, v->spawn, NULL, &pos);
	SDL_DestroyTexture(v->spawn);
}

void			draw_diagonal_d(t_env *v, int x, int y, int size)
{
	drawline(make_point(x, y + size), make_point(x + size, y), make_rgb(0, 0, 153, 255), v);
	drawline(make_point(x + 1, y + size + 1), make_point(x + size + 1, y + 1), make_rgb(0, 0, 153, 255), v);
}

void			draw_diagonal_g(t_env *v, int x, int y, int size)
{
	drawline(make_point(x, y), make_point(x + size, y + size), make_rgb(0, 0, 153, 255), v);
	drawline(make_point(x + 2, y), make_point(x + size + 2, y + size), make_rgb(0, 0, 153, 255), v);
}

void			draw_horizontal_wall(t_env *v, int x, int y, int size)
{
	drawline(make_point(x, y + size * 0.5), make_point(x + size, y + size * 0.5), make_rgb(0, 0, 153, 255), v);
	drawline(make_point(x, y + size * 0.5 + 2), make_point(x + size, y + size * 0.5 + 2), make_rgb(0, 0, 153, 255), v);
}

void			draw_vertical_wall(t_env *v, int x, int y, int size)
{
	drawline(make_point(x + size * 0.5, y), make_point(x + size * 0.5, y + size), make_rgb(0, 0, 153, 255), v);
	drawline(make_point(x + size * 0.5 + 2, y), make_point(x + size * 0.5 + 2, y + size), make_rgb(0, 0, 153, 255), v);
}

void			make_door(t_env *v, int start_x, int start_y, int size)
{
	SDL_Rect	pos;

	pos.x = start_x;
	pos.y = start_y;
	pos.w = size;
	pos.h = size;
	if (!(v->sur = IMG_Load("./srcs/editeur/door2.xpm")))
		ft_error((char*)SDL_GetError());
	v->door = SDL_CreateTextureFromSurface(v->ren, v->sur);
	SDL_FreeSurface(v->sur);
	SDL_RenderCopy(v->ren, v->door, NULL, &pos);
	SDL_DestroyTexture(v->door);
}

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
					draw_form_cube(v, g * v->cases + 5, t * v->cases + 5, v->cases - 10);
				if (v->tab[t][g].form == 2)
					draw_horizontal_wall(v, g * v->cases + 5, t * v->cases + 5, v->cases - 10);
				if (v->tab[t][g].form == 3)
					draw_vertical_wall(v, g * v->cases + 5, t * v->cases + 5, v->cases - 10);
				if (v->tab[t][g].form == 4)
					draw_diagonal_d(v, g * v->cases + 5, t * v->cases + 5, v->cases - 10);
				if (v->tab[t][g].form == 5)
					draw_diagonal_g(v, g * v->cases + 5, t * v->cases + 5, v->cases - 10);
				if (v->tab[t][g].form == 6)
					draw_void_circle(v, g * v->cases + (v->cases / 2), t * v->cases + (v->cases / 2), v->cases / 3);
				if (v->tab[t][g].form == 7)
					make_door(v, g * v->cases + 5, t * v->cases + 5, v->cases - 7);
				if (v->tab[t][g].form == 8)
					make_spawn(v, g * v->cases + 5, t * v->cases + 5, v->cases - 10);
			}
		}
	}
}

void			menu(t_env *v)
{
	make_text(v, write_text(v, "Taille des cases:", (SDL_Color){204, 203, 205, 255}, (SDL_Color){0, 0, 0, 255}, 10), WIDTH - 30 * 5, 10);
	make_text(v, write_text(v, "-", (SDL_Color){204, 203, 205, 255}, (SDL_Color){0, 0, 0, 255}, 10), WIDTH - 45, 10);
	make_text(v, write_text(v, ft_itoa(v->cases), (SDL_Color){204, 203, 205, 255}, (SDL_Color){0, 0, 0, 255}, 10), WIDTH - 33, 10);
	make_text(v, write_text(v, "+", (SDL_Color){204, 203, 205, 255}, (SDL_Color){0, 0, 0, 255}, 10), WIDTH - 15, 10);
	make_text(v, write_text(v, "Forme", (SDL_Color){204, 203, 205, 255}, (SDL_Color){0, 0, 0, 255}, 20), WIDTH - 30 * 6, 30);
	draw_form_cube(v, WIDTH - 30 * 6 + 4, 65, 20);
	make_text(v, write_text(v, "Cube", (SDL_Color){204, 203, 205, 255}, (SDL_Color){0, 0, 0, 255}, 12), WIDTH - 30 * 5 + 5, 70);
	draw_horizontal_wall(v, WIDTH - 30 * 6 + 5, 95, 20);
	make_text(v, write_text(v, "Mur plat horizontal", (SDL_Color){204, 203, 205, 255}, (SDL_Color){0, 0, 0, 255}, 12), WIDTH - 30 * 5 + 5, 100);
	draw_vertical_wall(v, WIDTH - 30 * 6 + 5, 125, 20);
	make_text(v, write_text(v, "Mur plat vertical", (SDL_Color){204, 203, 205, 255}, (SDL_Color){0, 0, 0, 255}, 12), WIDTH - 30 * 5 + 5, 130);
	draw_diagonal_d(v, WIDTH - 30 * 6 + 5, 155, 20);
	make_text(v, write_text(v, "Mur plat diagonale", (SDL_Color){204, 203, 205, 255}, (SDL_Color){0, 0, 0, 255}, 12), WIDTH - 30 * 5 + 5, 160);
	draw_diagonal_g(v, WIDTH - 30 * 6 + 5, 185, 20);
	make_text(v, write_text(v, "Mur plat diagonale", (SDL_Color){204, 203, 205, 255}, (SDL_Color){0, 0, 0, 255}, 12), WIDTH - 30 * 5 + 5, 190);
	draw_void_circle(v, WIDTH - 30 * 6 + 15, 215 + 11, 10);
	make_text(v, write_text(v, "Pillier", (SDL_Color){204, 203, 205, 255}, (SDL_Color){0, 0, 0, 255}, 12), WIDTH - 30 * 5 + 5, 220);
	make_door(v, WIDTH - 30 * 6 + 2, 245, 25);
	make_text(v, write_text(v, "Porte", (SDL_Color){204, 203, 205, 255}, (SDL_Color){0, 0, 0, 255}, 12), WIDTH - 30 * 5 + 5, 250);
	make_spawn(v, WIDTH - 30 * 6 + 5, 275, 22);
	make_text(v, write_text(v, "Spawn", (SDL_Color){204, 203, 205, 255}, (SDL_Color){0, 0, 0, 255}, 12), WIDTH - 30 * 5 + 5, 280);
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

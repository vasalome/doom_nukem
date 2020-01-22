/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_form.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 17:09:20 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 17:18:16 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

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

void            put_picture(t_env *v, int start_x, int start_y, int size, char *picture)
{
    SDL_Rect	pos;

	pos.x = start_x;
	pos.y = start_y;
	pos.w = size;
	pos.h = size;
	if (!(v->sur = IMG_Load(picture)))
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

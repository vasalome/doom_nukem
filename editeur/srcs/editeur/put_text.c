/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_text.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 11:22:24 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 16:17:36 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

SDL_Surface		*write_text(char *text, int size_font)
{
	TTF_Font	*font;
	SDL_Surface	*sur;

	if (TTF_Init() == -1)
		ft_error("Initialisation error of TFT_Init");
	font = NULL;
	font = TTF_OpenFont("./srcs/font/h.ttf", size_font);
	if (!font)
		ft_error("font error");
	sur = TTF_RenderText_Shaded(font, text, (SDL_Color){0, 0, 0, 255},
			(SDL_Color){204, 203, 205, 255});
	TTF_CloseFont(font);
	TTF_Quit();
	return (sur);
}

void			put_text(t_env *v, SDL_Surface *sur, int s_x, int s_y)
{
	SDL_Color	col;
	int			x;
	int			y;

	y = -1;
	while (++y < sur->h)
	{
		x = -1;
		while (++x < sur->w)
		{
			SDL_GetRGBA(get_pixel(sur, x, y),
					sur->format, &col.r, &col.g, &col.b, &col.a);
			if (col.a != 0)
				pixel_put(v, x + s_x, y + s_y,
						(t_rgb){col.r, col.g, col.b, col.a});
		}
	}
	SDL_FreeSurface(sur);
}

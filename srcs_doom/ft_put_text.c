/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_put_text.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/03 19:39:37 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 20:12:55 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

SDL_Surface		*write_text(char *text, int size_font)
{
	TTF_Font	*font;
	SDL_Surface	*sur;

	if (TTF_Init() == -1)
		ft_error("Initialisation error of TFT_Init");
	font = NULL;
	font = TTF_OpenFont("./hud/DS-DIGIT.TTF", size_font);
	if (!font)
		ft_error("font error");
	// sur = TTF_RenderText_Shaded(font, text, (SDL_Color){0, 255, 100, 0},
	// 		(SDL_Color){255, 0, 0, 255});
    sur = TTF_RenderText_Solid(font, text, (SDL_Color){0, 255, 100});
	TTF_CloseFont(font);
	TTF_Quit();
	return (sur);
}

void			put_text(t_info *v, SDL_Surface *sur, int s_x, int s_y)
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
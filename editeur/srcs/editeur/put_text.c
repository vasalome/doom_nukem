/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_text.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 11:22:24 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 15:18:08 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

SDL_Texture		*write_text(t_env *v, char *text, int size_font)
{
	TTF_Font	*font;
	SDL_Surface	*sur;
	SDL_Texture	*texture;

	if (TTF_Init() == -1)
		ft_error("Initialisation error of TFT_Init");
	font = NULL;
	font = TTF_OpenFont("./srcs/font/h.ttf", size_font);
	if (!font)
		ft_error("font error");
	sur = TTF_RenderText_Shaded(font, text, (SDL_Color){0, 0, 0, 255},
			(SDL_Color){204, 203, 205, 255});
	texture = SDL_CreateTextureFromSurface(v->ren, sur);
	SDL_FreeSurface(sur);
	TTF_CloseFont(font);
	TTF_Quit();
	return (texture);
}

void			put_text(t_env *v, SDL_Texture *tex, int x, int y)
{
	SDL_Rect	pos;

	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(v->ren, tex, NULL, &pos);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_picture.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 11:22:50 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/25 16:59:44 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

void			put_picture(t_env *v, t_start start, int size, char *picture)
{
	SDL_Rect	pos;

	pos.x = start.x;
	pos.y = start.y;
	pos.w = size;
	pos.h = size;
	if (!(v->sur = IMG_Load(picture)))
		ft_error((char*)SDL_GetError());
	v->tex = SDL_CreateTextureFromSurface(v->ren, v->sur);
	SDL_FreeSurface(v->sur);
	SDL_RenderCopy(v->ren, v->tex, NULL, &pos);
	SDL_DestroyTexture(v->tex);
}

void			make_picture_tga(t_env *v, t_start s, int size, char *pic)
{
	t_tga		*tga;
	int			y;
	int			x;
	int			px;
	int			py;

	y = s.y;
	tga = tga_parser(pic);
	if (!tga)
		ft_error("tga_parser did not work");
	while (++y < s.y + size)
	{
		x = s.x;
		while (++x < s.x + size)
		{
			px = (x - s.x) * tga->h.width / size;
			py = (y - s.y) * tga->h.height / size;
			SDL_SetRenderDrawColor(v->ren, tga->px[py * tga->h.width + px].r,
										tga->px[py * tga->h.width + px].g,
										tga->px[py * tga->h.width + px].b,
										tga->px[py * tga->h.width + px].a);
			SDL_RenderDrawPoint(v->ren, x + s.x, y + s.y);
		}
	}
}

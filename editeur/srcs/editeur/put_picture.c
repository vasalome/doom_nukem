/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_picture.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 11:22:50 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 17:09:57 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

void			put_picture(t_env *v, t_start s, int size, char *picture)
{
	SDL_Surface	*sur;
	SDL_Color	col;
	int			x;
	int			y;

	if (!(sur = IMG_Load(picture)))
		ft_error((char*)SDL_GetError());
	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			SDL_GetRGBA(get_pixel(sur, x * sur->w / size, y * sur->h / size),
					sur->format, &col.r, &col.g, &col.b, &col.a);
			if (col.a != 0)
				pixel_put(v, s.x + x, s.y + y, (t_rgb){col.r, col.g, col.b,
						col.a});
		}
	}
	SDL_FreeSurface(sur);
}

void			make_picture_tga(t_env *v, t_start s, int size, char *pic)
{
	t_tga		*tga;
	int			y;
	int			x;
	int			px;
	int			py;

	y = -1;
	tga = tga_parser(pic);
	if (!tga)
		ft_error("tga_parser did not work");
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			px = x * tga->h.width / size;
			py = y * tga->h.height / size;
			if (tga->px[py * tga->h.width + px].a != 0)
				pixel_put(v, x + s.x, y + s.y,
						(t_rgb){tga->px[py * tga->h.width + px].r,
								tga->px[py * tga->h.width + px].g,
								tga->px[py * tga->h.width + px].b,
								tga->px[py * tga->h.width + px].a});
		}
	}
}

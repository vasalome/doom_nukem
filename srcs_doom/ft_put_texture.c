/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_put_texture.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/03 16:28:59 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 19:10:59 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int				get_hex_rgba(int r, int g, int b, int a)
{
	return ((r << 24) | (g << 16) | (b << 8) | (a));
}

void			pixel_put(t_info *v, int x, int y, t_rgb color)
{
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	v->pixels[y * WIDTH + x] = get_hex_rgba(color.r, color.g, color.b, color.a);
}

Uint32			get_pixel(SDL_Surface *surface, int x, int y)
{
	int			bpp;
	Uint8		*p;

	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	if (bpp == 1)
		return (*p);
	else if (bpp == 2)
		return (*(Uint16 *)p);
	else if (bpp == 3)
		return (p[0] | p[1] << 8 | p[2] << 16);
	else if (bpp == 4)
		return (*(Uint32 *)p);
	return (0);
}

void			put_texture(t_info *v, t_start s, t_size size, SDL_Surface *sur)
{
	SDL_Color	col;
	int			x;
	int			y;

	y = -1;
	while (++y < size.y)
	{
		x = -1;
		while (++x < size.x)
		{
			SDL_GetRGBA(get_pixel(sur, x * sur->w / size.x, y * sur->h / size.y),
					sur->format, &col.r, &col.g, &col.b, &col.a);
			if (col.a > 65)
				pixel_put(v, s.x + x, s.y + y, (t_rgb){col.r, col.g, col.b,
						col.a});
		}
	}
}

//put_texture(v, (t_start){x, y}, (t_size){size_x, size_y}, t_tex *tex)
/*
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
}*/

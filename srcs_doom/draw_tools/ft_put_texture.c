/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_put_texture.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 17:18:43 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 11:15:57 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include_doom/doom.h"

void			ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int				get_hex_rgba(int r, int g, int b, int a)
{
	return ((r << 24) | (g << 16) | (b << 8) | (a));
}

void			pixel_put(t_info *v, int x, int y, t_rgb col)
{
	int			mix_r;
	int			mix_g;
	int			mix_b;
	int			a_bef;
	int			new_alpha;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	if (v->pixels[y * WIDTH + x] != 0)
	{
		a_bef = (v->pixels[y * WIDTH + x] & 0xFF) / 1.2;
		mix_r = col.r * col.a / 255 + (v->pixels[y * WIDTH + x] >> 8 & 0xFF) * a_bef * (255 - col.a) / 65025;
		mix_g = col.g * col.a / 255 + (v->pixels[y * WIDTH + x] >> 16 & 0xFF) * a_bef * (255 - col.a) / 65025;
		mix_b = col.b * col.a / 255 + (v->pixels[y * WIDTH + x] >> 24 & 0xFF) * a_bef * (255 - col.a) / 65025;
		new_alpha = col.a + (a_bef * (255 - col.a) / 255);
		v->pixels[y * WIDTH + x] = get_hex_rgba(mix_r, mix_g, mix_b, new_alpha);
	}
	else
		v->pixels[y * WIDTH + x] = get_hex_rgba(col.r, col.g, col.b, col.a);
	// if (v->game == 1 && x == 400 && y == 400){
	// 	printf("x %d\n", x);
	// 	printf("y %d\n", y);
	// 	printf("mix_r %d\n", mix_r);
	// 	printf("mix_g %d\n", mix_g);
	// 	printf("mix_b %d\n\n", mix_b);}
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
			SDL_GetRGBA(get_pixel(sur, x * sur->w / size.x, y * sur->h /
				size.y), sur->format, &col.r, &col.g, &col.b, &col.a);
			if (col.a != 0)
				pixel_put(v, s.x + x, s.y + y, (t_rgb){col.r, col.g, col.b,
						col.a});
		}
	}
}
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

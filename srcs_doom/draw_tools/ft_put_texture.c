/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_put_texture.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/03 16:28:59 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 16:05:44 by nrivoire    ###    #+. /#+    ###.fr     */
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

/*
void			pixel_put(t_info *v, int x, int y, t_rgb color)
{
    // int		r_out = (rA * aA / 255) + (rB * aB * (255 - aA) / (255*255));
	// int		g_out = (gA * aA / 255) + (gB * aB * (255 - aA) / (255*255));
	// int		b_out = (bA * aA / 255) + (bB * aB * (255 - aA) / (255*255));
	// int		a_out = aA + (aB * (255 - aA) / 255);



    // printf("x  = %d\n", x);
    // printf("y  = %d\n", y);
    // printf("before %d -> \n", v->pixels[y * WIDTH + x] & 0xFF);
    // printf("1 r= %d\n", color.r);
    // printf("1 g= %d\n", color.g);
	
    // printf("1 a= %d\n", color.a);
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;

	v->pixels[y * WIDTH + x] = get_hex_rgba(color.r, color.g, color.b, color.a);
	//if ((v->pixels[y * WIDTH + x] & 0xFF) == 0)
       //printf("%d -> ", v->pixels[y * WIDTH + x] & 0xFF);
	if ((get_hex_rgba(color.r, color.g, color.b, color.a) & 0xFF) == 0)
    	v->pixels[y * WIDTH + x] = get_hex_rgba(color.r, color.g, color.b, color.a);
    // printf("after %d -> \n", v->pixels[y * WIDTH + x] & 0xFF);
}
*/

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

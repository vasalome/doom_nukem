/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tga_parser_body.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/25 17:01:43 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/25 17:03:27 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

static t_px			make_pixel(unsigned char *byte, int byte_size)
{
	t_px			px;

	if (byte_size == 4)
	{
		px.r = ft_atoi_base(get_chunk(byte[2]), 16);
		px.g = ft_atoi_base(get_chunk(byte[1]), 16);
		px.b = ft_atoi_base(get_chunk(byte[0]), 16);
		px.a = ft_atoi_base(get_chunk(byte[3]), 16);
	}
	else if (byte_size == 3)
	{
		px.r = ft_atoi_base(get_chunk(byte[2]), 16);
		px.g = ft_atoi_base(get_chunk(byte[1]), 16);
		px.b = ft_atoi_base(get_chunk(byte[0]), 16);
		px.a = 255;
	}
	else
	{
		px.r = ft_atoi_base(get_chunk((byte[1] & 0x7c) << 1), 16);
		px.g = ft_atoi_base(get_chunk(((byte[1] & 0x03) << 6) |
				((byte[0] & 0xe0) >> 2)), 16);
		px.b = ft_atoi_base(get_chunk((byte[0] & 0x1f) << 3), 16);
		px.a = ft_atoi_base(get_chunk(byte[1] & 0x80), 16);
	}
	return (px);
}

t_px				*save_tga_rgba(int fd, t_px *px, t_header h, int byte_s)
{
	int				i;
	unsigned int	n;
	int				ret;
	unsigned char	byte[byte_s];

	ret = 0;
	n = -1;
	i = 0;
	while ((ret = read(fd, byte, byte_s)) > 0 && (++n < (h.height * h.width)))
	{
		if (h.datatypecode == 2)
			px[n] = make_pixel(byte, byte_s);
		else if (h.datatypecode == 10)
		{
			px[n] = make_pixel(&(byte[1]), byte_s);
			if ((byte[0] & 0x80) && !(i == -1))
				while (++i < (byte[0] & 0x7f))
					px[n] = make_pixel(&(byte[1]), byte_s);
			else if (!(i == -1))
				while (++i < (byte[0] & 0x7f))
					px[n] = make_pixel(byte, byte_s);
		}
	}
	return (px);
}

t_px				*invert_order_px(t_tga *tga)
{
	int				i;
	int				v;
	t_px			*res;

	v = 0;
	i = tga->h.height * tga->h.width - 1;
	if (!(res = malloc(sizeof(t_px) * (tga->h.width * tga->h.height))))
		ft_error("The malloc of the pixel struct didn't work.");
	while (i >= 0)
	{
		res[v].r = tga->px[i].r;
		res[v].g = tga->px[i].g;
		res[v].b = tga->px[i].b;
		res[v].a = tga->px[i].a;
		v++;
		i--;
	}
	free(tga->px);
	return (res);
}

void				swap_rgba(t_px *left, t_px *right)
{
	t_px			tmp;

	tmp.r = left->r;
	tmp.g = left->g;
	tmp.b = left->b;
	tmp.a = left->a;
	left->r = right->r;
	left->g = right->g;
	left->b = right->b;
	left->a = right->a;
	right->r = tmp.r;
	right->g = tmp.g;
	right->b = tmp.b;
	right->a = tmp.a;
}

void				mirror(t_tga *tga, int w, int h)
{
	int				i;
	int				j;
	int				l;
	int				pair;

	i = -1;
	l = w - 1;
	pair = w % 2;
	pair = 0 ? 0 : 1;
	if (pair == 0)
		while (++i < w * 0.5)
		{
			j = -1;
			while (++j < h)
				swap_rgba(&tga->px[i + w * j], &tga->px[l + w * j]);
			l--;
		}
	else
		while (++i < w * 0.5 - 1)
		{
			j = -1;
			while (++j < h)
				swap_rgba(&tga->px[i + w * j], &tga->px[l + w * j]);
			l--;
		}
}

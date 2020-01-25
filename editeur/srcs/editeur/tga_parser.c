/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tga_parser.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 09:31:49 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/25 15:09:48 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "../../includes/tga_parser.h"

char				*get_chunk(char chunk)
{
	char			*str;
	char			rep[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	int				i;
	int				j;

	i = -1;
	j = 0;
	str = ft_strnew(2);
	while (++i < 1)
	{
		str[j] = rep[(chunk >> 4) & 0x0F];
		str[j + 1] = rep[chunk & 0x0F];
		j = j + 2;
	}
	return (str);
}

t_px				make_pixel(unsigned char *byte, int byte_size)
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
		px.g = ft_atoi_base(get_chunk(((byte[1] & 0x03) << 6) | ((byte[0] & 0xe0) >> 2)), 16);
		px.b = ft_atoi_base(get_chunk((byte[0] & 0x1f) << 3), 16);
		px.a = ft_atoi_base(get_chunk(byte[1] & 0x80), 16);
	}
	return (px);
}

t_px				*save_tga_rgba(int fd, t_px *px, t_header h, int byte_size)
{
	int				i;
	unsigned int	n;
	int				ret;
	unsigned char	byte[byte_size];

	ret = 0;
	n = -1;
	while ((ret = read(fd, byte, byte_size)) > 0 && (++n < (h.height * h.width)))
	{
		if (h.datatypecode == 2)
			px[n] = make_pixel(byte, byte_size);
		else if (h.datatypecode == 10)
		{
			px[n] = make_pixel(&(byte[1]), byte_size);
			if ((byte[0] & 0x80) && (i == -1))
			{
				i = -1;
				while (++i < (byte[0] & 0x7f))
					px[n] = make_pixel(&(byte[1]), byte_size);
			}
			else
			{
				i = -1;
				while (++i < (byte[0] & 0x7f))
					px[n] = make_pixel(byte, byte_size);
			}
		}
	}
	return (px);
}

t_header			save_header_tga(t_header h, int fd)
{
	int 			ret;
	char			buff[18];

	ret = 0;
	while ((ret = read(fd, buff, 18)))
	{
		h.idlength = buff[0];
		h.colourmaptype = buff[1];
		h.datatypecode = buff[2];
		h.colourmaporigin = buff[3];
		h.colourmaplength = buff[5];
		h.colourmapdepth = buff[7];
		h.x_origin = buff[8];
		h.y_origin = buff[10];
		h.width = ft_atoi_base(ft_strjoin(get_chunk(buff[11]), get_chunk(buff[12])), 16);
		h.height = ft_atoi_base(ft_strjoin(get_chunk(buff[13]), get_chunk(buff[14])), 16);
		h.bitsperpixel = buff[16];
		h.imagedescriptor = buff[17];
		break;
	}
	if (h.datatypecode != 2 && h.datatypecode != 10)
		ft_error("Can only handle image type 2 and 10");
	if (h.bitsperpixel != 16 && h.bitsperpixel != 24 && h.bitsperpixel != 32)
		ft_error("Can only handle pixel depths of 16, 24, and 32");
	if (h.colourmaptype != 0 && h.colourmaptype != 1)
		ft_error("Can only handle colour map types of 0 and 1");
	return (h);
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

t_tga				*tga_parser(char *img)
{
	t_tga			*tga;
	int				fd;

	fd = open(img, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!(tga = ft_memalloc(sizeof(tga))))
		return (0);
	tga->h = save_header_tga(tga->h, fd);
	if (!(tga->px = malloc(sizeof(t_px) * (tga->h.width * tga->h.height))))
		ft_error("The malloc of the pixel struct didn't work.");
	tga->px = save_tga_rgba(fd, tga->px, tga->h, tga->h.bitsperpixel / 8);
	tga->px = invert_order_px(tga);
	mirror(tga, tga->h.width, tga->h.height);
	return (tga);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tga_parser_body.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/25 17:01:43 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 17:27:38 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

static int			pixel(unsigned char byte)
{
	char			*tmp;
	int				res;

	tmp = get_chunk(byte);
	res = ft_atoi_base(tmp, 16);
	free(tmp);
	return (res);
}

static t_px			make_pixel(unsigned char *byte, int byte_size)
{
	t_px			px;

	if (byte_size == 4)
	{
		px.r = pixel(byte[2]);
		px.g = pixel(byte[1]);
		px.b = pixel(byte[0]);
		px.a = pixel(byte[3]);
	}
	else if (byte_size == 3)
	{
		px.r = pixel(byte[2]);
		px.g = pixel(byte[1]);
		px.b = pixel(byte[0]);
		px.a = 255;
	}
	else
	{
		px.r = pixel((byte[1] & 0x7c) << 1);
		px.g = pixel(((byte[1] & 0x03) << 6) | ((byte[0] & 0xe0) >> 2));
		px.b = pixel((byte[0] & 0x1f) << 3);
		px.a = pixel(byte[1] & 0x80);
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

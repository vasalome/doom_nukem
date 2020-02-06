/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tga_parser.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 09:31:49 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 17:37:24 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

char				*get_chunk(char chunk)
{
	char			*str;
	char			*rep;
	int				i;
	int				j;

	rep = "0123456789ABCDEF";
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

static void			check_error_header(t_header h)
{
	if (h.datatypecode != 2 && h.datatypecode != 10)
		ft_error("Can only handle image type 2 and 10");
	if (h.bitsperpixel != 16 && h.bitsperpixel != 24 && h.bitsperpixel != 32)
		ft_error("Can only handle pixel depths of 16, 24, and 32");
	if (h.colourmaptype != 0 && h.colourmaptype != 1)
		ft_error("Can only handle colour map types of 0 and 1");
}

int					find_size(char first, char second)
{
	int				size;
	char			*tmp;
	char			*a;
	char			*b;

	a = get_chunk(first);
	b = get_chunk(second);
	tmp = ft_strjoin(a, b);
	free(a);
	free(b);
	size = ft_atoi_base(tmp, 16);
	free(tmp);
	return (size);
}

static t_header		save_header_tga(t_header h, int fd, int ret)
{
	char			buff[18];

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
		h.width = find_size(buff[11], buff[12]);
		h.height = find_size(buff[13], buff[14]);
		h.bitsperpixel = buff[16];
		h.imagedescriptor = buff[17];
		break ;
	}
	check_error_header(h);
	return (h);
}

t_tga				*tga_parser(char *img)
{
	t_tga			*tga;
	int				fd;
	int				ret;

	ret = 0;
	fd = open(img, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!(tga = ft_memalloc(sizeof(tga))))
		return (0);
	tga->h = save_header_tga(tga->h, fd, ret);
	if (!(tga->px = malloc(sizeof(t_px) * (tga->h.width * tga->h.height))))
		ft_error("The malloc of the pixel struct didn't work.");
	tga->px = save_tga_rgba(fd, tga->px, tga->h, tga->h.bitsperpixel / 8);
	tga->px = invert_order_px(tga);
	mirror(tga, tga->h.width, tga->h.height);
	return (tga);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tga_swap.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 17:27:12 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 17:27:31 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

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

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_in_grid_pattern.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 11:55:18 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 14:58:59 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

static void		choose_your_form_from_1_to_9(t_env *v, int g, int t)
{
	int			x;
	int			y;
	t_start		s;

	x = g * v->cases;
	y = t * v->cases;
	s = (t_start){x + 5, y + 5};
	if (v->tab[t][g].form == 1)
		draw_form_cube(v, s, v->cases - 10, (t_rgb){0, 0, 153, 255});
	if (v->tab[t][g].form == 2)
		draw_horizontal_wall(v, x + 5, y + 5, v->cases - 10);
	if (v->tab[t][g].form == 3)
		draw_vertical_wall(v, x + 5, y + 5, v->cases - 10);
	if (v->tab[t][g].form == 4)
		draw_diagonal_d(v, x + 5, y + 5, v->cases - 10);
	if (v->tab[t][g].form == 5)
		draw_diagonal_g(v, x + 5, y + 5, v->cases - 10);
	if (v->tab[t][g].form == 6)
		draw_void_circle(v, x + v->cases / 2, y + v->cases / 2, v->cases / 3);
	if (v->tab[t][g].form == 7)
		put_picture(v, s, v->cases - 7, "./src/img/door.xpm");
	if (v->tab[t][g].form == 8)
		put_picture(v, s, v->cases - 7, "./src/img/stickman.xpm");
	if (v->tab[t][g].form == 9)
		v->tab[t][g].form = 0;
}

void			draw_in_grid_pattern(t_env *v)
{
	int			g;
	int			t;

	t = -1;
	while (++t < v->h / v->cases)
	{
		g = -1;
		while (++g < (v->w - v->cases * 7) / v->cases)
			if (v->tab[t][g].form != 0)
				choose_your_form_from_1_to_9(v, g, t);
	}
}

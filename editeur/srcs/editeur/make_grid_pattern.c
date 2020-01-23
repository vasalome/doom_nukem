/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_grid_pattern.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 11:40:17 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 11:44:48 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

static void		where_is_the_mouse(t_env *v, SDL_Event e, int i, int j)
{
	int			k;
	int			l;
	int			pos_x;
	int			pos_y;

	pos_x = e.motion.x / v->cases;
	pos_y = e.motion.y / v->cases;
	k = 0;
	while (++k < v->cases && !(l = 0))
		while (++l < v->cases)
		{
			if (e.button.button == SDL_BUTTON_LEFT)
				pixel_put(v, i * v->cases + k, j * v->cases + l, make_rgb(
						pos_x == i && pos_y == j ? 0 : 191,
						pos_x == i && pos_y == j ? 102 : 190,
						pos_x == i && pos_y == j ? 0 : 193, 200));
			else
				pixel_put(v, i * v->cases + k, j * v->cases + l, make_rgb(
						pos_x == i && pos_y == j ? 0 : 191,
						pos_x == i && pos_y == j ? 179 : 190,
						pos_x == i && pos_y == j ? 0 : 193, 200));
		}
}

void			make_grid_pattern(t_env *v, SDL_Event event)
{
	int			i;
	int			j;
	int			k;

	j = -1;
	while (++j < HEIGHT / v->cases)
	{
		i = -1;
		while (++i < (WIDTH - 30 * 7) / v->cases)
		{
			k = -1;
			while (++k <= v->cases)
			{
				if (i < (WIDTH - 30 * 7) / v->cases)
					pixel_put(v, i * v->cases + k, j * v->cases,
							make_rgb(63, 62, 65, 150));
				if (j < HEIGHT / v->cases)
					pixel_put(v, i * v->cases, j * v->cases + k,
							make_rgb(63, 62, 65, 150));
			}
			if (event.motion.x > 0 && event.motion.x < WIDTH - 30 * 7 &&
					event.motion.y > 0 && event.motion.y < HEIGHT)
				where_is_the_mouse(v, event, i, j);
		}
	}
}

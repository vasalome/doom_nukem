/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_grid_pattern.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 11:40:17 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 17:10:32 by nrivoire    ###    #+. /#+    ###.fr     */
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
	t_rgb		color[3];

	color[0] = (t_rgb){191, 190, 193, 200};
	color[1] = (t_rgb){0, 102, 0, 200};
	color[2] = (t_rgb){0, 179, 0, 200};
	pos_x = e.motion.x / v->cases;
	pos_y = e.motion.y / v->cases;
	k = 0;
	while (++k < v->cases && !(l = 0))
		while (++l < v->cases)
		{
			if (e.button.button == SDL_BUTTON_LEFT
				|| e.button.button == SDL_BUTTON_RIGHT)
				pixel_put(v, i * v->cases + k, j * v->cases + l,
						pos_x == i && pos_y == j ? color[1] : color[0]);
			else
				pixel_put(v, i * v->cases + k, j * v->cases + l,
						pos_x == i && pos_y == j ? color[2] : color[0]);
		}
}

void			make_grid_pattern(t_env *v, SDL_Event event)
{
	int			i;
	int			j;
	int			k;

	j = -1;
	while (++j < v->h / v->cases)
	{
		i = -1;
		while (++i < (v->w - 30 * 7) / v->cases)
		{
			k = -1;
			while (++k <= v->cases)
			{
				if (i < (v->w - 30 * 7) / v->cases)
					pixel_put(v, i * v->cases + k, j * v->cases,
							(t_rgb){63, 62, 65, 150});
				if (j < v->h / v->cases)
					pixel_put(v, i * v->cases, j * v->cases + k,
							(t_rgb){63, 62, 65, 150});
			}
			if (event.motion.x > 0 && event.motion.x < v->w - 30 * 7 &&
					event.motion.y > 0 && event.motion.y < v->h)
				where_is_the_mouse(v, event, i, j);
		}
	}
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_form.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 17:09:20 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 15:21:08 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

void			draw_form_cube(t_env *v, t_start start, int size, t_rgb color)
{
	drawline((t_point){start.x, start.y}, (t_point){start.x + size, start.y},
			color, v);
	drawline((t_point){start.x, start.y + 1}, (t_point){start.x + size,
			start.y + 1}, color, v);
	drawline((t_point){start.x, start.y}, (t_point){start.x, start.y + size},
			color, v);
	drawline((t_point){start.x + 1, start.y}, (t_point){start.x + 1,
			start.y + size}, color, v);
	drawline((t_point){start.x + size, start.y}, (t_point){start.x + size,
			start.y + size + 1}, color, v);
	drawline((t_point){start.x + size + 1, start.y}, (t_point){start.x +
			size + 1, start.y + size + 1}, color, v);
	drawline((t_point){start.x, start.y + size}, (t_point){start.x + size,
			start.y + size}, color, v);
	drawline((t_point){start.x, start.y + size + 1}, (t_point){start.x +
			size, start.y + size + 1}, color, v);
}

void			draw_diagonal_d(t_env *v, int x, int y, int size)
{
	drawline((t_point){x, y + size}, (t_point){x + size, y},
			(t_rgb){0, 0, 153, 255}, v);
	drawline((t_point){x + 1, y + size + 1}, (t_point){x + size + 1,
			y + 1}, (t_rgb){0, 0, 153, 255}, v);
}

void			draw_diagonal_g(t_env *v, int x, int y, int size)
{
	drawline((t_point){x, y}, (t_point){x + size, y + size},
			(t_rgb){0, 0, 153, 255}, v);
	drawline((t_point){x + 2, y}, (t_point){x + size + 2, y + size},
			(t_rgb){0, 0, 153, 255}, v);
}

void			draw_horizontal_wall(t_env *v, int x, int y, int size)
{
	drawline((t_point){x, y + size * 0.5}, (t_point){x + size,
			y + size * 0.5}, (t_rgb){0, 0, 153, 255}, v);
	drawline((t_point){x, y + size * 0.5 + 2}, (t_point){x + size,
			y + size * 0.5 + 2}, (t_rgb){0, 0, 153, 255}, v);
}

void			draw_vertical_wall(t_env *v, int x, int y, int size)
{
	drawline((t_point){x + size * 0.5, y}, (t_point){x + size * 0.5,
			y + size}, (t_rgb){0, 0, 153, 255}, v);
	drawline((t_point){x + size * 0.5 + 2, y}, (t_point){x + size *
			0.5 + 2, y + size}, (t_rgb){0, 0, 153, 255}, v);
}

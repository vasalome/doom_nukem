/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window_tex.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/27 17:28:48 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 15:12:24 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

static void		make_window(t_env *v)
{
	int		x;
	int		y;

	y = 280;
	x = 350;
	drawline((t_point){x, y}, (t_point){x, 520}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){351, y}, (t_point){351, 520}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){352, y}, (t_point){352, 520}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){x, y}, (t_point){820, y}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){x, 281}, (t_point){820, 281}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){x, 282}, (t_point){820, 282}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){820, 520}, (t_point){820, y}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){821, 520}, (t_point){821, y}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){822, 520}, (t_point){822, y}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){x, 520}, (t_point){822, 520}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){x, 521}, (t_point){822, 521}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){x, 522}, (t_point){822, 522}, (t_rgb){0, 0, 0, 255}, v);
	y = 282;
	while (++y < 520)
	{
		x = 352;
		while (++x < 820)
			pixel_put(v, x, y, (t_rgb){217, 217, 217, 255});
	}
	put_picture(v, (t_start){803, 284}, 16, "./src/img/accept.xpm");
}

void			open_window(t_env *v)
{
	make_window(v);
	if (v->form == 1)
	{
		put_text(v, write_text("Choisissez votre texture pour chaque mur", 15),
				400, 300);
		choosing_cube_tex(v);
	}
	if (v->form > 1 && v->form < 6)
	{
		if (v->chosen_tex.flat_wall != v->button && v->button > 0)
			v->chosen_tex.flat_wall = v->button;
		choose_one_tex(v, v->chosen_tex.flat_wall);
	}
	if (v->form == 6)
	{
		if (v->chosen_tex.pillar != v->button && v->button > 0)
			v->chosen_tex.pillar = v->button;
		choose_one_tex(v, v->chosen_tex.pillar);
	}
	if (v->valid == 1)
	{
		v->window = 0;
		v->valid = 0;
	}
}

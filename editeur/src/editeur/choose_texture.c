/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   choose_texture.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/03 15:09:04 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 15:38:09 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

static void		make_cube_tex(t_env *v, int chosen)
{
	if (v->nb_wall < 4)
		put_picture(v, (t_start){790, 490}, 24, v->img[4]);
	if (v->nb_wall > 1)
		put_picture(v, (t_start){360, 490}, 24, v->img[3]);
	put_picture(v, (t_start){420, 370}, 35, v->wall[0]);
	put_picture(v, (t_start){420, 420}, 35, v->wall[1]);
	put_picture(v, (t_start){520, 370}, 35, v->wall[2]);
	put_picture(v, (t_start){520, 420}, 35, v->wall[3]);
	put_picture(v, (t_start){620, 370}, 35, v->wall[4]);
	put_picture(v, (t_start){620, 420}, 35, v->wall[5]);
	put_picture(v, (t_start){720, 370}, 35, v->wall[6]);
	put_picture(v, (t_start){720, 420}, 35, v->wall[7]);
	if (v->motion % 2 == 0 && v->motion > 0)
		draw_form_cube(v, (t_start){319 + 100 * (v->motion - v->motion * 0.5),
				419}, 36, (t_rgb){179, 0, 0, 255});
	else if (v->motion % 2 != 0 && v->motion > 0)
		draw_form_cube(v, (t_start){319 + 100 * (v->motion - (v->motion - 1) *
				0.5), 369}, 36, (t_rgb){179, 0, 0, 255});
	if (chosen % 2 == 0 && chosen > 0)
		draw_form_cube(v, (t_start){319 + 100 * (chosen - chosen * 0.5), 419},
				36, (t_rgb){102, 255, 51, 255});
	else if (chosen % 2 != 0 && chosen > 0)
		draw_form_cube(v, (t_start){319 + 100 * (chosen - (chosen - 1) * 0.5),
				369}, 36, (t_rgb){102, 255, 51, 255});
}

void			choosing_cube_tex_2(t_env *v)
{
	if (v->nb_wall == 3)
	{
		if (v->chosen_tex.nord != v->button && v->button > 0)
			v->chosen_tex.nord = v->button;
		put_text(v, write_text("MUR 3 : face nord", 12), 520, 330);
		make_cube_tex(v, v->chosen_tex.nord);
	}
	else if (v->nb_wall == 4)
	{
		if (v->chosen_tex.ouest != v->button && v->button > 0)
			v->chosen_tex.ouest = v->button;
		put_text(v, write_text("MUR 4 : face ouest", 12), 520, 330);
		make_cube_tex(v, v->chosen_tex.ouest);
	}
}

void			choosing_cube_tex(t_env *v)
{
	if (v->nb_wall == 1)
	{
		if (v->chosen_tex.est != v->button && v->button > 0)
			v->chosen_tex.est = v->button;
		put_text(v, write_text("MUR 1 : face est", 12), 520, 330);
		make_cube_tex(v, v->chosen_tex.est);
	}
	else if (v->nb_wall == 2)
	{
		if (v->chosen_tex.sud != v->button && v->button > 0)
			v->chosen_tex.sud = v->button;
		put_text(v, write_text("MUR 2 : face sud", 12), 520, 330);
		make_cube_tex(v, v->chosen_tex.sud);
	}
	choosing_cube_tex_2(v);
}

void			choose_one_tex(t_env *v, int chosen)
{
	put_text(v, write_text("Choisissez votre texture pour le mur", 15),
			400, 300);
	put_picture(v, (t_start){420, 370}, 35, v->wall[0]);
	put_picture(v, (t_start){420, 420}, 35, v->wall[1]);
	put_picture(v, (t_start){520, 370}, 35, v->wall[2]);
	put_picture(v, (t_start){520, 420}, 35, v->wall[3]);
	put_picture(v, (t_start){620, 370}, 35, v->wall[4]);
	put_picture(v, (t_start){620, 420}, 35, v->wall[5]);
	put_picture(v, (t_start){720, 370}, 35, v->wall[6]);
	put_picture(v, (t_start){720, 420}, 35, v->wall[7]);
	if (v->motion % 2 == 0 && v->motion > 0)
		draw_form_cube(v, (t_start){319 + 100 * (v->motion - v->motion * 0.5),
				419}, 36, (t_rgb){179, 0, 0, 255});
	else if (v->motion % 2 != 0 && v->motion > 0)
		draw_form_cube(v, (t_start){319 + 100 * (v->motion - (v->motion - 1) *
				0.5), 369}, 36, (t_rgb){179, 0, 0, 255});
	if (chosen % 2 == 0 && chosen > 0)
		draw_form_cube(v, (t_start){319 + 100 * (chosen - chosen * 0.5), 419},
				36, (t_rgb){102, 255, 51, 255});
	else if (chosen % 2 != 0 && chosen > 0)
		draw_form_cube(v, (t_start){319 + 100 * (chosen - (chosen - 1) * 0.5),
				369}, 36, (t_rgb){102, 255, 51, 255});
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window_tex.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/27 17:28:48 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 18:46:03 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

void        make_window(t_env *v)
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
	put_picture(v, (t_start){803, 284}, 16, "./srcs/images/accept.xpm");
}

void		make_cube_tex(t_env *v, int chosen)
{
	if (v->nb_wall < 4)
		put_picture(v, (t_start){790, 490}, 24, "./srcs/images/r_arrow.xpm");
	if (v->nb_wall > 1)
		put_picture(v, (t_start){360, 490}, 24, "./srcs/images/l_arrow.xpm");
	put_picture(v, (t_start){420, 370}, 35, "./srcs/tex/wall1.xpm");
	put_picture(v, (t_start){420, 420}, 35, "./srcs/tex/wall2.xpm");
	put_picture(v, (t_start){520, 370}, 35, "./srcs/tex/wall3.xpm");
	put_picture(v, (t_start){520, 420}, 35, "./srcs/tex/wall4.xpm");
	put_picture(v, (t_start){620, 370}, 35, "./srcs/tex/wall5.xpm");
	put_picture(v, (t_start){620, 420}, 35, "./srcs/tex/wall6.xpm");
	put_picture(v, (t_start){720, 370}, 35, "./srcs/tex/wall7.xpm");
	put_picture(v, (t_start){720, 420}, 35, "./srcs/tex/wall8.xpm");
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

void		choosing_cube_tex(t_env *v)
{
	put_text(v, write_text("Choisissez votre texture pour chaque mur", 15),
			400, 300);
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
	else if (v->nb_wall == 3)
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

void		open_window(t_env *v)
{
	make_window(v);
	if (v->form == 1)
		choosing_cube_tex(v);
	if (v->valid == 1)
	{
		v->window = 0;
		v->valid = 0;
	}
}

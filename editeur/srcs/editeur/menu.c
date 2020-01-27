/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   menu.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 11:55:48 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 15:21:49 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

void			menu_squares_size(t_env *v)
{
	put_text(v, write_text(v, "Taille des cases:", 10), WIDTH - 30 * 5, 10);
	put_text(v, write_text(v, "-", 10), WIDTH - 45, 10);
	put_text(v, write_text(v, ft_itoa(v->cases), 10), WIDTH - 33, 10);
	put_text(v, write_text(v, "+", 10), WIDTH - 15, 10);
	put_text(v, write_text(v, "Forme", 20), WIDTH - 30 * 6, 30);
}

void			menu_form_part(t_env *v)
{
	draw_form_cube(v, WIDTH - 30 * 6 + 4, 65, 20);
	put_text(v, write_text(v, "Cube", 12), WIDTH - 30 * 5 + 5, 70);
	draw_horizontal_wall(v, WIDTH - 30 * 6 + 5, 95, 20);
	put_text(v, write_text(v, "Mur plat horizontal", 12),
			WIDTH - 30 * 5 + 5, 100);
	draw_vertical_wall(v, WIDTH - 30 * 6 + 5, 125, 20);
	put_text(v, write_text(v, "Mur plat vertical", 12),
			WIDTH - 30 * 5 + 5, 130);
	draw_diagonal_d(v, WIDTH - 30 * 6 + 5, 155, 20);
	put_text(v, write_text(v, "Mur plat diagonale", 12),
			WIDTH - 30 * 5 + 5, 160);
	draw_diagonal_g(v, WIDTH - 30 * 6 + 5, 185, 20);
	put_text(v, write_text(v, "Mur plat diagonale", 12),
			WIDTH - 30 * 5 + 5, 190);
	draw_void_circle(v, WIDTH - 30 * 6 + 15, 215 + 11, 10);
	put_text(v, write_text(v, "Pillier", 12), WIDTH - 30 * 5 + 5, 220);
	//put_picture(v, (t_start){WIDTH - 30 * 6 + 2, 245}, 25,
	//		"./srcs/images/door.xpm");
	make_picture_tga(v, (t_start){WIDTH - 30 * 6 + 2, 245}, 25, "./srcs/images/door.tga");
	put_text(v, write_text(v, "Porte", 12), WIDTH - 30 * 5 + 5, 250);
	put_picture(v, (t_start){WIDTH - 30 * 6 + 5, 275}, 22,
			"./srcs/images/stickman.xpm");
	put_text(v, write_text(v, "Spawn", 12), WIDTH - 30 * 5 + 5, 280);
	put_picture(v, (t_start){WIDTH - 30 * 6 + 2, 302}, 27,
			"./srcs/images/gomme.xpm");
	put_text(v, write_text(v, "Gomme", 12), WIDTH - 30 * 5 + 5, 310);
}

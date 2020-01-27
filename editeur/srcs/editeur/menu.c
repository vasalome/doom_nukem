/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   menu.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 11:55:48 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 17:21:23 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

void			menu_text(t_env *v)
{
	put_text(v, write_text("Taille des cases:", 10), v->w - 30 * 5, 10);
	put_text(v, write_text("-", 10), v->w - 45, 10);
	put_text(v, write_text(ft_itoa(v->cases), 10), v->w - 33, 10);
	put_text(v, write_text("+", 10), v->w - 15, 10);
	put_text(v, write_text("Forme", 20), v->w - 30 * 6, 30);
	put_text(v, write_text("Cube", 12), v->w - 30 * 5 + 5, 70);
	put_text(v, write_text("Mur plat horizontal", 12), v->w - 30 * 5 + 5, 100);
	put_text(v, write_text("Mur plat vertical", 12), v->w - 30 * 5 + 5, 130);
	put_text(v, write_text("Mur plat diagonale", 12), v->w - 30 * 5 + 5, 160);
	put_text(v, write_text("Mur plat diagonale", 12), v->w - 30 * 5 + 5, 190);
	put_text(v, write_text("Pillier", 12), v->w - 30 * 5 + 5, 220);
	put_text(v, write_text("Porte", 12), v->w - 30 * 5 + 5, 250);
	put_text(v, write_text("Spawn", 12), v->w - 30 * 5 + 5, 280);
	put_text(v, write_text("appuyez sur ENTREE", 15), 1015, v->h - 57);
	put_text(v, write_text("pour generer la map", 15), 1010, v->h - 37);
	put_text(v, write_text("Outils", 20), v->w - 30 * 6, 560);
	put_text(v, write_text("clique droit sur la case", 10), v->w - 30 * 5, 596);
}

void			menu_button(t_env *v)
{
	draw_form_cube(v, v->w - 30 * 6 + 4, 65, 20);
	draw_horizontal_wall(v, v->w - 30 * 6 + 5, 95, 20);
	draw_vertical_wall(v, v->w - 30 * 6 + 5, 125, 20);
	draw_diagonal_d(v, v->w - 30 * 6 + 5, 155, 20);
	draw_diagonal_g(v, v->w - 30 * 6 + 5, 185, 20);
	draw_void_circle(v, v->w - 30 * 6 + 15, 215 + 11, 10);
	make_picture_tga(v, (t_start){v->w - 30 * 6 + 2, 245}, 25,
			"./srcs/images/door.tga");
	put_picture(v, (t_start){v->w - 30 * 6 + 5, 275}, 22,
			"./srcs/images/stickman.xpm");
	make_picture_tga(v, (t_start){v->w - 30 * 6 + 5, 590}, 22,
			"./srcs/images/gomme.tga");
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_button.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 13:37:48 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 15:55:46 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

static void		press_button(t_env *v, int start_x, int start_y, int taille)
{
	int		i;
	int		j;

	j = start_y;
	while (++j < start_y + taille)
	{
		i = start_x - 1;
		while (++i < start_x + taille)
			pixel_put(v, i, j, (t_rgb){166, 166, 166, 255});
	}
}

static void		click_form(t_env *v, int nb_form, int x, int y)
{
	v->form = nb_form;
	press_button(v, x, y, 32);
	if (v->form < 7)
	{
		v->window = 1;
		v->plus++;
	}
}

int				button_is_between(SDL_Event e, t_between b)
{
	if (e.button.x > b.min_x && e.button.x < b.max_x &&
			e.button.y > b.min_y && e.button.y < b.max_y)
		return (1);
	return (0);
}

void			init_button(t_env *v, SDL_Event e)
{
	int			w;

	w = v->w - 30 * 6;
	if (button_is_between(e, (t_between){w, w + 30, 65, 95}))
		click_form(v, 1, w, 60);
	else if (button_is_between(e, (t_between){w, w + 30, 95, 125}))
		click_form(v, 2, w, 90);
	else if (button_is_between(e, (t_between){w, w + 30, 125, 155}))
		click_form(v, 3, w, 120);
	else if (button_is_between(e, (t_between){w, w + 30, 155, 185}))
		click_form(v, 4, w, 150);
	else if (button_is_between(e, (t_between){w, w + 30, 185, 215}))
		click_form(v, 5, w, 180);
	else if (button_is_between(e, (t_between){w, w + 30, 215, 245}))
		click_form(v, 6, w, 210);
	else if (button_is_between(e, (t_between){w, w + 30, 245, 275}))
		click_form(v, 7, w, 240);
	else if (button_is_between(e, (t_between){w, w + 30, 275, 305}))
		click_form(v, 8, w, 270);
	else if (button_is_between(e, (t_between){w, w + 30, 305, 335}))
		click_form(v, 9, w, 300);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_button_event.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 13:39:25 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 14:46:29 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

void		which_form(t_env *v, SDL_Event e)
{
	int		t;
	int		g;

	t = -1;
	while (++t < HEIGHT / v->cases)
	{
		g = -1;
		while (++g < (WIDTH - v->cases * 7) / v->cases)
		{
			if (e.button.x / v->cases == g && e.button.y / v->cases == t
					&& v->form != 8)
			{
				if (v->tab[t][g].form == 8)
					v->spawn_count = 0;
				v->tab[t][g].form = v->form;
			}
			else if (v->spawn_count == 0 && e.button.x / v->cases == g
					&& e.button.y / v->cases == t)
			{
				v->tab[t][g].form = v->form;
				v->spawn_count = 1;
			}
		}
	}
}

void		press_button(t_env *v, int start_x, int start_y, int taille)
{
	int		i;
	int		j;

	j = start_y;
	while (++j < start_y + taille)
	{
		i = start_x - 1;
		while (++i < start_x + taille)
			pixel_put(v, i, j, make_rgb(166, 166, 166, 255));
	}
}

void		click_form(t_env *v, int nb_form, int x, int y)
{
	v->form = nb_form;
	press_button(v, x, y, 32);
}

int			button_is_between(SDL_Event e, t_between b)
{
	if (e.button.x > b.min_x && e.button.x < b.max_x &&
			e.button.y > b.min_y && e.button.y < b.max_y)
		return (1);
	return (0);
}

void		init_form(t_env *v, SDL_Event e)
{
	int		w;

	w = WIDTH - 30 * 6;
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

void		choose_the_size_of_your_map(t_env *v, SDL_Event e)
{
	if (v->cases > 15 && v->cases <= 30 && e.button.x > WIDTH - 45
			&& e.button.x < WIDTH - 35 && e.button.y > 15 && e.button.y < 20)
	{
		free_tab(v, v->tab);
		v->spawn_count = 0;
		if (v->cases == 30)
			v->cases = 18;
		else if (v->cases == 18)
			v->cases = 15;
		background_map(v);
		make_map(v);
	}
	if (v->cases >= 15 && v->cases < 30 && e.button.x > WIDTH - 15 &&
			e.button.x < WIDTH - 5 && e.button.y > 15 && e.button.y < 20)
	{
		free_tab(v, v->tab);
		v->spawn_count = 0;
		if (v->cases == 15)
			v->cases = 18;
		else if (v->cases == 18)
			v->cases = 30;
		background_map(v);
		make_map(v);
	}
}

void		mouse_button_event(SDL_Event e, t_env *v)
{
	if (e.button.button == SDL_BUTTON_LEFT)
	{
		init_form(v, e);
		choose_the_size_of_your_map(v, e);
		if (e.button.x > 0 && e.button.x < WIDTH - 30 * 7
				&& e.button.y > 0 && e.button.y < HEIGHT)
			which_form(v, e);
	}
}

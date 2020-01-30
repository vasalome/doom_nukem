/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_button_event.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 13:39:25 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 14:59:35 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

int			stretching(t_env *v, int inc)
{
	if (v->tab[v->s.y][v->s.x].form == 8)
		v->spawn_count = 0;
	v->tab[v->s.y][v->s.x].form = v->form;
	v->tab[v->s.y][v->s.x].texture = v->chosen_tex;
	if (inc != 0)
		return (inc);
	return (0);
}

void		do_the_user_stretch(t_env *v)
{
	if (v->s.x == v->s.dir_x && v->s.y == v->s.dir_y)
		stretching(v, 0);
	else if (v->s.x == v->s.dir_x && v->s.y != v->s.dir_y)
	{
		while (v->s.y < v->s.dir_y)
			v->s.y += stretching(v, 1);
		while (v->s.y >= v->s.dir_y)
			v->s.y -= stretching(v, 1);
	}
	else if (v->s.y == v->s.dir_y && v->s.x != v->s.dir_x)
	{
		while (v->s.x < v->s.dir_x)
			v->s.x += stretching(v, 1);
		while (v->s.x >= v->s.dir_x)
			v->s.x -= stretching(v, 1);
	}
}

void		which_form(t_env *v)
{
	int		t;
	int		g;

	t = -1;
	while (++t < v->h / v->cases)
	{
		g = -1;
		while (++g < (v->w - v->cases * 7) / v->cases)
		{
			if (v->s.x == g && v->s.y == t && v->form != 8)
				do_the_user_stretch(v);
			else if (v->spawn_count == 0 && v->s.x == g && v->s.y == t)
			{
				v->tab[t][g].form = v->form;
				v->spawn_count = 1;
			}
		}
	}
}

void		choose_the_size_of_your_map(t_env *v, SDL_Event e)
{
	if (v->cases > 15 && v->cases <= 30 && e.button.x > v->w - 45
			&& e.button.x < v->w - 35 && e.button.y > 15 && e.button.y < 20)
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
	if (v->cases >= 15 && v->cases < 30 && e.button.x > v->w - 15 &&
			e.button.x < v->w - 5 && e.button.y > 15 && e.button.y < 20)
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
	if (v->window == 0)
	{
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			if (e.button.button == SDL_BUTTON_LEFT)
			{
				init_button(v, e);
				choose_the_size_of_your_map(v, e);
			}
			if (e.button.button == SDL_BUTTON_RIGHT)
				v->form = 9;
			v->s.x = e.button.x / v->cases;
			v->s.y = e.button.y / v->cases;
		}
		else if (e.type == SDL_MOUSEBUTTONUP)
		{
			v->s.dir_x = e.motion.x / v->cases;
			v->s.dir_y = e.motion.y / v->cases;
			if (e.button.x > 0 && e.button.x < v->w - 30 * 7
					&& e.button.y > 0 && e.button.y < v->h)
				which_form(v);
		}
	}
	else
	{
		if (e.button.button == SDL_BUTTON_LEFT && e.type == SDL_MOUSEBUTTONDOWN)
		{
			if (button_is_between(e, (t_between){804, 820, 282, 298}))
				v->valid = 1;
			if (button_is_between(e, (t_between){790, 820, 490, 522}))
			{
				if (v->form == 1 && v->nb_wall < 4)
				{
					v->nb_wall++;
					v->button = 1;
				}
			}
			if (button_is_between(e, (t_between){360, 390, 490, 522}))
			{
				if (v->form == 1 && v->nb_wall > 1)
				{
					v->nb_wall--;
					v->button = 1;
				}
			}
			if (button_is_between(e, (t_between){420, 455, 370, 395}))
				v->button = 1;
			else if (button_is_between(e, (t_between){420, 458, 420, 458}))
				v->button = 2;
			else if (button_is_between(e, (t_between){520, 558, 370, 398}))
				v->button = 3;
			else if (button_is_between(e, (t_between){520, 558, 420, 458}))
				v->button = 4;
			else if (button_is_between(e, (t_between){620, 658, 370, 398}))
				v->button = 5;
			else if (button_is_between(e, (t_between){620, 658, 420, 458}))
				v->button = 6;
			else if (button_is_between(e, (t_between){720, 758, 370, 398}))
				v->button = 7;
			else if (button_is_between(e, (t_between){720, 758, 420, 458}))
				v->button = 8;
		}
	}
}

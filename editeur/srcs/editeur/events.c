/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 17:14:18 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 16:36:51 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

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

void		is_it_over_the_button(t_env *v, int start_x, int start_y, int taille, t_rgb color)
{
	int		i;
	int		j;

	j = start_y;
	while (++j < start_y + taille)
	{
		i = start_x - 1;
		while (++i < start_x + taille)
			pixel_put(v, i, j, color);
	}
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

void		which_form(t_env *v, SDL_Event e)
{
	int		t;
	int		g;

	t = - 1;
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

void		mouse_button_event(SDL_Event event, t_env *v)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		if (event.button.x > WIDTH - 30 * 6 + 5 && event.button.x < WIDTH - 30 * 6 + 20 && event.button.y > 65 && event.button.y < 95)
		{
			v->form = 1;
			press_button(v, WIDTH - 30 * 6, 60, 32);
		}
		if (event.button.x > WIDTH - 30 * 6 + 5 && event.button.x < WIDTH - 30 * 6 + 20 && event.button.y > 95 && event.button.y < 125)
		{
			v->form = 2;
			press_button(v, WIDTH - 30 * 6, 90, 32);
		}
		if (event.button.x > WIDTH - 30 * 6 + 5 && event.button.x < WIDTH - 30 * 6 + 20 && event.button.y > 125 && event.button.y < 155)
		{
			v->form = 3;
			press_button(v, WIDTH - 30 * 6, 120, 32);
		}
		if (event.button.x > WIDTH - 30 * 6 + 5 && event.button.x < WIDTH - 30 * 6 + 20 && event.button.y > 155 && event.button.y < 185)
		{
			v->form = 4;
			press_button(v, WIDTH - 30 * 6, 150, 32);
		}
		if (event.button.x > WIDTH - 30 * 6 + 5 && event.button.x < WIDTH - 30 * 6 + 20 && event.button.y > 185 && event.button.y < 215)
		{
			v->form = 5;
			press_button(v, WIDTH - 30 * 6, 180, 32);
		}
		if (event.button.x > WIDTH - 30 * 6 + 5 && event.button.x < WIDTH - 30 * 6 + 20 && event.button.y > 215 && event.button.y < 245)
		{
			v->form = 6;
			press_button(v, WIDTH - 30 * 6, 210, 32);
		}
		if (event.button.x > WIDTH - 30 * 6 + 5 && event.button.x < WIDTH - 30 * 6 + 20 && event.button.y > 245 && event.button.y < 275)
		{
			v->form = 7;
			press_button(v, WIDTH - 30 * 6, 240, 32);
		}
		if (event.button.x > WIDTH - 30 * 6 + 5 && event.button.x < WIDTH - 30 * 6 + 20 && event.button.y > 275 && event.button.y < 305)
		{
			v->form = 8;
			press_button(v, WIDTH - 30 * 6, 270, 32);
		}
		choose_the_size_of_your_map(v, event);
		if (event.button.x > 0 && event.button.x < WIDTH - 30 * 7 && event.button.y > 0 && event.button.y < HEIGHT)
			which_form(v, event);
	}
}

void		mouse_motion_event(SDL_Event event, t_env *v)
{
	if (event.motion.x > WIDTH - 30 * 6 + 5 && event.motion.x < WIDTH - 30 * 6 + 20 && event.motion.y > 65 && event.motion.y < 95)
		is_it_over_the_button(v, WIDTH - 30 * 6, 60, 32, make_rgb(191, 191, 191, 255));
	else
		is_it_over_the_button(v, WIDTH - 30 * 6, 60, 32, make_rgb(204, 203, 205, 255));
	if (event.motion.x > WIDTH - 30 * 6 + 5 && event.motion.x < WIDTH - 30 * 6 + 20 && event.motion.y > 95 && event.motion.y < 125)
		is_it_over_the_button(v, WIDTH - 30 * 6, 90, 32, make_rgb(191, 191, 191, 255));
	else
		is_it_over_the_button(v, WIDTH - 30 * 6, 90, 32, make_rgb(204, 203, 205, 255));
	if (event.motion.x > WIDTH - 30 * 6 + 5 && event.motion.x < WIDTH - 30 * 6 + 20 && event.motion.y > 125 && event.motion.y < 155)
		is_it_over_the_button(v, WIDTH - 30 * 6, 120, 32, make_rgb(191, 191, 191, 255));
	else
		is_it_over_the_button(v, WIDTH - 30 * 6, 120, 32, make_rgb(204, 203, 205, 255));
	if (event.motion.x > WIDTH - 30 * 6 + 5 && event.motion.x < WIDTH - 30 * 6 + 20 && event.motion.y > 155 && event.motion.y < 185)
		is_it_over_the_button(v, WIDTH - 30 * 6, 150, 32, make_rgb(191, 191, 191, 255));
	else
		is_it_over_the_button(v, WIDTH - 30 * 6, 150, 32, make_rgb(204, 203, 205, 255));
	if (event.motion.x > WIDTH - 30 * 6 + 5 && event.motion.x < WIDTH - 30 * 6 + 20 && event.motion.y > 185 && event.motion.y < 215)
		is_it_over_the_button(v, WIDTH - 30 * 6, 180, 32, make_rgb(191, 191, 191, 255));
	else
		is_it_over_the_button(v, WIDTH - 30 * 6, 180, 32, make_rgb(204, 203, 205, 255));
	if (event.motion.x > WIDTH - 30 * 6 + 5 && event.motion.x < WIDTH - 30 * 6 + 20 && event.motion.y > 215 && event.motion.y < 245)
		is_it_over_the_button(v, WIDTH - 30 * 6, 210, 32, make_rgb(191, 191, 191, 255));
	else
		is_it_over_the_button(v, WIDTH - 30 * 6, 210, 32, make_rgb(204, 203, 205, 255));
	if (event.motion.x > WIDTH - 30 * 6 + 5 && event.motion.x < WIDTH - 30 * 6 + 20 && event.motion.y > 245 && event.motion.y < 275)
		is_it_over_the_button(v, WIDTH - 30 * 6, 240, 32, make_rgb(191, 191, 191, 255));
	else
		is_it_over_the_button(v, WIDTH - 30 * 6, 240, 32, make_rgb(204, 203, 205, 255));
	if (event.motion.x > WIDTH - 30 * 6 + 5 && event.motion.x < WIDTH - 30 * 6 + 20 && event.motion.y > 275 && event.motion.y < 305)
		is_it_over_the_button(v, WIDTH - 30 * 6, 270, 32, make_rgb(191, 191, 191, 255));
	else
		is_it_over_the_button(v, WIDTH - 30 * 6, 270, 32, make_rgb(204, 203, 205, 255));
}

int			key_event(const Uint8 *keyboard_state)
{
	if (keyboard_state[SDL_SCANCODE_ESCAPE])
		return (1);
	return (0);
}

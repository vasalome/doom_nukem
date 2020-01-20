/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 17:14:18 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 17:28:32 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

void		press_button(t_env *v, int start_x, int start_y, int taille)
{
	int		i;
	int		j;

	j = start_y - 1;
	while (++j < start_y + taille)
	{
		i = start_x;
		while (++i < start_x + taille)
			pixel_put(v, i, j, make_rgb(166, 166, 166, 255));
	}
}

void		is_it_over_the_button(t_env *v, int start_x, int start_y, int taille, t_rgb color)
{
	int		i;
	int		j;

	j = start_y - 1;
	while (++j < start_y + taille)
	{
		i = start_x - 1;
		while (++i < start_x + taille)
			pixel_put(v, i, j, color);
	}
}

void		mouse_button_event(SDL_Event event, t_env *v)
{
	int			g;
	int			t;

	if (event.button.x > WIDTH - 30 * 6 + 5 && event.button.x < WIDTH - 30 * 6 + 20 && event.button.y > 65 && event.button.y < 95)
	{
		v->form = 1;
		press_button(v, WIDTH - 30 * 6, 60, 32);
	}
	if (event.button.x > WIDTH - 30 * 5 + 5 && event.button.x < WIDTH - 30 * 5 + 20 && event.button.y > 65 && event.button.y < 95)
	{
		v->form = 2;
		press_button(v, WIDTH - 30 * 5, 60, 32);
	}
	if (v->cases > 15 && v->cases <= 30 && event.button.x > WIDTH - 45 && event.button.x < WIDTH - 35 && event.button.y > 15 && event.button.y < 20)
	{
		free_tab(v, v->tab);
		v->cases -= 3;
		background_map(v);
		make_map(v);
	}
	if (v->cases >= 15 && v->cases < 30 && event.button.x > WIDTH - 15 && event.button.x < WIDTH - 5 && event.button.y > 15 && event.button.y < 20)
	{
		free_tab(v, v->tab);
		v->cases += 3;
		background_map(v);
		make_map(v);
	}
	if (event.button.x > 0 && event.button.x < WIDTH - 30 * 7 && event.button.y > 0 && event.button.y < HEIGHT)
	{
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			t = - 1;
			while (++t < HEIGHT / v->cases)
			{
				g = -1;
				while (++g < (WIDTH - v->cases * 7) / v->cases)
				{
					if (event.button.x / v->cases == g && event.button.y / v->cases == t)
						v->tab[t][g].form = v->form;
				}
			}
		}
	}
}

void		mouse_motion_event(SDL_Event event, t_env *v)
{
	if (event.motion.x > WIDTH - 30 * 6 + 5 && event.motion.x < WIDTH - 30 * 6 + 20 && event.motion.y > 65 && event.motion.y < 95)
		is_it_over_the_button(v, WIDTH - 30 * 6, 60, 32, make_rgb(191, 191, 191, 255));
	else
		is_it_over_the_button(v, WIDTH - 30 * 6, 60, 32, make_rgb(204, 203, 205, 255));
	if (event.motion.x > WIDTH - 30 * 5 + 5 && event.motion.x < WIDTH - 30 * 5 + 20 && event.motion.y > 65 && event.motion.y < 95)
		is_it_over_the_button(v, WIDTH - 30 * 5, 60, 32, make_rgb(191, 191, 191, 255));
	else
		is_it_over_the_button(v, WIDTH - 30 * 5, 60, 32, make_rgb(204, 203, 205, 255));
}

int			key_event(const Uint8 *keyboard_state)
{
	if (keyboard_state[SDL_SCANCODE_ESCAPE])
		return (1);
	return (0);
}

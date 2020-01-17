/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 17:14:18 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 17:38:44 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/editeur.h"

// int			is_it_over_the_circle(t_lst *cur_p, int x, int y)
// {
// 	if (sqrt(pow(x - cur_p->center_x, 2) + pow(y - cur_p->center_y, 2)) < RADIUS)
// 	{
// 		cur_p->over = 1;
// 		return (1);
// 	}
// 	else
// 	{
// 		cur_p->over = 0;
// 		return (0);
// 	}
// }

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

// void			draw_in_quadrillage(t_env *v, SDL_Event event)
// {
// 	int			g;
// 	int			t;

// 	t = -1;
// 	while (++t < HEIGHT / CASES)
// 	{
// 		g = -1;
// 		while (++g < (WIDTH - 30 * 7) / CASES)
// 		{
// 			if (v->tab[t][g].form == 1)
// 				//printf("x = %d y = %d\n", v->tab[t][g].case_x, v->tab[t][g].case_y);
// 		}
// 	}
// }

void		mouse_button_event(SDL_Event event, t_env *v)
{
	int			g;
	int			t;

	if (event.button.x > WIDTH - 30 * 6 + 5 && event.button.x < WIDTH - 30 * 6 + 20 && event.button.y > 65 && event.button.y < 95)
	{
		v->form = 1;
		press_button(v, WIDTH - 30 * 6, 60, 32);
	}
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		t = - 1;
		while (++t < HEIGHT / CASES)
		{
			g = -1;
			while (++g < (WIDTH - 30 * 7) / CASES)
			{
				if (event.button.x / CASES == g && event.button.y / CASES == t)
					v->tab[t][g].form = v->form;
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
}

int			key_event(const Uint8 *keyboard_state, t_env *v)
{
	if (keyboard_state[SDL_SCANCODE_ESCAPE])
		return (1);
	return (0);
}

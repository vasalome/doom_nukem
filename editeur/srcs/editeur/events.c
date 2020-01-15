/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 17:14:18 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 17:41:07 by nrivoire    ###    #+. /#+    ###.fr     */
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

void		mouse_button_event(SDL_Event event, t_env *v)
{

}

void		mouse_motion_event(SDL_Event event, t_env *v)
{

}

int			key_event(const Uint8 *keyboard_state, t_env *v)
{
	if (keyboard_state[SDL_SCANCODE_ESCAPE])
		return (1);
	return (0);
}

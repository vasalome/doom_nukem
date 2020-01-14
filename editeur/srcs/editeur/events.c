/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 17:14:18 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 14:50:34 by nrivoire    ###    #+. /#+    ###.fr     */
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

// int			select_point(t_lst *lst, int x, int y)
// {
// 	t_lst	*elem;

// 	elem = lst;
// 	while (elem != NULL)
// 	{
// 		if (is_it_over_the_circle(elem, x, y))
// 		{
// 			elem->select = 1;
// 			return (1);
// 		}
// 		elem = elem->next;
// 	}
// 	return (0);
// }

// t_lst		*where_am_i(t_lst *lst)
// {
// 	t_lst	*elem;

// 	elem = lst;
// 	while (elem != NULL)
// 	{
// 		if (elem->select == 1)
// 			return (elem);
// 		elem = elem->next;
// 	}
// }

void		mouse_button_event(SDL_Event event, t_env *v)
{
	// t_lst	*elem;

	// if (event.button.button == SDL_BUTTON_LEFT)
	// {
	// 	if (select_point(v->point, event.button.x, event.button.y))
	// 	{
	// 		//elem = where_am_i(v->point);
	// 		printf("there is already a point\n");
	// 	}
	// 	else
	// 		new_elem_lst(&v->point, event.button.x, event.button.y);
	// }
}

void		mouse_motion_event(SDL_Event event, t_env *v)
{
	// t_lst	*elem;

	// elem = v->point;
	// if (v->point)
	// 	while (elem != NULL)
	// 	{
	// 		// if (elem->select == 1 && event.motion.x > 0 && event.motion.x < WIDTH - 180 && event.motion.y > 0 && event.motion.y < HEIGHT - 180)
	// 		// {
	// 		// 	elem->seg = 1;
	// 		// 	//printf("%d %d\n", event.motion.xrel, event.motion.yrel);
	// 		// 	//printf("%d %d\n", event.motion.x, event.motion.y);
	// 		// 	drawline(make_point(elem->center_x, elem->center_y), make_point(event.motion.x - event.motion.xrel, event.motion.y - event.motion.yrel), make_rgb(0, 0, 0, 255), v);
	// 		// 	drawline(make_point(elem->center_x, elem->center_y), make_point(event.motion.x, event.motion.y), make_rgb(255, 255, 255, 255), v);
	// 		// }
	// 		// //else
	// 		// //	drawline(make_point(elem->center_x, elem->center_y), make_point(event.motion.x, event.motion.y), make_rgb(0, 0, 0, 255), v);
	// 		if (is_it_over_the_circle(elem, event.motion.x, event.motion.y))
	// 			break;
	// 		elem = elem->next;
	// 	}
}

int			key_event(const Uint8 *keyboard_state, t_env *v)
{
	if (keyboard_state[SDL_SCANCODE_ESCAPE])
		return (1);
	return (0);
}

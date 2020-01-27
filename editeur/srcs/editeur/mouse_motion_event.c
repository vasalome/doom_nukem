/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_motion_event.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 13:41:22 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/25 18:37:41 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

void		is_it_over_the_button(t_env *v, t_start s, int size, t_rgb color)
{
	int		i;
	int		j;

	j = s.y;
	while (++j < s.y + size)
	{
		i = s.x - 1;
		while (++i < s.x + size)
			pixel_put(v, i, j, color);
	}
}

int			mouse_location(SDL_Event e, t_between b)
{
	if (e.motion.x > b.min_x && e.motion.x < b.max_x &&
			e.motion.y > b.min_y && e.motion.y < b.max_y)
		return (1);
	return (0);
}

void		mouse_motion_event_2(SDL_Event event, t_env *v,
		t_rgb color, t_rgb color_click)
{
	int		w;

	w = WIDTH - 30 * 6;
	if (mouse_location(event, (t_between){w, w + 30, 60, 90}))
		is_it_over_the_button(v, (t_start){w, 60}, 32, color_click);
	else
		is_it_over_the_button(v, (t_start){w, 60}, 32, color);
	if (mouse_location(event, (t_between){w, w + 30, 90, 120}))
		is_it_over_the_button(v, (t_start){w, 90}, 32, color_click);
	else
		is_it_over_the_button(v, (t_start){w, 90}, 32, color);
	if (mouse_location(event, (t_between){w, w + 30, 120, 150}))
		is_it_over_the_button(v, (t_start){w, 120}, 32, color_click);
	else
		is_it_over_the_button(v, (t_start){w, 120}, 32, color);
	if (mouse_location(event, (t_between){w, w + 30, 150, 180}))
		is_it_over_the_button(v, (t_start){w, 150}, 32, color_click);
	else
		is_it_over_the_button(v, (t_start){w, 150}, 32, color);
	if (mouse_location(event, (t_between){w, w + 30, 180, 210}))
		is_it_over_the_button(v, (t_start){w, 180}, 32, color_click);
	else
		is_it_over_the_button(v, (t_start){w, 180}, 32, color);
}

void		mouse_motion_event(SDL_Event event, t_env *v)
{
	int		w;
	t_rgb	color_click;
	t_rgb	color;

	color_click = (t_rgb){191, 191, 191, 255};
	color = (t_rgb){204, 203, 205, 255};
	w = WIDTH - 30 * 6;
	mouse_motion_event_2(event, v, color, color_click);
	if (mouse_location(event, (t_between){w, w + 30, 210, 240}))
		is_it_over_the_button(v, (t_start){w, 210}, 32, color_click);
	else
		is_it_over_the_button(v, (t_start){w, 210}, 32, color);
	if (mouse_location(event, (t_between){w, w + 30, 240, 270}))
		is_it_over_the_button(v, (t_start){w, 240}, 32, color_click);
	else
		is_it_over_the_button(v, (t_start){w, 240}, 32, color);
	if (mouse_location(event, (t_between){w, w + 30, 270, 300}))
		is_it_over_the_button(v, (t_start){w, 270}, 32, color_click);
	else
		is_it_over_the_button(v, (t_start){w, 270}, 32, color);
	if (mouse_location(event, (t_between){w, w + 30, 300, 330}))
		is_it_over_the_button(v, (t_start){w, 300}, 32, color_click);
	else
		is_it_over_the_button(v, (t_start){w, 300}, 32, color);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_motion_event.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/03 19:21:06 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 13:01:48 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include_doom/doom.h"

void			load_button(t_info *info, int i, SDL_Event event)
{
	t_start		start;
	t_size		size;

	start.x = ((WIDTH / 4) * 3 - (info->menu[i].button->w / 1.5) / 2) + info->xOffsetMenu;
	start.y = (info->menu[1].button->h / 1.4  + ((info->menu[i].button->h / 5 + 10) * (i - 2))) + info->yOffsetMenu;
	size.x = (info->menu[i].button->w / 1.5) * info->zoom;;
	size.y = (info->menu[i].button->h / 5) * info->zoom;
	if (event.motion.x > start.x && event.motion.x < (start.x + size.x))
		if (event.motion.y > start.y && event.motion.y < (start.y + size.y))
		{
			put_texture(info, start, size, info->menu[4].button);
			info->button = i - 2;
		}
	else
		put_texture(info, start, size, info->menu[2].button);
}

void		mouse_motion_event(t_info *info, SDL_Event event)
{
	int		i;

	i = 1;
	if (info->game == 2)
	{
	    SDL_ShowCursor(SDL_DISABLE);
	    info->player.turn_right = 1;
	    info->player.turn_left = 1;
	    info->player.turn_rate = -event.motion.xrel * 0.002;
	    info->player.turn_rate_y = event.motion.yrel * 0.002;
	    SDL_WarpMouseInWindow(info->win.win, info->win.w/2, info->win.h/2);
	    info->raycast = 1;
	}
	else if (info->game == 3)
	{
	    info->xrel = event.motion.xrel;
	    info->yrel = event.motion.yrel;
	}
	else
		while (++i <= 5)
			load_button(&info, i, event);
}

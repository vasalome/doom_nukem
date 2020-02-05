/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_motion_event.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/03 19:21:06 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 17:03:53 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include_doom/doom.h"

void			load_button(t_info *info, int i, SDL_Event e)
{
	t_start		start;
	t_size		size;
	char		*str;

	start.x = WIDTH - (WIDTH / 5 + WIDTH / 8);
	start.y = HEIGHT - (HEIGHT - (HEIGHT / 4 * i + HEIGHT / 32));
	size.x = info->menu[1]->w / 1.5;
	size.y = info->menu[1]->h / 5;
	if (e.motion.x >= start.x && e.motion.x <= (start.x + size.x)
			&& e.motion.y >= start.y && e.motion.y <= (start.y + size.y))
	{
		str = ft_strjoin(" Level ", ft_itoa(i));
		put_text(info, write_text(str, size.y / 1.34),
				start.x + 5, start.y + 5);
		free(str);
		info->button = i - 1;
	}
	else
		put_texture(info, start, size, info->menu[1]);
}

void			mouse_motion_event(t_info *info, SDL_Event event)
{
	int			i;

	i = 0;
	if (info->game == 2)
	{
		SDL_ShowCursor(SDL_DISABLE);
		info->player.turn_right = 1;
		info->player.turn_left = 1;
		info->player.turn_rate = -event.motion.xrel * 0.002;
		info->player.turn_rate_y = event.motion.yrel * 0.002;
		SDL_WarpMouseInWindow(info->win.win, WIDTH / 2, HEIGHT / 2);
		info->raycast = 1;
	}
	else if (info->game == 3)
	{

	}
	else
		while (++i <= 4)
			load_button(info, i, event);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_motion_event.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 20:04:01 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 20:04:03 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include_doom/doom.h"

void	turn_left(t_info *info)
{
	if (info->player.turn_left == 1)
	{
		info->fps.rect.y += 500 * info->player.turn_rate_y;
		if (info->fps.rect.y > 0)
			info->fps.rect.y = 0;
		if (info->fps.rect.y < -400)
			info->fps.rect.y = -400;
		info->player.turn_left = 0;	
	}
}

void	turn_right(t_info *info)
{
	if (info->player.turn_right == 1)
	{
		info->player.x_old_direction = info->player.x_dir;
		info->player.x_dir = info->player.x_dir *\
			cos(-info->player.turn_rate) - info->player.y_dir *\
			sin(-info->player.turn_rate);
		info->player.y_dir = info->player.x_old_direction *\
			sin(-info->player.turn_rate) + info->player.y_dir *\
			cos(-info->player.turn_rate);
		info->player.x_old_plane = info->player.x_plane;
		info->player.x_plane = info->player.x_plane *\
			cos(-info->player.turn_rate) - info->player.y_plane *\
			sin(-info->player.turn_rate);
		info->player.y_plane = info->player.x_old_plane *\
			sin(-info->player.turn_rate) + info->player.y_plane *\
			cos(-info->player.turn_rate);
		info->player.turn_right = 0;
	}
	turn_left(info);
}

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
		put_text(info, write_text(str, size.y / 1.95),
				start.x + 5, start.y + 15);
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
	if (info->game == 1)
	{
		SDL_ShowCursor(SDL_DISABLE);
		info->player.turn_right = 1;
		info->player.turn_left = 1;
		info->player.turn_rate = -event.motion.xrel * 0.002;
		info->player.turn_rate_y = event.motion.yrel * 0.002;
		SDL_WarpMouseInWindow(info->win.win, WIDTH / 2, HEIGHT / 2);
		info->raycast = 1;
		turn_right(info);
	}
	else if (info->game == 2)
	{

	}
	else
		while (++i <= 4)
			load_button(info, i, event);
}

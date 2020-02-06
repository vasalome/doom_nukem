/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_button_event.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/03 19:12:05 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 12:29:45 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include_doom/doom.h"

void			mouse_button_down(t_info *info, SDL_Event event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		if (info->button == 0 && info->game != 2 && info->game != 3)
		{
			info->game = 1;
			//SDL_ShowCursor(SDL_DISABLE);
			//SDL_WarpMouseInWindow(info->win.win, WIDTH / 2, HEIGHT / 2);
			init_items(info);
		}
		else if (info->button == 1 && info->game != 2)
			info->game = 3;
		else
			shot(info);
    }
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		info->item.key += 1;
    	info->player.life -= 10;
		printf("CLICK RIGHT\n");
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		
	}
}

void			mouse_button_up(t_info *info, SDL_Event event)
{

}

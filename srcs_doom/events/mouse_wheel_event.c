/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_wheel_event.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/04 12:33:19 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 12:37:23 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include_doom/doom.h"

void		mouse_wheel_event(t_info *info, SDL_Event event)
{
	if (info->game == 3)
	{
		if (event.wheel.y > 0)
		    if (info->zoom < 3)
		        info->zoom += 0.1;
		else if (event.wheel.y < 0)
		    if (info->zoom > 0.2)
		        info->zoom -= 0.1;
	}
	/*if (event.wheel.y > 0)
        printf("CLICK WHEELUP\n");
    //printf("event.wheel.y 111111-> %d\n", event.wheel.y);
    if (event.wheel.y < 0)
        printf("CLICK WHEELDOWN\n");*/
    //printf("event.wheel.y 222222-> %d\n", event.wheel.y);
}

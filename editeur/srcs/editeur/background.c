/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   background.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 14:08:24 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 14:08:43 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

void		background_menu(t_env *v)
{
	int		i;
	int		j;

	j = -1;
	SDL_SetRenderTarget(v->ren, v->back_menu);
	while (++j < HEIGHT)
	{
		i = WIDTH - 30 * 7 + 1;
		while (++i < WIDTH)
			pixel_put(v, i, j, make_rgb(204, 203, 205, 255));
	}
	while (++j < HEIGHT && !(j = -1))
	{
		i = -1;
		while (++i < WIDTH - 30 * 7)
			pixel_put(v, i, j, make_rgb(204, 203, 205, 255));
	}
	SDL_SetRenderTarget(v->ren, NULL);
}

void		background_map(t_env *v)
{
	int		j;
	int		i;

	j = -1;
	SDL_SetRenderTarget(v->ren, v->back);
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH - 30 * 7)
			pixel_put(v, i, j, make_rgb(191, 190, 193, 255));
	}
	SDL_SetRenderTarget(v->ren, NULL);
}

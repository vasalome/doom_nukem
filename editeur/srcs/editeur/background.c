/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   background.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 14:08:24 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 17:06:18 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

void		background_menu(t_env *v)
{
	int		i;
	int		j;

	j = -1;
	while (++j < v->h)
	{
		i = v->w - 30 * 7 + 1;
		while (++i < v->w)
			pixel_put(v, i, j, (t_rgb){204, 203, 205, 255});
	}
	while (++j < v->h && !(j = -1))
	{
		i = -1;
		while (++i < v->w - 30 * 7)
			pixel_put(v, i, j, (t_rgb){204, 203, 205, 255});
	}
}

void		background_map(t_env *v)
{
	int		j;
	int		i;

	j = -1;
	while (++j < v->h)
	{
		i = -1;
		while (++i < v->w - 30 * 7)
			pixel_put(v, i, j, (t_rgb){191, 190, 193, 255});
	}
}

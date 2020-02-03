/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   button_window.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/03 13:53:08 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 15:11:42 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

static void		button_window_2(SDL_Event e, t_env *v)
{
	if (button_is_between(e, (t_between){420, 455, 370, 395}))
		v->button = 1;
	else if (button_is_between(e, (t_between){420, 458, 420, 458}))
		v->button = 2;
	else if (button_is_between(e, (t_between){520, 558, 370, 398}))
		v->button = 3;
	else if (button_is_between(e, (t_between){520, 558, 420, 458}))
		v->button = 4;
	else if (button_is_between(e, (t_between){620, 658, 370, 398}))
		v->button = 5;
	else if (button_is_between(e, (t_between){620, 658, 420, 458}))
		v->button = 6;
	else if (button_is_between(e, (t_between){720, 758, 370, 398}))
		v->button = 7;
	else if (button_is_between(e, (t_between){720, 758, 420, 458}))
		v->button = 8;
}

void			button_window(SDL_Event e, t_env *v)
{
	if (button_is_between(e, (t_between){804, 820, 282, 298}))
		v->valid = 1;
	if (button_is_between(e, (t_between){790, 820, 490, 522}))
		if (v->form == 1 && v->nb_wall < 4)
		{
			v->nb_wall++;
			v->button = 1;
		}
	if (button_is_between(e, (t_between){360, 390, 490, 522}))
		if (v->form == 1 && v->nb_wall > 1)
		{
			v->nb_wall--;
			v->button = 1;
		}
	button_window_2(e, v);
}

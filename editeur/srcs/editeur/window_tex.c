/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window_tex.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/27 17:28:48 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 19:44:48 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

void        make_window(t_env *v)
{
	int		x;
	int		y;

	y = 280;
	x = 350;
	drawline((t_point){x, y}, (t_point){x, 520}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){351, y}, (t_point){351, 520}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){352, y}, (t_point){352, 520}, (t_rgb){0, 0, 0, 255}, v);	
	drawline((t_point){x, y}, (t_point){820, y}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){x, 281}, (t_point){820, 281}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){x, 282}, (t_point){820, 282}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){820, 520}, (t_point){820, y}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){821, 520}, (t_point){821, y}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){822, 520}, (t_point){822, y}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){x, 520}, (t_point){822, 520}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){x, 521}, (t_point){822, 521}, (t_rgb){0, 0, 0, 255}, v);
	drawline((t_point){x, 522}, (t_point){822, 522}, (t_rgb){0, 0, 0, 255}, v);
	y = 282;
	while (++y < 520)
	{
		x = 352;
		while (++x < 820)
			pixel_put(v, x, y, (t_rgb){217, 217, 217, 255});
	}
	make_picture_tga(v, (t_start){803, 284}, 16, "./srcs/images/quit.tga");
}

// void		make_tex(t_env *v)
// {
// 	//put_picture();
// }

void		open_window(t_env *v)
{
	make_window(v);
	
}

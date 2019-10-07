/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw_wall.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/19 14:22:18 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 14:51:40 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/wolf.h"

void	draw_wall_plus(int x, int draw_start, t_info *info, int tex_y)
{
	info->fps.data[x * 4 + 4 * WIDTH * draw_start] =\
		(char)info->wt[info->w_j].data[info->wt[info->w_j].tex_x * 4 + 4 *\
		info->wt[info->w_j].xhud * tex_y];
	info->fps.data[x * 4 + 4 * WIDTH * draw_start + 1] =\
		(char)info->wt[info->w_j].data[info->wt[info->w_j].tex_x * 4 + 4 *\
		info->wt[info->w_j].xhud * tex_y + 1];
	info->fps.data[x * 4 + 4 * WIDTH * draw_start + 2] =\
		(char)info->wt[info->w_j].data[info->wt[info->w_j].tex_x * 4 + 4 *\
		info->wt[info->w_j].xhud * tex_y + 2];
	info->fps.data[x * 4 + 4 * WIDTH * draw_start + 3] = (char)0;
}

void	draw_wall(int x, int draw_start, int draw_end, t_info *info)
{
	int		y;
	int		d;
	int		tex_y;

	y = -1;
	while (++y <= draw_start)
		info->fps.data[x * 4 + 4 * WIDTH * y + 3] = (char)255;
	while (++draw_start <= draw_end)
	{
		d = draw_start * 256 - info->win.h * 128 + info->wall.line_height * 128;
		tex_y = ((d * info->wt[info->w_j].yhud) / info->wall.line_height) / 256;
		draw_wall_plus(x, draw_start, info, tex_y);
	}
	y = draw_start - 5;
	while (++y < info->win.h)
	{
		info->fps.data[x * 4 + 4 * WIDTH * y] = (char)120;
		info->fps.data[x * 4 + 4 * WIDTH * y + 1] = (char)120;
		info->fps.data[x * 4 + 4 * WIDTH * y + 2] = (char)120;
		info->fps.data[x * 4 + 4 * WIDTH * y + 3] = (char)0;
	}
}

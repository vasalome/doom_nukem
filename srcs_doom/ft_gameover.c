/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_gameover.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:35:35 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 18:03:18 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

/*void	create_flash(t_info *info)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	info->flash.img = mlx_new_image(info->win.mlx, WIDTH, HEIGHT);
	info->flash.data = mlx_get_data_addr(info->flash.img, &info->flash.bpp,\
			&info->flash.sizeline, &info->flash.endian);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			info->flash.data[x * 4 + 4 * WIDTH * y] = (char)255;
			info->flash.data[x * 4 + 4 * WIDTH * y + 1] = (char)255;
			info->flash.data[x * 4 + 4 * WIDTH * y + 2] = (char)255;
			info->flash.data[x * 4 + 4 * WIDTH * y + 3] = (char)125;
			x++;
		}
		y++;
	}
}

void	flash(t_info *info)
{
	create_flash(info);
	mlx_put_image_to_window(info->win.mlx, info->win.win,\
		info->flash.img, 0, 0);
	ray_casting(info);
}*/

void	game_over(t_info *info)
{
	//void	*img;
	//int		w;
	//int		h;
	int		x;
	int		y;

	y = 0;
	//img = mlx_xpm_file_to_image(info->win.mlx, "img/game_over_p.xpm", &w, &h);
	//create_img(info);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			/*info->fps.data[x * 4 + 4 * WIDTH * y] = (char)27;
			info->fps.data[x * 4 + 4 * WIDTH * y + 1] = (char)27;
			info->fps.data[x * 4 + 4 * WIDTH * y + 2] = (char)205;
			info->fps.data[x * 4 + 4 * WIDTH * y + 3] = (char)0;*/
			x++;
		}
		y++;
	}
	/*mlx_put_image_to_window(info->win.mlx, info->win.win, info->fps.img, 0, 0);
	mlx_put_image_to_window(info->win.mlx, info->win.win,
			img, WIDTH / 2 - w / 2, HEIGHT / 2 - h / 2);*/
}

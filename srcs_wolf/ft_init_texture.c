/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_texture.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/19 14:00:48 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 19:16:44 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/wolf.h"

void	textures_door_2(t_info *info)
{
	info->wt[12].img = IMG_Load("wall/fac_a-light.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"wall/4/door-c.xpm", &info->wt[12].xhud, &info->wt[12].yhud);
	info->wt[12].data = mlx_get_data_addr(info->wt[12].img, &info->wt[12].bpp,\
		&info->wt[12].sizeline, &info->wt[12].endian);*/
	info->wt[13].img = IMG_Load("wall/fac_a-light.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"wall/4/door-a.xpm", &info->wt[13].xhud, &info->wt[13].yhud);
	info->wt[13].data = mlx_get_data_addr(info->wt[13].img, &info->wt[13].bpp,\
		&info->wt[13].sizeline, &info->wt[13].endian);*/
	info->wt[14].img = IMG_Load("wall/fac_a-light.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"wall/4/door-bd.xpm", &info->wt[14].xhud, &info->wt[14].yhud);
	info->wt[14].data = mlx_get_data_addr(info->wt[14].img, &info->wt[14].bpp,\
		&info->wt[14].sizeline, &info->wt[14].endian);*/
	info->wt[15].img = IMG_Load("wall/fac_a-light.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"wall/4/door-bd.xpm", &info->wt[15].xhud, &info->wt[15].yhud);
	info->wt[15].data = mlx_get_data_addr(info->wt[15].img, &info->wt[15].bpp,\
		&info->wt[15].sizeline, &info->wt[15].endian);*/
}

void	textures_door_1(t_info *info)
{
	info->wt[4].img = IMG_Load("wall/fac_a-light.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"wall/3/door_b-c.xpm", &info->wt[4].xhud, &info->wt[4].yhud);
	info->wt[4].data = mlx_get_data_addr(info->wt[4].img, &info->wt[4].bpp,\
		&info->wt[4].sizeline, &info->wt[4].endian);*/
	info->wt[5].img = IMG_Load("wall/fac_a-light.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"wall/3/door_b-a.xpm", &info->wt[5].xhud, &info->wt[5].yhud);
	info->wt[5].data = mlx_get_data_addr(info->wt[5].img, &info->wt[5].bpp,\
		&info->wt[5].sizeline, &info->wt[5].endian);*/
	info->wt[6].img = IMG_Load("wall/fac_a-light.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"wall/3/door_b-bd.xpm", &info->wt[6].xhud, &info->wt[6].yhud);
	info->wt[6].data = mlx_get_data_addr(info->wt[6].img, &info->wt[6].bpp,\
		&info->wt[6].sizeline, &info->wt[6].endian);*/
	info->wt[7].img = IMG_Load("wall/fac_a-light.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"wall/3/door_b-bd.xpm", &info->wt[7].xhud, &info->wt[7].yhud);
	info->wt[7].data = mlx_get_data_addr(info->wt[7].img, &info->wt[7].bpp,\
		&info->wt[7].sizeline, &info->wt[7].endian);*/
}

void	textures_wall_2(t_info *info)
{
	info->wt[8].img = IMG_Load("wall/fac_a-light.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"wall/2/face_c-2.xpm", &info->wt[8].xhud, &info->wt[8].yhud);
	info->wt[8].data = mlx_get_data_addr(info->wt[8].img, &info->wt[8].bpp,\
		&info->wt[8].sizeline, &info->wt[8].endian);*/
	info->wt[9].img = IMG_Load("wall/fac_a-light.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"wall/2/face_a-2.xpm", &info->wt[9].xhud, &info->wt[9].yhud);
	info->wt[9].data = mlx_get_data_addr(info->wt[9].img, &info->wt[9].bpp,\
		&info->wt[9].sizeline, &info->wt[9].endian);*/
	info->wt[10].img = IMG_Load("wall/fac_a-light.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"wall/2/face_bd-2.xpm", &info->wt[10].xhud, &info->wt[10].yhud);
	info->wt[10].data = mlx_get_data_addr(info->wt[10].img, &info->wt[10].bpp,\
		&info->wt[10].sizeline, &info->wt[10].endian);*/
	info->wt[11].img = IMG_Load("wall/fac_a-light.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"wall/2/face_bd-2.xpm", &info->wt[11].xhud, &info->wt[11].yhud);
	info->wt[11].data = mlx_get_data_addr(info->wt[11].img, &info->wt[11].bpp,\
		&info->wt[11].sizeline, &info->wt[11].endian);*/
}

void	textures_wall_1(t_info *info)
{
	info->wt[0].img = IMG_Load("wall/fac_a-light.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"wall/1/face_c.xpm", &info->wt[0].xhud, &info->wt[0].yhud);
	info->wt[0].data = mlx_get_data_addr(info->wt[0].img, &info->wt[0].bpp,\
		&info->wt[0].sizeline, &info->wt[0].endian);*/
	info->wt[1].img = IMG_Load("wall/fac_a-light.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"wall/1/face_a.xpm", &info->wt[1].xhud, &info->wt[1].yhud);
	info->wt[1].data = mlx_get_data_addr(info->wt[1].img, &info->wt[1].bpp,\
		&info->wt[1].sizeline, &info->wt[1].endian);*/
	info->wt[2].img = IMG_Load("wall/fac_a-light.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"wall/1/face_b.xpm", &info->wt[2].xhud, &info->wt[2].yhud);
	info->wt[2].data = mlx_get_data_addr(info->wt[2].img, &info->wt[2].bpp,\
		&info->wt[2].sizeline, &info->wt[2].endian);*/
	info->wt[3].img = IMG_Load("wall/fac_a-light.png");/*mlx_xpm_file_to_image(info->win.mlx,\
		"wall/1/face_d.xpm", &info->wt[3].xhud, &info->wt[3].yhud);
	info->wt[3].data = mlx_get_data_addr(info->wt[3].img, &info->wt[3].bpp,\
		&info->wt[3].sizeline, &info->wt[3].endian);*/
}

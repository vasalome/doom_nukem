/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_texture.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/19 14:00:48 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/11 11:11:09 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	textures_door_2(t_info *info)
{
	info->wt[12].img = IMG_Load("wall/4/door-c.png");
	info->wt[13].img = IMG_Load("wall/4/door-a.png");
	info->wt[14].img = IMG_Load("wall/4/door-bd.png");
	info->wt[15].img = IMG_Load("wall/4/door-bd.png");
}

void	textures_door_1(t_info *info)
{
	/*info->wt[4].img = IMG_Load("wall/bars.png");
	info->wt[5].img = IMG_Load("wall/bars.png");
	info->wt[6].img = IMG_Load("wall/bars.png");
	info->wt[7].img = IMG_Load("wall/bars.png");*/
	info->wt[4].img = IMG_Load("wall/3/door_b-c.png");
	info->wt[5].img = IMG_Load("wall/3/door_b-a.png");
	info->wt[6].img = IMG_Load("wall/3/door_b-bd.png");
	info->wt[7].img = IMG_Load("wall/3/door_b-bd.png");
}

void	textures_wall_2(t_info *info)
{					
	info->wt[8].img = IMG_Load("wall/jojo.png");
	info->wt[9].img = IMG_Load("wall/jojo.png");
	info->wt[10].img = IMG_Load("wall/jojo.png");
	info->wt[11].img = IMG_Load("wall/cheh.png");
	
	/*info->wt[8].img = IMG_Load("wall/2/face_c-2.png");
	info->wt[9].img = IMG_Load("wall/2/face_a-2.png");
	info->wt[10].img = IMG_Load("wall/2/face_bd-2.png");
	info->wt[11].img = IMG_Load("wall/2/face_bd-2.png");*/
}

void	textures_wall_1(t_info *info)
{
	info->wt[0].img = IMG_Load("wall/floor2.png");
	info->wt[1].img = IMG_Load("wall/floor2.png");
	info->wt[2].img = IMG_Load("wall/floor2.png");
	info->wt[3].img = IMG_Load("wall/floor2.png");
	
	/*info->wt[0].img = IMG_Load("wall/1/face_c.png");
	info->wt[1].img = IMG_Load("wall/1/face_a.png");
	info->wt[2].img = IMG_Load("wall/1/face_b.png");
	info->wt[3].img = IMG_Load("wall/1/face_d.png");*/
}

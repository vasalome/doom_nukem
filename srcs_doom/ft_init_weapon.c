/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_weapon.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/19 13:56:47 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 15:22:19 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	weapons(t_info *info)
{
	info->wp[0].img = IMG_Load("weapons/fist/fist_1.png");
	info->wp[1].img = IMG_Load("weapons/fist/fist_1.png");
	info->wp[2].img = IMG_Load("weapons/fist/fist_1.png");
	info->wp[3].img = IMG_Load("weapons/fist/fist_1.png");
	info->wp[4].img = IMG_Load("weapons/fist/fist_1.png");
	info->wp[5].img = IMG_Load("weapons/fist/fist_1.png");
	info->wp[6].img = IMG_Load("weapons/fist/fist_1.png");
	info->wp[7].img = IMG_Load("weapons/fist/fist_1.png");
	info->wp[8].img = IMG_Load("weapons/fist/fist_1.png");
	info->wp[9].img = IMG_Load("weapons/fist/fist_1.png");
	info->wp[10].img = IMG_Load("weapons/fist/fist_1.png");
}

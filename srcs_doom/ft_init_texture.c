/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_texture.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/19 14:00:48 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 23:20:02 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	textures_list(t_info *info)
{
	info->wt[0].img = IMG_Load("wall/scpwall.png");
	info->wt[1].img = IMG_Load("wall/scpwall3.png");
	info->wt[2].img = IMG_Load("wall/scpwall3-1.png");
	info->wt[3].img = IMG_Load("wall/scpwall3.png");
	info->wt[4].img = IMG_Load("wall/floor2.png");
	// info->wt[5].img = IMG_Load("wall/map_pillar.png");
	// info->wt[6].img = ;
	// info->wt[7].img = ;
	// info->wt[8].img = ;
	// info->wt[9].img = ;
	// info->wt[10].img = ;
	// info->wt[11].img = ;
	// info->wt[12].img = ;
	// info->wt[13].img = ;
	// info->wt[14].img = ;
	// info->wt[15].img = ;
	info->wt[16].img = IMG_Load("wall/scpfloor2.png");
	info->wt[17].img = IMG_Load("wall/scpfloor.png");
	info->wt[18].img = IMG_Load("wall/transparent.png");
	// info->wt[19].img = ;

	// 20 a 30 dans skybox pour l'instant
	// info->wt[20].img = ;
	// info->wt[21].img = ;
	// info->wt[22].img = ;
	// info->wt[23].img = ;
	// info->wt[24].img = ;
	// info->wt[25].img = ;
	// info->wt[26].img = ;
	// info->wt[27].img = ;
	// info->wt[28].img = ;
	// info->wt[29].img = ;
	// info->wt[30].img = ;

}

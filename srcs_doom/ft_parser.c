/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parser.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:40:07 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/11 15:00:34 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

int		parser(t_info *info)
{
	...
gnl

	case_type(fill[i][0]);
	if (fill[i][1] == '1')
		colision(fill[i][1]);
	if (fill[i][2] == '1')
		ray_passe ; ?
	height_floor(fill[i][3]);
	if (fill[i][4] == '1')
		roof(fill[i][5]);
	textures_wall(fill[i][6],fill[i][7],fill[i][8],fill[i][9]);
	if (fill[i][10] == '1')
		teleport(fill[i][11]);
	if (fill[i][12] != '0')
		music(fill[i][12]);
	if (fill[i][13] != '0')
	{
		if (fill[i][13] == '2')
			action interaction ?
	}
	
}

	// idee formatage parsing
	 [1,0,1,1.25,1,2.25,N,E,S,O,1,10 11 A,1,1]
	// [fill[i][0],fill[i][1],fill[i][2],fill[i][3],fill[i][4],fill[i][5],.....]


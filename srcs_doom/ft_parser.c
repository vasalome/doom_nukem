/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parser.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:40:07 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/12 19:50:05 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	check_inside(type variable)
{
	int		i;
	int		count;
	i = -1;
	count = 0;

	while (variable[++i])
		if (variable[i] == ',')
			count++;
	if (count != 13)
		ft_usage('Invalid case:'variable);
}

static int	inside(type variable, int i)
{
	int	
	check_inside();
	while (variable[*i] != ',')
		if (!(variable[*i] >= '1' && variable[*i] <= 'ID MAX DES MURS'))
			ft_usage('Invalid case:'variable);
	{
		
	}
	
}



static int	parser(?? variable ??)
{
	int		i;
	int		top;
	int		buff[BUFF_SIZE];

	i = -1;
	top = 0;
	while (variable[++i])
	{
		if (variable[i] == '[')
			buff[++top] = variable[i];
		if (variable[i] == ']')
			if (!inside(buff[top--], variable[i]))
				return (-1);
	}


-----------------


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


/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fill_map.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:40:07 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 17:30:27 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

/*
int		pars_bin(t_fillmap *fill, t_info *info)
{
	info->map.map[fill->x][fill->y].wall = request_bin(fill, 1); //need to code request_bin pour recuperer le binaire d'un fichier

	
	
	while (fill->line[fill->i] != ')')
		fill->i++;
	
	fill->x++;
	return(0);
}*/

int		request_value(t_fillmap *fill, int x)
{
	int i;
	int	count;
	int	ret;

	i = fill->i;
	count = 0;
	ret = 0;
	x--;
	while (count != x)
	{
		if(fill->line[i++] == ',')
			count++;
	}
	while (fill->line[i] < '0' || fill->line[i] > '9')
		i++;
	while (fill->line[i] >= '0' && fill->line[i] <= '9')
	{
		ret *= 10;
		ret += fill->line[i] - 48;
		i++;
	}
	return (ret);
}

int		parsing(t_fillmap *fill, t_info *info)
{
	info->map.map[fill->x][fill->y].wall = request_value(fill, 1);
	info->map.map[fill->x][fill->y].ceilTexId = request_value(fill, 2);
	info->map.map[fill->x][fill->y].floorTexId = request_value(fill, 3);
	
	info->map.map[fill->x][fill->y].e_tex = 0; //est
	info->map.map[fill->x][fill->y].s_tex = 0; //sud
	info->map.map[fill->x][fill->y].n_tex = 0; //nord
	info->map.map[fill->x][fill->y].w_tex = 0; //ouest

	info->map.map[fill->x][fill->y].e_tex = request_value(fill, 4); //est
	info->map.map[fill->x][fill->y].s_tex = request_value(fill, 5); //sud
	info->map.map[fill->x][fill->y].n_tex = request_value(fill, 6); //nord
	info->map.map[fill->x][fill->y].w_tex = request_value(fill, 7); //ouest
	info->map.map[fill->x][fill->y].clip = request_value(fill, 8); // cliping
	if (request_value(fill, 9) == 1)// teleport
	{
		info->map.map[fill->x][fill->y].tp = request_value(fill, 9);
		info->map.map[fill->x][fill->y].tp_x = request_value(fill, 10);
		info->map.map[fill->x][fill->y].tp_y = request_value(fill, 11);
	}
	info->map.map[fill->x][fill->y].wall_h = (request_value(fill, 12)); // alpha
	info->map.map[fill->x][fill->y].sp = request_value(fill, 13); // sprites
	//info->map.map[fill->x][fill->y]. = ; //

	while (fill->line[fill->i] != ']')
		fill->i++;
	fill->x++;
	return(0);
}

int		read_map(t_info *info, t_fillmap *fill)
{
	int			ret;

	while ((ret = ft_get_next_line(fill->fd, &fill->line)))
	{
		fill->x = 0;
		fill->i = 0;
		while (fill->line[fill->i] != '\0')
		{
			if (fill->line[fill->i] == '[')
				parsing(fill, info);
				/* preparation du parsing des fichiers
			if (fill->line[fill->i] == '(')
				pars_bin(fill, info);
				*/
			fill->i++;
		}
		ft_strdel(&fill->line);
		fill->y++;
		//printf("\n");
	}
	if (ret == -1)
		return (-1);
	return (0);
}

int		fill_map(t_info *info)
{
	t_fillmap	fill;

	fill.i = 0;
	fill.x = 0;
	fill.y = 0;
	fill.j = 0;
	fill.line = NULL;
	if (!(fill.fd = open(info->map.name, O_RDONLY)))
		return (-1);
	if (read_map(info, &fill) == -1)
		return (-1);
	return (0);
}

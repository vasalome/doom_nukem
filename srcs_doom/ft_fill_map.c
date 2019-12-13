/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fill_map.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:40:07 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 17:32:29 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	fill_map_plus(t_fillmap *fill, t_info *info)
{
	if (fill->line[fill->i] == '0' || fill->line[fill->i] == '1'
	|| fill->line[fill->i] == '2' || fill->line[fill->i] == '3'
	|| fill->line[fill->i] == '4' || fill->line[fill->i] == '5'
	|| fill->line[fill->i] == '6' || fill->line[fill->i] == '7'
	|| fill->line[fill->i] == '8')
		info->use = fill->line[fill->i];
	if (fill->line[fill->i] == '3');
		//tp_destination(fill, info, fill->line, &fill->i);
}

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
	// type de case
	info->map.map[fill->x][fill->y].wall = request_value(fill, 1);
	// tex plafond
	info->map.map[fill->x][fill->y].ceilTexId = request_value(fill, 2);
	// tex sol
	info->map.map[fill->x][fill->y].floorTexId = request_value(fill, 3);
	// tex mur  !!  !!
	
	info->map.map[fill->x][fill->y].e_tex = 0; //est
	info->map.map[fill->x][fill->y].s_tex = 0; //sud
	info->map.map[fill->x][fill->y].n_tex = 0; //nord
	info->map.map[fill->x][fill->y].w_tex = 0;

	info->map.map[fill->x][fill->y].e_tex = request_value(fill, 4); //est
	info->map.map[fill->x][fill->y].s_tex = request_value(fill, 5); //sud
	info->map.map[fill->x][fill->y].n_tex = request_value(fill, 6); //nord
	info->map.map[fill->x][fill->y].w_tex = request_value(fill, 7); //ouest
	/*printf("EST: %d\nSUD: %d\nNORD: %d\nOUEST: %d\n---------------\n",\
		info->map.map[fill->x][fill->y].e_tex,\
		info->map.map[fill->x][fill->y].s_tex,\
		info->map.map[fill->x][fill->y].n_tex,\
		info->map.map[fill->x][fill->y].w_tex);*/
	//cliping
	//info-> ?? = request_value(fill, 8); 
	// teleport
	if (request_value(fill, 9) == 1)
	{
		info->map.map[fill->x][fill->y].gg = request_value(fill, 9);
		info->map.map[fill->x][fill->y].tp_x = request_value(fill, 10);
		info->map.map[fill->x][fill->y].tp_y = request_value(fill, 11);
	}

	info->map.map[fill->x][fill->y].wall_h = (request_value(fill, 12));


	//printf("%d ", info->map.map[fill->x][fill->y].wall);
	while (fill->line[fill->i] != ']')
		fill->i++;
	//printf("wall x = %d y = %d -----> %d\n\n", fill->x - 1, fill->y, info->map.map[fill->x][fill->y].wall);
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
			//fill_map_plus(fill, info);
			if (fill->line[fill->i] == '[')
				parsing(fill, info);
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

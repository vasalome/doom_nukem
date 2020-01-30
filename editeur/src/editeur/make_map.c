/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 14:07:12 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 15:02:39 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

void		free_tab(t_env *v, t_map **tab)
{
	int		i;

	i = -1;
	while (++i < v->h / v->cases)
		free(tab[i]);
	free(tab);
}

void		make_map(t_env *v)
{
	int		i;
	int		j;

	j = -1;
	if (!(v->tab = malloc(sizeof(t_map *) * (v->h / v->cases))))
		return ;
	while (++j < v->h / v->cases)
	{
		i = -1;
		if (!(v->tab[j] = malloc(sizeof(t_map) * ((v->w - v->cases * 7)
				/ v->cases))))
			return ;
		while (++i < (v->w - v->cases * 7) / v->cases)
		{
			v->tab[j][i].case_x = i;
			v->tab[j][i].case_y = j;
			v->tab[j][i].form = 0;
			v->tab[j][i].texture = v->chosen_tex;
		}
	}
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_env.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 16:04:37 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 17:38:09 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

void			free_tab(t_env *v, t_map **tab)
{
	int			i;

	i = -1;
	while (++i < v->h / v->cases)
		free(tab[i]);
	free(tab);
}

static void		free_sur_img(SDL_Surface **sur, int nb)
{
	int			i;

	i = -1;
	while (++i < nb)
		SDL_FreeSurface(sur[i]);
}

static void		free_tga_img(t_tga **tga, int nb)
{
	int			i;

	i = -1;
	while (++i < nb)
		free(tga[i]);
}

void			free_env(t_env *v)
{
	if (v)
	{
		free_tab(v, v->tab);
		free(v->pixels);
		free_sur_img(v->wall, 8);
		free_sur_img(v->floor, 2);
		free_sur_img(v->img, 6);
		free_tga_img(v->tga, 2);
		free(v);
	}
}

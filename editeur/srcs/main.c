/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 15:26:14 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 15:29:57 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/editeur.h"

void		init(t_env *env)
{
	if (SDL_Init(SDL_INIT_VIDEO))
		ft_error("Couldn't initialize SDL");
	if (!(env->win = SDL_CreateWindow("wolf3d", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0)))
		ft_error("Could not create the window");
	if (!(env->ren = SDL_CreateRenderer(env->win, -1, SDL_RENDERER_SOFTWARE)))
		ft_error("Could not create a renderer");
}

// void			editeur_setup(t_env *v)
// {
	
// }

// static t_lst	*ft_lst_new(int x, int y)
// {
// 	t_lst		*elem;

// 	if (!(elem = (t_lst *)malloc(sizeof(t_lst))))
// 		return (NULL);
// 	elem->center_x = x;
// 	elem->center_y = y;
// 	elem->etat = 1;
// 	elem->select = 0;
// 	elem->seg = 0;
// 	elem->next = NULL;
// 	return (elem);
// }

// void			new_elem_lst(t_lst **elem, int x, int y)
// {
// 	t_lst		*new;
// 	t_lst		*tmp;

// 	new = ft_lst_new(x, y);
// 	if (*elem == NULL)
// 		*elem = new;
// 	else
// 	{
// 		tmp = *elem;
// 		while (tmp->next)
// 			tmp = tmp->next;
// 		tmp->next = new;
// 	}
// }

// void			lstdel(t_lst *lst)
// {
// 	if (lst->next)
// 		lstdel(lst->next);
// 	free(lst);
// }

void		make_map(t_env *v)
{
	int		i;
	int		j;

	j = -1;
	if (!(v->tab = malloc(sizeof(t_map *) * ((WIDTH - CASES * 5) / CASES))))
		return ;
	while (++j < (HEIGHT - CASES * 5) / CASES)
	{
		i = -1;
		if (!(v->tab[j] = malloc(sizeof(t_map) * ((WIDTH - CASES * 5) / CASES))))
			return ;
		while (++i < (WIDTH - CASES * 5) / CASES)
		{
			v->tab[j][i].case_x = i;
			v->tab[j][i].case_y = j;
		}
	}
}

void		background_menu(t_env *v)
{
	int		i;
	int		j;

	SDL_SetRenderTarget(v->ren, v->back);
	j = -1;
	while (++j < HEIGHT)
	{
		i = WIDTH - 30 * 7 + 1;
		while (++i < WIDTH)
			pixel_put(v, i, j, make_rgb(204, 203, 205, 255));
	}
	while (++j < HEIGHT && !(j = -1))
	{
		i = -1;
		while (++i < WIDTH - 30 * 7)
			pixel_put(v, i, j, make_rgb(204, 203, 205, 255));
	}
	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH - 30 * 7)
			pixel_put(v, i, j, make_rgb(191, 190, 193, 255));
	}
	SDL_SetRenderTarget(v->ren, NULL);
}

int			main(int argc, char **argv)
{
	t_env	*v;
	int		fd;

	fd = 0;
	if (!(v = ft_memalloc(sizeof(t_env))))
		return (0);
	//if (argc != 2 || (fd = open(argv[1], O_RDONLY)) < 0)
	//	return (0);
	//v->point = NULL;
	make_map(v);
	init(v);
	//editeur_setup(env);
	background_menu(v);
	display(v);
	return (0);
}
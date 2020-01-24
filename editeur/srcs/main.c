/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 15:26:14 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 12:19:05 by nrivoire    ###    #+. /#+    ###.fr     */
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

void		background_menu(t_env *v)
{
	int		i;
	int		j;

	j = -1;
	SDL_SetRenderTarget(v->ren, v->back_menu);
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
	SDL_SetRenderTarget(v->ren, NULL);
}

void		background_map(t_env *v)
{
	int		j;
	int		i;

	j = -1;
	SDL_SetRenderTarget(v->ren, v->back);
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH - 30 * 7)
			pixel_put(v, i, j, make_rgb(191, 190, 193, 255));
	}
	SDL_SetRenderTarget(v->ren, NULL);
}

void		free_tab(t_env *v, t_map **tab)
{
	int		i;

	i = -1;
	while (++i < HEIGHT / v->cases)
		free(tab[i]);
	free(tab);
}

void		make_map(t_env *v)
{
	int		i;
	int		j;

	j = -1;
	if (!(v->tab = malloc(sizeof(t_map *) * (HEIGHT / v->cases))))
		return ;
	while (++j < HEIGHT / v->cases)
	{
		i = -1;
		if (!(v->tab[j] = malloc(sizeof(t_map) * ((WIDTH - v->cases * 7) / v->cases))))
			return ;
		while (++i < (WIDTH - v->cases * 7) / v->cases)
		{
			v->tab[j][i].case_x = i;
			v->tab[j][i].case_y = j;
			v->tab[j][i].form = 0;
		}
	}
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
	argc = 1;
	(void)argv;
	v->form = 0;
	v->cases = 30;
	v->spawn_count = 0;
	make_map(v);
	init(v);
	//editeur_setup(env);
	background_map(v);
	background_menu(v);
	display(v);
	return (0);
}
/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 15:26:14 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 14:59:56 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/editeur.h"

void		init(t_env *v)
{
	if (SDL_Init(SDL_INIT_VIDEO))
		ft_error("Couldn't initialize SDL");
	if (!(v->win = SDL_CreateWindow("editeur", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, v->w, v->h, 0)))
		ft_error("Could not create the window");
	if (!(v->ren = SDL_CreateRenderer(v->win, -1, SDL_RENDERER_SOFTWARE)))
		ft_error("Could not create a renderer");
	if (!(v->tex = SDL_CreateTexture(v->ren, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STREAMING, v->w, v->h)))
		ft_error("Could not create a texture");
	if (!(v->pixels = malloc(sizeof(uint32_t) * (v->h * v->w))))
		ft_error("ALLO CA MARCHE PAS");
}

// void			editeur_setup(t_env *v)
// {
	
// }

int			main(int argc, char **argv)
{
	t_env	*v;
	int		fd;

	fd = 0;
	if (!(v = ft_memalloc(sizeof(t_env))))
		return (0);
	argc = 1;
	(void)argv;
	v->form = 0;
	v->cases = 30;
	v->spawn_count = 0;
	v->w = 1200;
	v->h = 900;
	v->window = 0;
	v->nb_wall = 1;
	v->motion = 0;
	v->button = 0;
	v->chosen_tex.est = 0;
	v->chosen_tex.sud = 0;
	v->chosen_tex.ouest = 0;
	v->chosen_tex.nord = 0;
	v->motion = 0;
	v->button = 1;
	v->plus = 0;
	make_map(v);
	init(v);
	//editeur_setup(env);
	background_map(v);
	background_menu(v);
	display(v);
	return (0);
}
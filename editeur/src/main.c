/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 15:26:14 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 11:34:53 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/editeur.h"

static void		init(t_env *v)
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
		ft_error("Pixels malloc error");
	if (TTF_Init() == -1)
		ft_error("Initialisation error of TFT_Init");
}

static void		editeur_setup(t_env *v)
{
	v->form = 0;
	v->cases = 30;
	v->spawn_count = 0;
	v->w = 1200;
	v->h = 900;
	v->window = 0;
	v->nb_wall = 1;
	v->motion = 0;
	v->button = 0;
	v->chosen_tex.est = 1;
	v->chosen_tex.sud = 1;
	v->chosen_tex.ouest = 1;
	v->chosen_tex.nord = 1;
	v->motion = 0;
	v->button = 1;
	v->plus = 0;
	v->tmp = 0;
}

static void		load_images2(t_env *v)
{
	if (!(v->floor[0] = IMG_Load("./src/tex/floor1.xpm")))
		ft_error((char*)SDL_GetError());
	if (!(v->floor[1] = IMG_Load("./src/tex/floor2.xpm")))
		ft_error((char*)SDL_GetError());
	if (!(v->img[0] = IMG_Load("./src/img/accept.xpm")))
		ft_error((char*)SDL_GetError());
	if (!(v->img[1] = IMG_Load("./src/img/door.xpm")))
		ft_error((char*)SDL_GetError());
	if (!(v->img[2] = IMG_Load("./src/img/gomme.xpm")))
		ft_error((char*)SDL_GetError());
	if (!(v->img[3] = IMG_Load("./src/img/l_arrow.xpm")))
		ft_error((char*)SDL_GetError());
	if (!(v->img[4] = IMG_Load("./src/img/r_arrow.xpm")))
		ft_error((char*)SDL_GetError());
	if (!(v->img[5] = IMG_Load("./src/img/stickman.xpm")))
		ft_error((char*)SDL_GetError());
	if (!(v->tga[0] = tga_parser("./src/img/door.tga")))
		ft_error("tga parser on door didn't work");
	if (!(v->tga[1] = tga_parser("./src/img/gomme.tga")))
		ft_error("tga parser on gomme didn't work");
}

static void		load_images(t_env *v)
{
	if (!(v->wall[0] = IMG_Load("./src/tex/wall1.xpm")))
		ft_error((char*)SDL_GetError());
	if (!(v->wall[1] = IMG_Load("./src/tex/wall2.xpm")))
		ft_error((char*)SDL_GetError());
	if (!(v->wall[2] = IMG_Load("./src/tex/wall3.xpm")))
		ft_error((char*)SDL_GetError());
	if (!(v->wall[3] = IMG_Load("./src/tex/wall4.xpm")))
		ft_error((char*)SDL_GetError());
	if (!(v->wall[4] = IMG_Load("./src/tex/wall5.xpm")))
		ft_error((char*)SDL_GetError());
	if (!(v->wall[5] = IMG_Load("./src/tex/wall6.xpm")))
		ft_error((char*)SDL_GetError());
	if (!(v->wall[6] = IMG_Load("./src/tex/wall7.xpm")))
		ft_error((char*)SDL_GetError());
	if (!(v->wall[7] = IMG_Load("./src/tex/wall8.xpm")))
		ft_error((char*)SDL_GetError());
	load_images2(v);
}

int				main(int argc, char **argv)
{
	t_env	*v;
	int		fd;

	fd = 0;
	if (!(v = ft_memalloc(sizeof(t_env))))
		return (0);
	argc = 1;
	(void)argv;
	editeur_setup(v);
	make_map(v);
	init(v);
	background_map(v);
	background_menu(v);
	load_images(v);
	display(v);
	free_env(v);
	return (0);
}

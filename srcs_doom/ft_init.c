/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:32:21 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 11:31:16 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void		init_window(t_info *info)
{
	int		img_flags;

	img_flags = IMG_INIT_PNG | IMG_INIT_JPG;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) < 0)
		ft_error("Échec de l'initialisation de la SDL");
	if (!(info->win.win = SDL_CreateWindow("Doom_Nukem", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
		ft_error("Échec de la création de la windows");
	if (!(info->win.ren = SDL_CreateRenderer(info->win.win, -1,
			SDL_RENDERER_ACCELERATED)))
		ft_error("Échec de la création du renderer");
	if (!(IMG_Init(img_flags) & img_flags))
		ft_error("Échec de l'initialisation de la SDL_image");
	if (!(info->textu = SDL_CreateTexture(info->win.ren,
			SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT)))
		ft_error("Échec de la création de la texture");
	if (!(info->pixels = malloc(sizeof(uint32_t) * (HEIGHT * WIDTH))))
		ft_error("Échec du malloc de info->pixels");
	if (TTF_Init() == -1)
		ft_error("Échec de l'initialisation de la SDL TTF");
}

void		load_textures(t_info *info)
{
	info->w_i = 0;
	info->w_j = 0;
	init_textures(info);
	init_hud(info);
}

void		init_map(t_info *info)
{
	if (set_map_size(info) == -1)
		ft_usage("Fichier corrompu !");
	create_map(info);
	if (fill_map(info) == -1)
		ft_usage("Fichier corrompu !");
	get_spawn(info);
}

void		init_player(t_info *info)
{
	info->player.x_pos = info->map.x_spawn;
	info->player.y_pos = info->map.y_spawn;
	info->player.height = 1;
	info->player.x_dir = -1;
	info->player.y_dir = 0;
	info->player.x_plane = 0;
	info->player.y_plane = 0.66;
	info->player.move_down = 0;
	info->player.move_up = 0;
	info->player.move_left = 0;
	info->player.move_right = 0;
	info->player.turn_left = 0;
	info->player.turn_right = 0;
	info->player.turn_rate = 0.1;
	info->player.turn_rate_y = 0.1;
	info->player.fov = 2;
	info->player.move_speed = 0.05;
	info->player.tp_index = 0;
	info->player.life = 100;
	info->player.can_trap = 1;
	info->floor.texId = 9;
	info->floor.texId2 = 10;
}

void		init_doors(t_info *info)
{
	int		i;
	int		j;

	i = -1;
	if (!(info->map.door_state = (int**)malloc(sizeof(int*) * info->map.width)) ||
		!(info->map.door_offset = (double**)malloc(sizeof(double*) * info->map.width)))
		return ;
	while (++i < info->map.width)
	{
		if (!(info->map.door_state[i] = (int*)malloc(sizeof(int) * info->map.height)))
			return ;
		if (!(info->map.door_offset[i] = (double*)malloc(sizeof(double) * info->map.height)))
			return ;
	}
	i = -1;
	while (++i < info->map.width)
	{
		j = -1;
		while (++j < info->map.height)
		{
			info->map.door_state[i][j] = 0;
			info->map.door_offset[i][j] = 0;
		}
	}
}

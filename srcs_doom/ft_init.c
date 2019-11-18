/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:32:21 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 16:35:29 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

/*
** Initate default variables when game start
*/

void	init_player(t_info *info)
{
	info->player.x_pos = info->map.x_spawn;
	info->player.y_pos = info->map.y_spawn;
	info->player.height = 65;
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
	info->player.life = 11;
	info->player.can_trap = 1;
}

void	init_map(t_info *info)
{
	if (set_map_size(info) == -1)
		ft_usage("Fichier corrompu !");
	create_map(info);
	if (fill_map(info) == -1)
		ft_usage("Fichier corrompu !");
	get_spawn(info);
}

void	load_textures(t_info *info)
{
	info->w_i = 0;
	info->w_j = 0;
	weapons(info);
	hub_life(info);
	textures_wall_1(info);
	textures_wall_2(info);
	textures_door_1(info);
	textures_door_2(info);
	textures_floor(info);
}

void	init_window(t_info *info)
{
	info->win.w = WIDTH;
	info->win.h = HEIGHT;
	
	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
	
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) < 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
    }
	else
	{
		info->win.win = SDL_CreateWindow("Ma première application SDL2",
                                          	SDL_WINDOWPOS_CENTERED,
                                          	SDL_WINDOWPOS_CENTERED,
                                                                	info->win.w,
                                                                  	info->win.h,
                                                                  	SDL_WINDOW_SHOWN/* | SDL_WINDOW_FULLSCREEN*/);
																  
		info->win.renderer = SDL_CreateRenderer(info->win.win, -1, SDL_RENDERER_ACCELERATED);
		SDL_SetRenderDrawColor( info->win.renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	}
	
	if	(!(IMG_Init(imgFlags) & imgFlags))
	{
		printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", IMG_GetError() );
	}
}

void	init_music(t_info *info)
{
	info->music.sound = Mix_LoadMUS("music/scream.wav");
	info->music.high = Mix_LoadWAV("music/scream.wav");
	info->music.low = Mix_LoadWAV("music/elevator.wav");
	
}

void	init(t_info *info)
{
	info->shot = 1;
	info->action = 0;
	init_window(info);
	load_textures(info);
	init_map(info);
	init_player(info);
	init_music(info);
	icon(info);
	ray_casting_image(info);
}

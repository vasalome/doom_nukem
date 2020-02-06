/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_doom.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 17:53:57 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 11:37:50 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

// /* Fonction de callback (sera appelée toutes les 30 ms) */
// Uint32 frameDisplay(Uint32 intervalle, void *parametre)
// {
//     t_info *info = parametre;
//     //printf("%d FPS\n", info->frame);
//     info->frame = 0;
//     return intervalle;
// }

static void		init_info(t_info *info, char **argv)
{
    info->map.name = argv[1];
    info->frame = 0;
    info->i = 0;
    info->iii = 10;
    info->ii = 10;
    info->quit = 0;
    info->door = 0;
    info->game = 0;
    // info->fps.rect.x = 0;
    // info->fps.rect.y = -200;
    // info->fps.rect.w = WIDTH;
    // info->fps.rect.h = HEIGHT + 400;
    info->testHeight = 0;
    info->player.head = 1;
    info->shot = 1;
	info->action = 0;
}

int				main(int argc, char **argv)
{
	t_info		info;

	if (argc != 2)
		ft_usage("Mauvais nombre d'arguments !");
	init_info(&info, argv);
	init_window(&info);
	load_textures(&info);
	init_map(&info);
	init_player(&info);
	init_clip(&info);
	init_doors(&info);
	display_doom(&info);
}

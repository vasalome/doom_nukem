/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_doom.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 17:53:57 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 16:54:59 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

// void    render_skybox(t_info *info)
// {
//     return ;
//     // SDL_RenderCopy(info->win.ren, info->wt[29].texture, NULL, &info->wt[29].rect);
//     // SDL_RenderCopy(info->win.ren, info->wt[30].texture, NULL, &info->wt[30].rect);

//     // SDL_RenderCopy(info->win.ren, info->wt[25].texture, NULL, &info->wt[25].rect);
//     // SDL_RenderCopy(info->win.ren, info->wt[26].texture, NULL, &info->wt[26].rect);
//     // SDL_RenderCopy(info->win.ren, info->wt[27].texture, NULL, &info->wt[27].rect);
//     // SDL_RenderCopy(info->win.ren, info->wt[28].texture, NULL, &info->wt[28].rect);

//     // SDL_RenderCopy(info->win.ren, info->wt[20].texture, NULL, &info->wt[20].rect);
//     // SDL_RenderCopy(info->win.ren, info->wt[21].texture, NULL, &info->wt[21].rect);
//     // SDL_RenderCopy(info->win.ren, info->wt[22].texture, NULL, &info->wt[22].rect);
//     // SDL_RenderCopy(info->win.ren, info->wt[23].texture, NULL, &info->wt[23].rect);
//     // SDL_RenderCopy(info->win.ren, info->wt[24].texture, NULL, &info->wt[24].rect);
// }

// /* Fonction de callback (sera appelée toutes les 30 ms) */
// Uint32 frameDisplay(Uint32 intervalle, void *parametre)
// {
//     t_info *info = parametre;
//     //printf("%d FPS\n", info->frame);
//     info->frame = 0;
//     return intervalle;
// }


//     //SDL_Thread* threadID = SDL_CreateThread(threadAnim, "wowThread", (t_info*)&info);
//     //SDL_Thread* threadID2 = SDL_CreateThread(threadAnim2, "wowThread2", (t_info*)&info);
// 	//mlx_hook(info.win.win, 17, 0, red_cross, (void *)0);
// 	//mlx_hook(info.win.win, 2, (1L << 0), key_press, &info);
// 	//mlx_hook(info.win.win, 3, (1L << 1), key_release, &info);
// 	//mlx_loop_hook(info.win.mlx, move, &info);

//     //info.win.screen = IMG_Load("head/head1.png");

//     //SDL_SetWindowIcon(info.win.win, info.win.screen);
//     //Mix_PlayMusic(info.music.sound, -1);

//         // if (info.game == 2)
//         // {
//         //     SDL_SetTextureBlendMode(info.fps.texture, SDL_BLENDMODE_BLEND);
//         //     SDL_UnlockTexture(info.fps.texture);
        
//         //     SDL_RenderClear(info.win.ren);
//         //     render_skybox(&info);

//         //     SDL_RenderCopy(info.win.ren, info.fps.texture, NULL, &info.fps.rect);
//         //     // RENDER HUD
//         //     //SDL_RenderCopy(info.win.ren, info.hud[0].texture, NULL, &info.hud[0].rect);
// 		//info.sur_hud[0] = IMG_Load("hud/head/1/fst_r.png");
//     	//render_hud(&info, &event);
//         // }
//         // else if (info.game == 3)
//         // {
//         //     //menu(&info);
//         //     SDL_RenderClear(info.win.ren);
//         //     // SDL_RenderCopy(info.win.ren, info.head[1].texture, NULL, &info.head[1].rect);
//         //     // SDL_RenderCopy(info.win.ren, info.head[2].texture, NULL, &info.head[2].rect);
//         // }
//         // else
//         // {    
            
            
//         //     SDL_RenderClear(info.win.ren);
//         //     menu(&info);
            
//         //     SDL_RenderCopy(info.win.ren, info.head[0].texture, NULL, NULL);  
            
//         //     SDL_RenderCopy(info.win.ren, info.head[1].texture, NULL, &info.head[1].rect);
//         //     SDL_RenderCopy(info.win.ren, info.head[2].texture, NULL, &info.head[2].rect);
//         //     SDL_RenderCopy(info.win.ren, info.head[3].texture, NULL, &info.head[3].rect);
//         //     SDL_RenderCopy(info.win.ren, info.head[4].texture, NULL, &info.head[4].rect);
//         //     SDL_RenderCopy(info.win.ren, info.head[5].texture, NULL, &info.head[5].rect);
//         // }
		
// 		SDL_RenderPresent(info.win.ren);

//         info.frame++;
//        // move(&info);
//       //  ray_casting_image(&info);
//         if (info.game == 2)
//         {
//             move(&info);
//             move_doors(&info);
//             if(info.raycast)
//             {
//                 ray_casting_image(&info);
//                 end = clock();
// 		        info.delta_time = ((double)(end - start)) / CLOCKS_PER_SEC;
//                 info.raycast = 0;
//             }
            
//         }
//          if (info.game == 1)
//             info.game = 2;
// 		SDL_Delay(10);
// 	}
//    //SDL_WaitThread( threadID, NULL );
//    //SDL_WaitThread( threadID2, NULL );

	
//     int freeme = 0;
//     while (freeme < 30)
//     {
//         SDL_FreeSurface(info.wt[freeme++].img);
//     }
    
//    IMG_Quit();
//    SDL_Quit();
// }

// void    loadButton(t_info *info, int i)
// {
//     int     x;
//     int     y;

//     SDL_GetMouseState(&x, &y);
//     info->head[i].texture = SDL_CreateTextureFromSurface(info->win.ren, info->head[2].img);
//     SDL_QueryTexture(info->head[i].texture, NULL, NULL, &info->head[i].w, &info->head[i].h);
    
//     info->head[i].rect.x = ((WIDTH / 4) * 3 - (info->head[i].w/ 1.5) / 2) + info->xOffsetMenu;
//     info->head[i].rect.y = (info->head[1].h / 1.4  + ((info->head[i].h / 5 + 10) * (i - 2))) + info->yOffsetMenu;
//     info->head[i].rect.w = (info->head[i].w / 1.5) * info->zoom;
//     info->head[i].rect.h = (info->head[i].h / 5) * info->zoom; 
    
//     if (x > info->head[i].rect.x && x < (info->head[i].rect.x + info->head[i].rect.w))
//     {
//         if (y > info->head[i].rect.y && y < (info->head[i].rect.y + info->head[i].rect.h))
//         {
//             info->head[i].texture = SDL_CreateTextureFromSurface(info->win.ren, info->head[4].img);
//             info->button = i - 2;
//         }
//     }
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
    info->xOffsetMenu = 0;
    info->yOffsetMenu = 0;
    info->zoom = 1;
    info->fps.rect.x = 0;
    info->fps.rect.y = -200;
    info->fps.rect.w = WIDTH;
    info->fps.rect.h = HEIGHT + 400;
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
    //ray_casting(&info);
	display_doom(&info);
}

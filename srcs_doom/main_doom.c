/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_doom.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 17:53:57 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 14:30:47 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

/* Fonction de callback (sera appelée toutes les 30 ms) */
Uint32 frameDisplay(Uint32 intervalle, void *parametre)
{
    t_info *info = parametre;
    printf("%d FPS\n", info->frame);
    return intervalle;
}

int		main(int argc, char **argv)
{
	t_info	info;
    
  // SDL_Event evenements = {0};
    info.frame = 0;
    SDL_TimerID timer;

    timer = SDL_AddTimer(1, frameDisplay, (t_info*)&info); /* Démarrage du timer */

	if (argc != 2)
		ft_usage("Mauvais nombre d'arguments !");
	info.map.name = argv[1];
    info.i = 0;
    info.iii = 10;
    info.ii = 10;
    info.quit = 0;
	init(&info);

    //SDL_Thread* threadID = SDL_CreateThread(threadAnim, "wowThread", (t_info*)&info);
    //SDL_Thread* threadID2 = SDL_CreateThread(threadAnim2, "wowThread2", (t_info*)&info);
	//mlx_hook(info.win.win, 17, 0, red_cross, (void *)0);
	//mlx_hook(info.win.win, 2, (1L << 0), key_press, &info);
	//mlx_hook(info.win.win, 3, (1L << 1), key_release, &info);
	//mlx_loop_hook(info.win.mlx, move, &info);
	while(!info.quit)
   {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
 
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                info.quit = 1;
                break;
    
                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        info.quit = 1;
                    else if (event.key.keysym.sym == SDLK_w)
                        info.player.move_up = 1;
                    else if (event.key.keysym.sym == SDLK_s)
                        info.player.move_down = 1;
                    else if (event.key.keysym.sym == SDLK_d)
                        info.player.turn_right = 1;
                    else if (event.key.keysym.sym == SDLK_a)
                        info.player.turn_left = 1;
                    break;
                }
            
            case SDL_KEYUP:
                {
                    if (event.key.keysym.sym == SDLK_w)
                        info.player.move_up = 0;
                    else if (event.key.keysym.sym == SDLK_s)
                        info.player.move_down = 0;
                    else if (event.key.keysym.sym == SDLK_d)
                        info.player.turn_right = 0;
                    else if (event.key.keysym.sym == SDLK_a)
                        info.player.turn_left = 0;
                    break;
                }
        } // end switch
    } // end of message processing
            
        //hud(&info);
        SDL_UnlockTexture(info.fps.texture2);
		SDL_RenderClear(info.win.renderer);

        SDL_RenderCopy(info.win.renderer, info.fps.texture2, NULL, NULL);
        
        //SDL_RenderCopy(info.win.renderer, info.fps.texture, NULL, &info.head[3].rect);

        //SDL_RenderCopy(info.win.renderer, info.win.texture3, NULL, &info.head[4].rect);

		SDL_RenderPresent(info.win.renderer);

        //SDL_UpdateWindowSurface(info.win.win);

        //SDL_Delay(100);
        SDL_DestroyTexture(info.fps.texture2);
        info.frame++;
        move(&info);
        ray_casting_image(&info);
        
   }
   //SDL_WaitThread( threadID, NULL );
   //SDL_WaitThread( threadID2, NULL );
   IMG_Quit();
   SDL_Quit();
}

/*int main()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        //std::cout << "Failed to initialize the SDL2 library\n";
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          680, 480,
                                          0);

    if(!window)
    {
        //std::cout << "Failed to create window\n";
        return -1;
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    if(!window_surface)
    {
        //std::cout << "Failed to get the surface from the window\n";
        return -1;
    }

    SDL_UpdateWindowSurface(window);

    SDL_Delay(5000);
}*/
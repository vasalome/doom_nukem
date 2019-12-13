/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_doom.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 17:53:57 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 14:51:53 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void    render_skybox(t_info *info)
{
    SDL_RenderCopy(info->win.renderer, info->wt[29].texture, NULL, &info->wt[29].rect);
    SDL_RenderCopy(info->win.renderer, info->wt[30].texture, NULL, &info->wt[30].rect);

    SDL_RenderCopy(info->win.renderer, info->wt[25].texture, NULL, &info->wt[25].rect);
    SDL_RenderCopy(info->win.renderer, info->wt[26].texture, NULL, &info->wt[26].rect);
    SDL_RenderCopy(info->win.renderer, info->wt[27].texture, NULL, &info->wt[27].rect);
    SDL_RenderCopy(info->win.renderer, info->wt[28].texture, NULL, &info->wt[28].rect);

    SDL_RenderCopy(info->win.renderer, info->wt[20].texture, NULL, &info->wt[20].rect);
    SDL_RenderCopy(info->win.renderer, info->wt[21].texture, NULL, &info->wt[21].rect);
    SDL_RenderCopy(info->win.renderer, info->wt[22].texture, NULL, &info->wt[22].rect);
    SDL_RenderCopy(info->win.renderer, info->wt[23].texture, NULL, &info->wt[23].rect);
    SDL_RenderCopy(info->win.renderer, info->wt[24].texture, NULL, &info->wt[24].rect);
}

/* Fonction de callback (sera appelée toutes les 30 ms) */
Uint32 frameDisplay(Uint32 intervalle, void *parametre)
{
    t_info *info = parametre;
    //printf("%d FPS\n", info->frame);
    info->frame = 0;
    return intervalle;
}

int		main(int argc, char **argv)
{
	t_info	info;
    
  // SDL_Event evenements = {0};
    info.frame = 0;
    SDL_TimerID timer;

    //timer = SDL_AddTimer(1000, frameDisplay, (t_info*)&info); /* Démarrage du timer */

	if (argc != 2)
		ft_usage("Mauvais nombre d'arguments !");
    
	info.map.name = argv[1];
    info.i = 0;
    info.iii = 10;
    info.ii = 10;
    info.quit = 0;
	init(&info);
    info.fps.rect.x = 0;
	info.fps.rect.y = -200;
	info.fps.rect.w = WIDTH;
	info.fps.rect.h = HEIGHT + 400;

    //SDL_Thread* threadID = SDL_CreateThread(threadAnim, "wowThread", (t_info*)&info);
    //SDL_Thread* threadID2 = SDL_CreateThread(threadAnim2, "wowThread2", (t_info*)&info);
	//mlx_hook(info.win.win, 17, 0, red_cross, (void *)0);
	//mlx_hook(info.win.win, 2, (1L << 0), key_press, &info);
	//mlx_hook(info.win.win, 3, (1L << 1), key_release, &info);
	//mlx_loop_hook(info.win.mlx, move, &info);

    //info.win.screen = IMG_Load("head/head1.png");

    //SDL_SetWindowIcon(info.win.win, info.win.screen);
    //Mix_PlayMusic(info.music.sound, -1);

    while(!info.quit)
    {
        SDL_Event event;
        //printf("xrel -> %d\n", event.motion.xrel);
        //printf("yrel -> %f\n", info.player.turn_rate);
        
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
                        info.player.move_right = 1;
                    else if (event.key.keysym.sym == SDLK_a)
                        info.player.move_left = 1;
                    else if (event.key.keysym.sym == SDLK_e)
                        info.player.turn_right = 1;
                    else if (event.key.keysym.sym == SDLK_q)
                        info.player.turn_left = 1;
                    else if (event.key.keysym.sym == SDLK_b)
                        info.player.height  += 0.1;
                    else if (event.key.keysym.sym == SDLK_n)
                        info.player.height  -= 0.1;
                    else if (event.key.keysym.sym == SDLK_LSHIFT)
                        info.player.move_speed = 0.1;
                    else if (event.key.keysym.sym == SDLK_f)
                        info.action = 1;
                    else if (event.key.keysym.sym == SDLK_g)
                    {
                        Mix_PlayChannel(-1, info.music.high, 0);
                    }
                    else if (event.key.keysym.sym == SDLK_h)
                    {
                        Mix_PlayChannel(-1, info.music.low, 0);
                    }
                    else if (event.key.keysym.sym == SDLK_z)
                    {
                        SDL_Delay(10);
                        info.wt[8].img = IMG_Load("wall/jojo2.png");
	                    info.wt[9].img = IMG_Load("wall/jojo2.png");
	                    info.wt[10].img = IMG_Load("wall/jojo2.png");
	                    info.wt[11].img = IMG_Load("wall/jojo2.png");
                    }
                    break;
                }
            
            case SDL_KEYUP:
                {
                    if (event.key.keysym.sym == SDLK_w)
                        info.player.move_up = 0;
                    else if (event.key.keysym.sym == SDLK_s)
                        info.player.move_down = 0;
                    else if (event.key.keysym.sym == SDLK_d)
                        info.player.move_right = 0;
                    else if (event.key.keysym.sym == SDLK_a)
                        info.player.move_left = 0;
                    else if (event.key.keysym.sym == SDLK_e)
                        info.player.turn_right = 0;
                    else if (event.key.keysym.sym == SDLK_q)
                        info.player.turn_left = 0;
                    else if (event.key.keysym.sym == SDLK_LSHIFT)
                        info.player.move_speed = 0.05;
                    else if (event.key.keysym.sym == SDLK_f)
                        info.action = 0;
                    else if (event.key.keysym.sym == SDLK_z)
                    {
                        SDL_Delay(10);
                        info.wt[8].img = IMG_Load("wall/jojo.png");
	                    info.wt[9].img = IMG_Load("wall/jojo.png");
	                    info.wt[10].img = IMG_Load("wall/jojo.png");
	                    info.wt[11].img = IMG_Load("wall/jojo.png");
                    }
                    break;
                }
            case SDL_MOUSEMOTION:
                {
                    SDL_ShowCursor(SDL_DISABLE);
                    info.player.turn_right = 1;
                    info.player.turn_left = 1;
                    info.player.turn_rate = -event.motion.xrel * 0.002;
                    info.player.turn_rate_y = event.motion.yrel * 0.002;
                    
                    SDL_WarpMouseInWindow(info.win.win, info.win.w/2, info.win.h/2); 
                }
            case SDL_MOUSEBUTTONDOWN:
                {
                    switch (event.button.button)
                    {
                        case SDL_BUTTON_LEFT:
                            printf("CLICK LEFT\n");
                            break;
                        case SDL_BUTTON_RIGHT:
                            printf("CLICK RIGHT\n");
                            break;
                        case SDL_BUTTON_MIDDLE:
                            printf("CLICK MIDDLE\n");
                            break;
                    }
                }
            case SDL_MOUSEWHEEL:
                {
                    if (event.wheel.y > 0);
                        //printf("CLICK WHEELUP\n");
                    //printf("event.wheel.y 111111-> %d\n", event.wheel.y);
                    if (event.wheel.y < 0);
                        //printf("CLICK WHEELDOWN\n");
                    //printf("event.wheel.y 222222-> %d\n", event.wheel.y);
                }
        } // end switch
    } // end of message processing
            
        //hud(&info);
        SDL_SetTextureBlendMode(info.fps.texture, SDL_BLENDMODE_BLEND);
        SDL_UnlockTexture(info.fps.texture);
        //SDL_UnlockTexture(info.wt[2].texture);
      
		SDL_RenderClear(info.win.renderer);
        render_skybox(&info);
        SDL_RenderCopy(info.win.renderer, info.fps.texture, NULL, &info.fps.rect);
        //SDL_RenderCopy(info.win.renderer, info.wt[2].texture, NULL, &info.head[3].rect);
          
        ////// ESPACE SKYBOX
        //render_skybox(&info);

        //SDL_RenderCopy(info.win.renderer, info.fps.texture2, NULL, &info.head[3].rect);

        //SDL_RenderCopy(info.win.renderer, info.win.texture3, NULL, &info.head[4].rect);

		SDL_RenderPresent(info.win.renderer);

        //SDL_UpdateWindowSurface(info.win.win);

        //SDL_Delay(100);
        //SDL_DestroyTexture(info.fps.texture2);
        info.frame++;
        move(&info);
        
        ray_casting_image(&info);

   }
   //SDL_WaitThread( threadID, NULL );
   //SDL_WaitThread( threadID2, NULL );


    int freeme = 0;
    while (freeme < 30)
    {
        SDL_FreeSurface(info.wt[freeme++].img);
    }
    
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
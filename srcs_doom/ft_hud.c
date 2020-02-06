/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hud.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 15:54:11 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 11:34:02 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	healthpack(t_info *info)
{
	char	*pack = NULL;

	pack = ft_itoa(info->item.hp);
	// print les packs a droite en dessous des munitions
}

void	munition(t_info *info)
{
	char	*ammo = NULL;
	
	ammo = ft_itoa(info->item.ammo);
	// print les munitions a droite
}

void	lifebar(t_info *info)
{
	char	*life = NULL;
	
	life = ft_itoa(info->player.life);
	//printf("string = %s\n", life);
	// print la vie a gauche
}

void	render_hud(t_info *info, SDL_Event event)
{
	static int	backup = 0;
	static int	hit = 0;

	// if (info->item.key >= 1)
		// SDL_RenderCopy(info->win.ren, info->hud[1].texture, NULL, &info->hud[1].rect);
	// SDL_RenderCopy(info->win.ren, info->hud[0].texture, NULL, &info->hud[0].rect);

	if (info->player.life > 80)
	{
		if (event.motion.xrel == backup || event.motion.xrel == 0){
			// SDL_RenderCopy(info->win.ren, info->hud[3].texture, NULL, &info->hud[3].rect);
			put_texture(info, (t_start){75, 537}, (t_size){120, 145}, info->sur_hud[0]);
			}
	}
	// 	else if (event->motion.xrel < 0)
	// 		SDL_RenderCopy(info->win.ren, info->hud[4].texture, NULL, &info->hud[4].rect);
	// 	else if (event->motion.xrel > 0)
	// 		SDL_RenderCopy(info->win.ren, info->hud[5].texture, NULL, &info->hud[5].rect);
	// }
	// else if (info->player.life > 60)
	// {
	// 	if (event->motion.xrel == backup || event->motion.xrel == 0)
	// 		SDL_RenderCopy(info->win.ren, info->hud[6].texture, NULL, &info->hud[6].rect);
	// 	else if (event->motion.xrel < 0)
	// 		SDL_RenderCopy(info->win.ren, info->hud[7].texture, NULL, &info->hud[7].rect);
	// 	else if (event->motion.xrel > 0)
	// 		SDL_RenderCopy(info->win.ren, info->hud[8].texture, NULL, &info->hud[8].rect);
	// }
	// else if (info->player.life > 30)
	// {
	// 	if (event->motion.xrel == backup || event->motion.xrel == 0)
	// 		SDL_RenderCopy(info->win.ren, info->hud[9].texture, NULL, &info->hud[9].rect);
	// 	else if (event->motion.xrel < 0)
	// 		SDL_RenderCopy(info->win.ren, info->hud[10].texture, NULL, &info->hud[10].rect);
	// 	else if (event->motion.xrel > 0)
	// 		SDL_RenderCopy(info->win.ren, info->hud[11].texture, NULL, &info->hud[11].rect);
	// }
	// else if (info->player.life > 0)
	// {
	// 	if (event->motion.xrel == backup || event->motion.xrel == 0)
	// 		SDL_RenderCopy(info->win.ren, info->hud[12].texture, NULL, &info->hud[12].rect);
	// 	else if (event->motion.xrel < 0)
	// 		SDL_RenderCopy(info->win.ren, info->hud[13].texture, NULL, &info->hud[13].rect);
	// 	else if (event->motion.xrel > 0)
	// 		SDL_RenderCopy(info->win.ren, info->hud[14].texture, NULL, &info->hud[14].rect);
	// }
	// else if (info->player.life <= 0)
	// 	SDL_RenderCopy(info->win.ren, info->hud[19].texture, NULL, &info->hud[19].rect);

	// // Quand le player prend des dégats. Allonger son affichage
	// if (info->player.life != hit)
	// {
	// 	if (info->player.life < 100 && info->player.life >= 80)
	// 		SDL_RenderCopy(info->win.ren, info->hud[15].texture, NULL, &info->hud[15].rect);
	// 	else if (info->player.life < 80 && info->player.life >= 60)
	// 		SDL_RenderCopy(info->win.ren, info->hud[16].texture, NULL, &info->hud[16].rect);
	// 	else if (info->player.life < 60 && info->player.life >= 30)
	// 		SDL_RenderCopy(info->win.ren, info->hud[17].texture, NULL, &info->hud[17].rect);
	// 	else if (info->player.life < 30 && info->player.life >= 0)
	// 		SDL_RenderCopy(info->win.ren, info->hud[18].texture, NULL, &info->hud[18].rect);
	// }

	hit = info->player.life;
	backup = event.motion.xrel;
	lifebar(info);
	munition(info);
}

void	draw_head_hurt(t_info *info)
{
	info->hud[15].img = IMG_Load("hud/head/h/1.png");
	info->hud[15].texture = SDL_CreateTextureFromSurface(info->win.ren,\
		info->hud[15].img);
	info->hud[15].rect.x = 75;
	info->hud[15].rect.y = 537;
	info->hud[15].rect.w = 120;
	info->hud[15].rect.h = 145;

	info->hud[16].img = IMG_Load("hud/head/h/2.png");
	info->hud[16].texture = SDL_CreateTextureFromSurface(info->win.ren,\
		info->hud[16].img);
	info->hud[16].rect.x = 75;
	info->hud[16].rect.y = 535;
	info->hud[16].rect.w = 120;
	info->hud[16].rect.h = 145;

	info->hud[17].img = IMG_Load("hud/head/h/3.png");
	info->hud[17].texture = SDL_CreateTextureFromSurface(info->win.ren,\
		info->hud[17].img);
	info->hud[17].rect.x = 75;
	info->hud[17].rect.y = 535;
	info->hud[17].rect.w = 120;
	info->hud[17].rect.h = 145;

	info->hud[18].img = IMG_Load("hud/head/h/4.png");
	info->hud[18].texture = SDL_CreateTextureFromSurface(info->win.ren,\
		info->hud[18].img);
	info->hud[18].rect.x = 75;
	info->hud[18].rect.y = 535;
	info->hud[18].rect.w = 120;
	info->hud[18].rect.h = 145;

	info->hud[19].img = IMG_Load("hud/head/h/dead.png");
	info->hud[19].texture = SDL_CreateTextureFromSurface(info->win.ren,\
		info->hud[19].img);
	info->hud[19].rect.x = 75;
	info->hud[19].rect.y = 536;
	info->hud[19].rect.w = 120;
	info->hud[19].rect.h = 145;
}

void	draw_head_low(t_info *info)
{
	info->hud[12].img = IMG_Load("hud/head/4/fst_m.png");
	info->hud[12].texture = SDL_CreateTextureFromSurface(info->win.ren,\
		info->hud[12].img);
	info->hud[12].rect.x = 75;
	info->hud[12].rect.y = 537;
	info->hud[12].rect.w = 120;
	info->hud[12].rect.h = 145;

	info->hud[13].img = IMG_Load("hud/head/4/fst_r.png");
	info->hud[13].texture = SDL_CreateTextureFromSurface(info->win.ren,\
		info->hud[13].img);
	info->hud[13].rect.x = 75;
	info->hud[13].rect.y = 535;
	info->hud[13].rect.w = 120;
	info->hud[13].rect.h = 145;

	info->hud[14].img = IMG_Load("hud/head/4/fst_l.png");
	info->hud[14].texture = SDL_CreateTextureFromSurface(info->win.ren,\
		info->hud[14].img);
	info->hud[14].rect.x = 75;
	info->hud[14].rect.y = 535;
	info->hud[14].rect.w = 120;
	info->hud[14].rect.h = 145;
}

void	draw_head_mid(t_info *info)
{
	info->hud[9].img = IMG_Load("hud/head/3/fst_m.png");
	info->hud[9].texture = SDL_CreateTextureFromSurface(info->win.ren,\
		info->hud[9].img);
	info->hud[9].rect.x = 75;
	info->hud[9].rect.y = 537;
	info->hud[9].rect.w = 120;
	info->hud[9].rect.h = 145;

	info->hud[10].img = IMG_Load("hud/head/3/fst_r.png");
	info->hud[10].texture = SDL_CreateTextureFromSurface(info->win.ren,\
		info->hud[10].img);
	info->hud[10].rect.x = 75;
	info->hud[10].rect.y = 535;
	info->hud[10].rect.w = 120;
	info->hud[10].rect.h = 145;

	info->hud[11].img = IMG_Load("hud/head/3/fst_l.png");
	info->hud[11].texture = SDL_CreateTextureFromSurface(info->win.ren,\
		info->hud[11].img);
	info->hud[11].rect.x = 75;
	info->hud[11].rect.y = 535;
	info->hud[11].rect.w = 120;
	info->hud[11].rect.h = 145;
}

void	draw_head_lips(t_info *info)
{
	info->hud[6].img = IMG_Load("hud/head/2/fst_m.png");
	info->hud[6].texture = SDL_CreateTextureFromSurface(info->win.ren,\
		info->hud[6].img);
	info->hud[6].rect.x = 75;
	info->hud[6].rect.y = 537;
	info->hud[6].rect.w = 120;
	info->hud[6].rect.h = 145;

	info->hud[7].img = IMG_Load("hud/head/2/fst_r.png");
	info->hud[7].texture = SDL_CreateTextureFromSurface(info->win.ren,\
		info->hud[7].img);
	info->hud[7].rect.x = 75;
	info->hud[7].rect.y = 535;
	info->hud[7].rect.w = 120;
	info->hud[7].rect.h = 145;

	info->hud[8].img = IMG_Load("hud/head/2/fst_l.png");
	info->hud[8].texture = SDL_CreateTextureFromSurface(info->win.ren,\
		info->hud[8].img);
	info->hud[8].rect.x = 75;
	info->hud[8].rect.y = 535;
	info->hud[8].rect.w = 120;
	info->hud[8].rect.h = 145;
}

void	draw_head(t_info *info)
{
	info->sur_hud[0] = IMG_Load("hud/head/1/fst_m.png");
	// info->hud[3].img = IMG_Load("hud/head/1/fst_m.png");
	// info->hud[3].texture = SDL_CreateTextureFromSurface(info->win.ren,\
	// 	info->hud[3].img);
	// info->hud[3].rect.x = 75;
	// info->hud[3].rect.y = 537;
	// info->hud[3].rect.w = 120;
	// info->hud[3].rect.h = 145;

	info->hud[4].img = IMG_Load("hud/head/1/fst_r.png");
	info->hud[4].texture = SDL_CreateTextureFromSurface(info->win.ren,\
		info->hud[4].img);
	info->hud[4].rect.x = 75;
	info->hud[4].rect.y = 535;
	info->hud[4].rect.w = 120;
	info->hud[4].rect.h = 145;

	info->hud[5].img = IMG_Load("hud/head/1/fst_l.png");
	info->hud[5].texture = SDL_CreateTextureFromSurface(info->win.ren,\
		info->hud[5].img);
	info->hud[5].rect.x = 75;
	info->hud[5].rect.y = 535;
	info->hud[5].rect.w = 120;
	info->hud[5].rect.h = 145;

	draw_head_lips(info);
	draw_head_mid(info);
	draw_head_low(info);
	draw_head_hurt(info);
}

void    draw_hud(t_info *info)
{
	printf("bonjour\n");
    info->hud[0].img = IMG_Load("hud/hud_gen.png");
	info->hud[0].texture = SDL_CreateTextureFromSurface(info->win.ren,\
		info->hud[0].img);
	info->hud[0].rect.x = 0;
	info->hud[0].rect.y = 0;
	info->hud[0].rect.w = WIDTH;
	info->hud[0].rect.h = HEIGHT;

	info->hud[1].img = IMG_Load("hud/hud_key.png");
	info->hud[1].texture = SDL_CreateTextureFromSurface(info->win.ren,\
		info->hud[1].img);
	info->hud[1].rect.x = 1010;
	info->hud[1].rect.y = 790;
	info->hud[1].rect.w = 109;
	info->hud[1].rect.h = 89;

	draw_head(info);
}

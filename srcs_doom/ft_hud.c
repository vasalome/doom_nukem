/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hud.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 15:54:11 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 20:59:46 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	healthpack(t_info *info)
{
	char	*pack = NULL;

	pack = ft_itoa(info->item.hp);
	put_text(info, write_text(ft_strcat(pack," +"), 35), 360, 825);
}

void	munition(t_info *info)
{
	char	*ammo = NULL;
	char	*reload = NULL;
	
	ammo = ft_itoa(info->item.ammo);
	reload = ft_itoa(info->item.reload);
	put_text(info, write_text(ammo, 75), 1200, 790);
	put_text(info, write_text("/ 6", 35), 1270, 790);
	put_text(info, write_text(reload, 35), 1270, 825);
	put_text(info, write_text("mun", 22), 1320, 836);
}

void	lifebar(t_info *info)
{
	char	*life = NULL;
	
	life = ft_itoa(info->player.life);
	if (info->player.life >= 0)
		put_text(info, write_text(life, 75), 250, 790);
	else
		info->player.life = 0;
	put_text(info, write_text("%", 35), 360, 795);
}

void	render_hud(t_info *info, SDL_Event *event)
{
	static int	backup = 0;
	static int	hit = 0;

	if (info->item.key >= 1)
		put_texture(info, (t_start){1010, 790}, (t_size){109, 89}, info->sur_hud[1]);
	put_texture(info, (t_start){0, 0}, (t_size){WIDTH, HEIGHT}, info->sur_hud[0]);

	if (info->player.life > 80)
	{
		if (event->motion.xrel == backup || event->motion.xrel == 0)
			put_texture(info, (t_start){75, 537}, (t_size){120, 145}, info->sur_hud[3]);
		else if (event->motion.xrel < 0)
			put_texture(info, (t_start){75, 535}, (t_size){120, 145}, info->sur_hud[4]);
		else if (event->motion.xrel > 0)
			put_texture(info, (t_start){75, 535}, (t_size){120, 145}, info->sur_hud[5]);
	}
	else if (info->player.life > 60)
	{
		if (event->motion.xrel == backup || event->motion.xrel == 0)
			put_texture(info, (t_start){75, 537}, (t_size){120, 145}, info->sur_hud[6]);
		else if (event->motion.xrel < 0)
			put_texture(info, (t_start){75, 535}, (t_size){120, 145}, info->sur_hud[7]);
		else if (event->motion.xrel > 0)
			put_texture(info, (t_start){75, 535}, (t_size){120, 145}, info->sur_hud[8]);
	}
	else if (info->player.life > 30)
	{
		if (event->motion.xrel == backup || event->motion.xrel == 0)
			put_texture(info, (t_start){75, 537}, (t_size){120, 145}, info->sur_hud[9]);
		else if (event->motion.xrel < 0)
			put_texture(info, (t_start){75, 535}, (t_size){120, 145}, info->sur_hud[10]);
		else if (event->motion.xrel > 0)
			put_texture(info, (t_start){75, 535}, (t_size){120, 145}, info->sur_hud[11]);
	}
	else if (info->player.life > 0)
	{
		if (event->motion.xrel == backup || event->motion.xrel == 0)
			put_texture(info, (t_start){75, 537}, (t_size){120, 145}, info->sur_hud[12]);
		else if (event->motion.xrel < 0)
			put_texture(info, (t_start){75, 535}, (t_size){120, 145}, info->sur_hud[13]);
		else if (event->motion.xrel > 0)
			put_texture(info, (t_start){75, 535}, (t_size){120, 145}, info->sur_hud[14]);
	}
	else if (info->player.life <= 0)
		put_texture(info, (t_start){75, 536}, (t_size){120, 145}, info->sur_hud[19]);

	// Quand le player prend des dégats. Allonger son affichage
	if (info->player.life != hit)
	{
		if (info->player.life < 100 && info->player.life >= 80)
			put_texture(info, (t_start){75, 537}, (t_size){120, 145}, info->sur_hud[15]);
		else if (info->player.life < 80 && info->player.life >= 60)
			put_texture(info, (t_start){75, 535}, (t_size){120, 145}, info->sur_hud[16]);
		else if (info->player.life < 60 && info->player.life >= 30)
			put_texture(info, (t_start){75, 535}, (t_size){120, 145}, info->sur_hud[17]);
		else if (info->player.life < 30 && info->player.life >= 0)
			put_texture(info, (t_start){75, 535}, (t_size){120, 145}, info->sur_hud[18]);
	}

	hit = info->player.life;
	backup = event->motion.xrel;
	lifebar(info);
	munition(info);
	healthpack(info);
}

void	draw_head_hurt(t_info *info)
{
	info->sur_hud[15] = IMG_Load("hud/head/h/1.png");
	// info->hud[15].img = IMG_Load("hud/head/h/1.png");
	// info->hud[15].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
	// 	info->hud[15].img);
	// info->hud[15].rect.x = 75;
	// info->hud[15].rect.y = 537;
	// info->hud[15].rect.w = 120;
	// info->hud[15].rect.h = 145;

	info->sur_hud[16] = IMG_Load("hud/head/h/2.png");
	// info->hud[16].img = IMG_Load("hud/head/h/2.png");
	// info->hud[16].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
	// 	info->hud[16].img);
	// info->hud[16].rect.x = 75;
	// info->hud[16].rect.y = 535;
	// info->hud[16].rect.w = 120;
	// info->hud[16].rect.h = 145;

	info->sur_hud[17] = IMG_Load("hud/head/h/3.png");
	// info->hud[17].img = IMG_Load("hud/head/h/3.png");
	// info->hud[17].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
	// 	info->hud[17].img);
	// info->hud[17].rect.x = 75;
	// info->hud[17].rect.y = 535;
	// info->hud[17].rect.w = 120;
	// info->hud[17].rect.h = 145;

	info->sur_hud[18] = IMG_Load("hud/head/h/4.png");
	// info->hud[18].img = IMG_Load("hud/head/h/4.png");
	// info->hud[18].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
	// 	info->hud[18].img);
	// info->hud[18].rect.x = 75;
	// info->hud[18].rect.y = 535;
	// info->hud[18].rect.w = 120;
	// info->hud[18].rect.h = 145;

	info->sur_hud[19] = IMG_Load("hud/head/h/dead.png");
	// info->hud[19].img = IMG_Load("hud/head/h/dead.png");
	// info->hud[19].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
	// 	info->hud[19].img);
	// info->hud[19].rect.x = 75;
	// info->hud[19].rect.y = 536;
	// info->hud[19].rect.w = 120;
	// info->hud[19].rect.h = 145;
}

void	draw_head_low(t_info *info)
{
	info->sur_hud[12] = IMG_Load("hud/head/4/fst_m.png");
	// info->hud[12].img = IMG_Load("hud/head/4/fst_m.png");
	// info->hud[12].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
	// 	info->hud[12].img);
	// info->hud[12].rect.x = 75;
	// info->hud[12].rect.y = 537;
	// info->hud[12].rect.w = 120;
	// info->hud[12].rect.h = 145;

	info->sur_hud[13] = IMG_Load("hud/head/4/fst_r.png");
	// info->hud[13].img = IMG_Load("hud/head/4/fst_r.png");
	// info->hud[13].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
	// 	info->hud[13].img);
	// info->hud[13].rect.x = 75;
	// info->hud[13].rect.y = 535;
	// info->hud[13].rect.w = 120;
	// info->hud[13].rect.h = 145;

	info->sur_hud[14] = IMG_Load("hud/head/4/fst_l.png");
	// info->hud[14].img = IMG_Load("hud/head/4/fst_l.png");
	// info->hud[14].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
	// 	info->hud[14].img);
	// info->hud[14].rect.x = 75;
	// info->hud[14].rect.y = 535;
	// info->hud[14].rect.w = 120;
	// info->hud[14].rect.h = 145;
}

void	draw_head_mid(t_info *info)
{
	info->sur_hud[9] = IMG_Load("hud/head/3/fst_m.png");
	// info->hud[9].img = IMG_Load("hud/head/3/fst_m.png");
	// info->hud[9].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
	// 	info->hud[9].img);
	// info->hud[9].rect.x = 75;
	// info->hud[9].rect.y = 537;
	// info->hud[9].rect.w = 120;
	// info->hud[9].rect.h = 145;

	info->sur_hud[10] = IMG_Load("hud/head/3/fst_r.png");
	// info->hud[10].img = IMG_Load("hud/head/3/fst_r.png");
	// info->hud[10].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
	// 	info->hud[10].img);
	// info->hud[10].rect.x = 75;
	// info->hud[10].rect.y = 535;
	// info->hud[10].rect.w = 120;
	// info->hud[10].rect.h = 145;

	info->sur_hud[11] = IMG_Load("hud/head/3/fst_l.png");
	// info->hud[11].img = IMG_Load("hud/head/3/fst_l.png");
	// info->hud[11].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
	// 	info->hud[11].img);
	// info->hud[11].rect.x = 75;
	// info->hud[11].rect.y = 535;
	// info->hud[11].rect.w = 120;
	// info->hud[11].rect.h = 145;
}

void	draw_head_lips(t_info *info)
{
	info->sur_hud[6] = IMG_Load("hud/head/2/fst_m.png");
	// info->hud[6].img = IMG_Load("hud/head/2/fst_m.png");
	// info->hud[6].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
	// 	info->hud[6].img);
	// info->hud[6].rect.x = 75;
	// info->hud[6].rect.y = 537;
	// info->hud[6].rect.w = 120;
	// info->hud[6].rect.h = 145;

	info->sur_hud[7] = IMG_Load("hud/head/2/fst_r.png");
	// info->hud[7].img = IMG_Load("hud/head/2/fst_r.png");
	// info->hud[7].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
	// 	info->hud[7].img);
	// info->hud[7].rect.x = 75;
	// info->hud[7].rect.y = 535;
	// info->hud[7].rect.w = 120;
	// info->hud[7].rect.h = 145;

	info->sur_hud[8] = IMG_Load("hud/head/2/fst_l.png");
	// info->hud[8].img = IMG_Load("hud/head/2/fst_l.png");
	// info->hud[8].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
	// 	info->hud[8].img);
	// info->hud[8].rect.x = 75;
	// info->hud[8].rect.y = 535;
	// info->hud[8].rect.w = 120;
	// info->hud[8].rect.h = 145;
}

void	draw_head(t_info *info)
{
	info->sur_hud[3] = IMG_Load("hud/head/1/fst_m.png");
	// info->hud[3].img = IMG_Load("hud/head/1/fst_m.png");
	// info->hud[3].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
	// 	info->hud[3].img);
	// info->hud[3].rect.x = 75;
	// info->hud[3].rect.y = 537;
	// info->hud[3].rect.w = 120;
	// info->hud[3].rect.h = 145;

	info->sur_hud[4] = IMG_Load("hud/head/1/fst_r.png");
	// info->hud[4].img = IMG_Load("hud/head/1/fst_r.png");
	// info->hud[4].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
	// 	info->hud[4].img);
	// info->hud[4].rect.x = 75;
	// info->hud[4].rect.y = 535;
	// info->hud[4].rect.w = 120;
	// info->hud[4].rect.h = 145;

	info->sur_hud[5] = IMG_Load("hud/head/1/fst_l.png");
	// info->hud[5].img = IMG_Load("hud/head/1/fst_l.png");
	// info->hud[5].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
	// 	info->hud[5].img);
	// info->hud[5].rect.x = 75;
	// info->hud[5].rect.y = 535;
	// info->hud[5].rect.w = 120;
	// info->hud[5].rect.h = 145;

	draw_head_lips(info);
	draw_head_mid(info);
	draw_head_low(info);
	draw_head_hurt(info);
}

void    draw_hud(t_info *info)
{
	info->sur_hud[0] = IMG_Load("hud/hud_gen.png");
    // info->hud[0].img = IMG_Load("hud/hud_gen.png");
	// info->hud[0].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
	// 	info->hud[0].img);
	// info->hud[0].rect.x = 0;
	// info->hud[0].rect.y = 0;
	// info->hud[0].rect.w = WIDTH;
	// info->hud[0].rect.h = HEIGHT;

	info->sur_hud[1] = IMG_Load("hud/hud_key.png");
	// info->hud[1].img = IMG_Load("hud/hud_key.png");
	// info->hud[1].texture = SDL_CreateTextureFromSurface(info->win.renderer,\
	// 	info->hud[1].img);
	// info->hud[1].rect.x = 1010;
	// info->hud[1].rect.y = 790;
	// info->hud[1].rect.w = 109;
	// info->hud[1].rect.h = 89;

	draw_head(info);
}

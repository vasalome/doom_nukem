/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hud.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 15:54:11 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 19:39:21 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	info_hud(t_info *info)
{
	char	*life;
	char	*pack;
	char	*ammo;
	char	*reload;

	life = ft_itoa(info->player.life);
	pack = ft_itoa(info->item.hp);
	ammo = ft_itoa(info->item.ammo);
	reload = ft_itoa(info->item.reload);
	if (info->player.life >= 0)
		put_text(info, write_text_hud(life, 75), 250, 790);
	else
		info->player.life = 0;
	put_text(info, write_text_hud("%", 35), 360, 795);
	put_text(info, write_text_hud(ft_strcat(pack," +"), 35), 360, 825);
	put_text(info, write_text_hud(ammo, 75), 1200, 790);
	put_text(info, write_text_hud("/ 6", 35), 1270, 790);
	put_text(info, write_text_hud(reload, 35), 1270, 825);
	put_text(info, write_text_hud("mun", 22), 1310, 836);
}

void	render_head_low(t_info *i, SDL_Event *event)
{
	if (i->player.life > 30)
	{
		if (event->motion.xrel == i->player.backup || event->motion.xrel == 0)
			put_texture(i, (t_start){75, 537}, (t_size){120, 145}, i->hud[9]);
		else if (event->motion.xrel < 0)
			put_texture(i, (t_start){75, 535}, (t_size){120, 145}, i->hud[10]);
		else if (event->motion.xrel > 0)
			put_texture(i, (t_start){75, 535}, (t_size){120, 145}, i->hud[11]);
	}
	else if (i->player.life > 0)
	{
		if (event->motion.xrel == i->player.backup || event->motion.xrel == 0)
			put_texture(i, (t_start){75, 537}, (t_size){120, 145}, i->hud[12]);
		else if (event->motion.xrel < 0)
			put_texture(i, (t_start){75, 535}, (t_size){120, 145}, i->hud[13]);
		else if (event->motion.xrel > 0)
			put_texture(i, (t_start){75, 535}, (t_size){120, 145}, i->hud[14]);
	}
}

void	render_head(t_info *i, SDL_Event *event)
{
	if (i->player.life > 80 && i->player.life == i->player.hit)
	{
		if (event->motion.xrel == i->player.backup || event->motion.xrel == 0)
			put_texture(i, (t_start){75, 537}, (t_size){120, 145}, i->hud[3]);
		else if (event->motion.xrel < 0)
			put_texture(i, (t_start){75, 535}, (t_size){120, 145}, i->hud[4]);
		else if (event->motion.xrel > 0)
			put_texture(i, (t_start){75, 535}, (t_size){120, 145}, i->hud[5]);
	}
	else if (i->player.life > 60 && i->player.life == i->player.hit)
	{
		if (event->motion.xrel == i->player.backup || event->motion.xrel == 0)
			put_texture(i, (t_start){75, 537}, (t_size){120, 145}, i->hud[6]);
		else if (event->motion.xrel < 0)
			put_texture(i, (t_start){75, 535}, (t_size){120, 145}, i->hud[7]);
		else if (event->motion.xrel > 0)
			put_texture(i, (t_start){75, 535}, (t_size){120, 145}, i->hud[8]);
	}
	else if (i->player.life > 0 && i->player.life == i->player.hit)
	{
		render_head_low(i, event);
	}
}

void	render_hud(t_info *i, SDL_Event *event)
{
	if (i->item.key >= 1)
		put_texture(i, (t_start){1010, 790}, (t_size){109, 89}, i->hud[1]);
	put_texture(i, (t_start){0, 0}, (t_size){WIDTH, HEIGHT}, i->hud[0]);
	if (i->player.life > 0 && i->player.life == i->player.hit)
	{
		render_head(i, event);
	}
	else if (i->player.life <= 0 && i->player.life == i->player.hit)
		put_texture(i, (t_start){75, 536}, (t_size){120, 145}, i->hud[19]);
	if (i->player.life != i->player.hit)
	{
		if (i->player.life < 100 && i->player.life >= 80)
			put_texture(i, (t_start){75, 537}, (t_size){120, 145}, i->hud[15]);
		else if (i->player.life < 80 && i->player.life >= 60)
			put_texture(i, (t_start){75, 535}, (t_size){120, 145}, i->hud[16]);
		else if (i->player.life < 60 && i->player.life >= 30)
			put_texture(i, (t_start){75, 535}, (t_size){120, 145}, i->hud[17]);
		else if (i->player.life < 30 && i->player.life >= 0)
			put_texture(i, (t_start){75, 535}, (t_size){120, 145}, i->hud[18]);
	}
	i->player.hit = i->player.life;
	i->player.backup = event->motion.xrel;
	info_hud(i);
}

void	draw_hud(t_info *info)
{
	info->hud[0] = IMG_Load("hud/hud_gen.png");
	info->hud[1] = IMG_Load("hud/hud_key.png");
	info->hud[3] = IMG_Load("hud/head/1/fst_m.png");
	info->hud[4] = IMG_Load("hud/head/1/fst_r.png");
	info->hud[5] = IMG_Load("hud/head/1/fst_l.png");
	info->hud[6] = IMG_Load("hud/head/2/fst_m.png");
	info->hud[7] = IMG_Load("hud/head/2/fst_r.png");
	info->hud[8] = IMG_Load("hud/head/2/fst_l.png");
	info->hud[9] = IMG_Load("hud/head/3/fst_m.png");
	info->hud[10] = IMG_Load("hud/head/3/fst_r.png");
	info->hud[11] = IMG_Load("hud/head/3/fst_l.png");
	info->hud[12] = IMG_Load("hud/head/4/fst_m.png");
	info->hud[13] = IMG_Load("hud/head/4/fst_r.png");
	info->hud[14] = IMG_Load("hud/head/4/fst_l.png");
	info->hud[15] = IMG_Load("hud/head/h/1.png");
	info->hud[16] = IMG_Load("hud/head/h/2.png");
	info->hud[17] = IMG_Load("hud/head/h/3.png");
	info->hud[18] = IMG_Load("hud/head/h/4.png");
	info->hud[19] = IMG_Load("hud/head/h/dead.png");
}

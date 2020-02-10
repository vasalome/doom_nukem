/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_weapon.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 15:54:11 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 16:51:35 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void    change_item(t_info *info)
{
    if (info->item.hp == 0)
    {
        info->item.info_hp = 1;
    }
    else if (info->item.hp > 0)
    {
        info->item.weapon = 2;
        info->item.info_hp = 0;
    }
    
}

void    put_weapon(t_info *info)
{
    if (info->item.weapon == 1 || info->item.weapon == 3)
        put_text(info, write_text_hud(" equip: Plasma Bolter ", 25), 450, 67);
    else if (info->item.weapon == 2)
        put_text(info, write_text_hud(" equip: Living Leech     ", 25), 450, 67);
    if (info->item.hp == 0)
        put_text(info, write_text_hud(" info: no leech in stock.  ", 20), 450, 100);
}

void    kick(t_info *i)
{
    if (i->item.kick == 1)
    {
        put_texture(i, (t_start){450, 530}, (t_size){237*1.7, 219*1.7}, i->pistol[2]);
        // i->item.weapon = 3; METTRE LE HIT DU KICK
    }
    else if (i->item.kick == 0)
        i->item.weapon = 1;
    i->item.weapon = 1;
}

void    omg_he_got_a_gun(t_info *i)
{
    int     up;
    int     side;

    up = 560 + rand() % 2;
    side = 900 + rand() % 2;
    if (i->item.weapon == 1)
        put_texture(i, (t_start){side, up}, (t_size){237*1.7, 219*1.7}, i->pistol[0]);
    else if (i->item.weapon == 2)
        put_texture(i, (t_start){side, up - 50}, (t_size){237*1.7, 219*1.7}, i->pistol[1]);
}
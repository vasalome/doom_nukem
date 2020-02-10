/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_weapon.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 15:54:11 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 11:31:21 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void    change_item(t_info *info)
{
    printf("%d\n",info->item.hp);
    // if (info->item.hp == 0)
    //     //put_text(info, write_text_hud("NO LEECH IN STOCK", 25), 450, 80); // need to repair this
	// else
        info->item.weapon = 2;
}

void    put_weapon(t_info *info)
{
    if (info->item.weapon == 1)
        put_text(info, write_text_hud(" equip: Plasma Bolter ", 25), 450, 67);
    else if (info->item.weapon == 2)
        put_text(info, write_text_hud(" equip: Living Leech     ", 25), 450, 67);
}

void    omg_he_got_a_gun(t_info *i)
{
    int     up;
    int     side;

    up = 560 + rand() % 10;
    side = 900 + rand() % 10;
    if (i->item.weapon == 1)
        put_texture(i, (t_start){side, up}, (t_size){237*1.7, 219*1.7}, i->pistol[0]);
    else if (i->item.weapon == 2)
        put_texture(i, (t_start){side, up - 50}, (t_size){237*1.7, 219*1.7}, i->pistol[1]);
}
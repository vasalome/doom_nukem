/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_clip.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 16:20:15 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 18:19:06 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

void	clip_10(t_info *info)
{
    printf("\nclip = %d\n",info->map.map[(int)(info->player.x_pos +\
        info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].clip);
    printf("wall = %d\n",info->map.map[(int)(info->player.x_pos +\
        info->player.x_dir * info->player.move_speed)][(int)(info->player.y_pos)].wall);
    printf("x_pos = %.20f\n",info->player.x_pos);
    printf("y_pos = %.20f\n",info->player.y_pos);
    // if (info->player.x_pos != (floor(info->player.x_pos + 0.5))) //|| info->player.x_pos > (floor(info->player.x_pos) + 0.6))
    // {
        printf("oui = %f\n",(floor(info->player.x_pos) + 0.5));
        if (info->player.x_pos + info->player.x_dir * info->player.move_speed\
                != (floor(info->player.x_pos + 0.5)))\
                //&& info->player.x_pos + info->player.x_dir * info->player.move_speed \
                < (floor(info->player.x_pos + 0.6))))
        {
            info->player.x_pos += info->player.x_dir * info->player.move_speed;
            info->player.y_pos += info->player.y_dir * info->player.move_speed;
        }
        else
        {
            printf("dedans\n");
            info->player.x_pos += info->player.x_dir * info->player.move_speed;
            info->player.y_pos += info->player.y_dir * info->player.move_speed;
        }
        ////
        
        if (info->player.x_pos + info->player.x_dir * info->player.move_speed\
                < (floor(info->player.x_pos + 0.6)))
        {
            info->player.x_pos = (floor(info->player.x_pos) + 0.61);
            info->player.x_pos += info->player.x_dir * info->player.move_speed;
        }
        if (info->player.x_pos + info->player.x_dir * info->player.move_speed\
                > (floor(info->player.x_pos + 0.4)))
        {
            info->player.x_pos = (floor(info->player.x_pos) + 0.39);
            info->player.x_pos += info->player.x_dir * info->player.move_speed;
        }
}

void	clip_12(t_info *info)
{
    printf("\nclip = %d\n",info->map.map[(int)(info->player.y_pos +\
        info->player.y_dir * info->player.move_speed)][(int)(info->player.x_pos)].clip);
    printf("wall = %d\n",info->map.map[(int)(info->player.y_pos +\
        info->player.y_dir * info->player.move_speed)][(int)(info->player.x_pos)].wall);
    printf("y_pos = %.20f\n",info->player.y_pos);
    // if (info->player.x_pos != (floor(info->player.x_pos + 0.5))) //|| info->player.x_pos > (floor(info->player.x_pos) + 0.6))
    // {
        printf("oui = %f\n",(floor(info->player.y_pos) + 0.5));
        if (info->player.y_pos + info->player.y_dir * info->player.move_speed\
                != (floor(info->player.y_pos + 0.5)))\
                //&& info->player.y_pos + info->player.y_dir * info->player.move_speed\
                < (floor(info->player.y_pos + 0.6))))
        {
            info->player.y_pos += info->player.y_dir * info->player.move_speed;
            info->player.x_pos += info->player.x_dir * info->player.move_speed;
        }
        else
        {
            printf("dedans\n");
            info->player.y_pos += info->player.y_dir * info->player.move_speed;
            info->player.x_pos += info->player.x_dir * info->player.move_speed;
        }
        ////
        
        if (info->player.y_pos + info->player.y_dir * info->player.move_speed\
                < (floor(info->player.y_pos + 0.6)))
        {
            info->player.y_pos = (floor(info->player.y_pos) + 0.61);
        }
        if (info->player.y_pos + info->player.x_dir * info->player.move_speed\
                > (floor(info->player.y_pos + 0.4)))
        {
            info->player.y_pos = (floor(info->player.y_pos) + 0.39);
        }
}
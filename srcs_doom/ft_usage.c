/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_usage.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/24 19:19:21 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 12:27:41 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

int		red_cross(void)
{
	exit(0);
	return (0);
}

int		ft_usage(char *error)
{
	write(1, "\033[32m\nErreur: \033[0m", 14);
	ft_putstr(error);
	write(1, "\n\n", 2);
	write(1, "\033[31mComment l'utiliser ?\n\n\033[0m", 32);
	write(1, "  Exemple : ./doom_nukem 'map'\n\n \n", 30);
	write(1, "\033[32mChoisis ton level              \n", 37);
	write(1, ". 1 : maps/1.map\n", 17);
	write(1, ". 2 : maps/2.map\n", 17);
	write(1, ". 3 : maps/3.map\n\n", 18);
	write(1, ".etc, ou utilise l'editeur\n", 27);
	write(1, "\033[0m\n", 5);
	exit(0);
	return (64);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_usage.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/24 19:19:21 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/25 17:21:11 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/wolf.h"

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
	write(1, "\033[31mComment l'utiliser ?   \n\033[0m", 34);
	write(1, "\n", 1);
	write(1, "  Exemple : ./wolf3d 'map'     \n", 32);
	write(1, "\n\n", 2);
	write(1, "\033[32mChoisis ta carte               \n", 37);
	write(1, ". 1 : maps/mindfuck.map        \n", 32);
	write(1, ". 2 : maps/big_cube.map        \n", 32);
	write(1, ". 3 : maps/lnieto_1.map        \n", 32);
	write(1, ". 4 : maps/prison_escape.map   \n", 32);
	write(1, ". 5 : maps/test_texture.map    \n", 32);
	write(1, ". 6 : maps/test_tp.map         \n", 32);
	write(1, ".etc, ou crée ta propre carte  \n", 35);
	write(1, "\033[0m\n", 5);
	exit(0);
	return (64);
}

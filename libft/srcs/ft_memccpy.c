/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 13:32:14 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 14:59:49 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	x;
	char			*y;
	const char		*z;

	x = 0;
	y = dst;
	z = src;
	while (x < n)
	{
		y[x] = z[x];
		if (z[x] == (char)c)
			return (y + x + 1);
		x++;
	}
	return (NULL);
}

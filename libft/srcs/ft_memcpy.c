/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 11:55:05 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 10:46:12 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	x;
	unsigned char	*y;
	unsigned char	*z;

	x = 0;
	y = (unsigned char *)dst;
	z = (unsigned char *)src;
	if (n == 0)
		return (y);
	while (x < n)
	{
		y[x] = z[x];
		x++;
	}
	dst = y;
	return (y);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 13:38:18 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 13:32:14 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*x;
	unsigned char	tmp[len];
	unsigned char	*y;
	unsigned int	z;

	if (len > 65535)
		return (NULL);
	x = (unsigned char *)dst;
	y = (unsigned char *)src;
	z = 0;
	while (z < len)
	{
		tmp[z] = y[z];
		z++;
	}
	z = 0;
	while (z < len)
	{
		x[z] = tmp[z];
		z++;
	}
	return (dst);
}

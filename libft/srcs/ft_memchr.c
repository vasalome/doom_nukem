/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 14:23:46 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 14:32:23 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*x;
	unsigned char	y;
	unsigned int	z;

	x = (unsigned char *)s;
	y = (unsigned char)c;
	z = 0;
	if (!n)
		return (NULL);
	while (z < n)
	{
		if (x[z] == y)
			return (x + z);
		z++;
	}
	return (NULL);
}

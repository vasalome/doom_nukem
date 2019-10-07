/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 15:32:40 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 15:46:07 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*x;
	char			y;
	unsigned int	z;
	unsigned int	w;

	x = (char *)s;
	y = (char)c;
	z = 0;
	w = 0;
	while (x[z] != '\0')
	{
		if (x[z] == y)
			w = z;
		z++;
	}
	if (x[w] == y)
		return (x + w);
	if (c == '\0')
		return (x + z);
	return (NULL);
}

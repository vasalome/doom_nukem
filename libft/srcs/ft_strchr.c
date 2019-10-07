/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 15:26:04 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 15:32:02 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*x;
	char			y;
	unsigned int	z;

	x = (char *)s;
	y = (char)c;
	z = 0;
	while (x[z] != '\0')
	{
		if (x[z] == y)
			return (x + z);
		z++;
	}
	if (c == '\0')
		return (x + z);
	return (NULL);
}

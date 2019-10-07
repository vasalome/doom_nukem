/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 15:17:40 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 15:24:43 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	x;
	unsigned int	y;
	char			*w;
	char			*z;

	x = 0;
	y = 0;
	w = (char *)haystack;
	z = (char *)needle;
	if (!*z)
		return (w);
	while (w[y] != '\0' && y < len)
	{
		x = 0;
		if (w[y] == z[0])
		{
			while (w[y + x] == z[x] && z[x] != '\0' && y + x < len)
				x++;
			if (z[x] == '\0')
				return (w + y);
		}
		y++;
	}
	return (NULL);
}

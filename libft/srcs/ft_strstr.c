/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 11:06:52 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 15:16:13 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
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
	while (w[y] != '\0')
	{
		x = 0;
		if (w[y] == z[0])
		{
			while (w[y + x] == z[x] && z[x] != '\0')
				x++;
			if (z[x] == '\0')
				return (w + y);
		}
		y++;
	}
	return (NULL);
}

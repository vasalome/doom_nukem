/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 11:49:20 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 14:07:08 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char				*x;
	unsigned int		z;

	z = 0;
	x = NULL;
	if (s)
	{
		x = ft_strnew(len);
		if (!x)
			return (NULL);
		while (z < len && s[start + z] != '\0')
		{
			x[z] = s[start + z];
			z++;
		}
		x[z] = '\0';
	}
	return (x);
}

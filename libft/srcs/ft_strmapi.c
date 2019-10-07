/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 11:21:22 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 14:52:36 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*x;
	unsigned int	z;

	z = 0;
	x = NULL;
	if (s && f)
	{
		x = ft_strnew(ft_strlen(s));
		if (!x)
			return (NULL);
		while (*s != '\0')
		{
			x[z] = f(z, *s);
			z++;
			s++;
		}
		x[z] = '\0';
	}
	return (x);
}

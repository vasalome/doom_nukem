/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 10:57:56 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 15:49:39 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char	*x;
	int		z;

	z = 0;
	x = NULL;
	if (s && f)
	{
		x = ft_strnew(ft_strlen(s));
		if (!x)
			return (NULL);
		while (*s != '\0')
		{
			x[z] = f(*s);
			z++;
			s++;
		}
		x[z] = '\0';
	}
	return (x);
}

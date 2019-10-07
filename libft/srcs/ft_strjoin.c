/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 11:56:18 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 15:49:18 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*x;

	x = NULL;
	if (s1 && s2)
	{
		x = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!x)
			return (NULL);
		ft_strlcat(x, s1, ft_strlen(s1) + ft_strlen(s2) + 1);
		ft_strlcat(x, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	}
	return (x);
}

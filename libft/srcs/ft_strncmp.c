/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 11:58:35 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 14:49:28 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*j1;
	unsigned char	*j2;

	j1 = (unsigned char *)s1;
	j2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (j1[i] != '\0' && j2[i] != '\0' && i < n)
	{
		if (j1[i] != j2[i])
			return (j1[i] - j2[i]);
		i++;
	}
	if (i == n)
		i--;
	if ((j1[i] == '\0' && j2[i] != '\0') ||
			(j2[i] == '\0' && j1[i] != '\0'))
		return (j1[i] - j2[i]);
	return (j1[i] - j2[i]);
}

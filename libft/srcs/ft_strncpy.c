/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 10:22:32 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 10:51:37 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int x;

	x = 0;
	while (src[x] != '\0' && x < len)
	{
		dst[x] = src[x];
		x++;
	}
	while (x != len)
	{
		dst[x] = '\0';
		x++;
	}
	return (dst);
}

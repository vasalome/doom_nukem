/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 08:16:02 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 13:03:05 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned	int x;
	unsigned	int	y;
	unsigned	int	len;

	len = 0;
	x = 0;
	y = 0;
	while (dst[x] != '\0')
		x++;
	len = ft_strlen(dst);
	if (size > len + 1)
	{
		while (src[y] != '\0' && y < (size - len - 1))
		{
			dst[x] = src[y];
			x++;
			y++;
		}
		dst[x] = '\0';
	}
	if (size < len)
		return (ft_strlen(src) + size);
	return (ft_strlen(src) + len);
}

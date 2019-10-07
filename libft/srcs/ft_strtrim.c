/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 13:16:58 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 12:39:20 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*x;
	int				i;
	int				z;
	unsigned int	y;

	z = -1;
	i = 0;
	y = 0;
	if (!s)
		return (NULL);
	while ((s[y] == ' ' || s[y] == '\n' || s[y] == '\t'))
		y++;
	while (s[y + i] != '\0')
		i++;
	if (!i)
		return (x = ft_strnew(0));
	while (s[y + i] == ' ' || s[y + i] == '\t' ||
			s[y + i] == '\n' || s[y + i] == '\0')
		i--;
	if (!(x = ft_strnew(i + 1)))
		return (NULL);
	while (++z <= i)
		x[z] = s[y + z];
	x[z] = '\0';
	return (x);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 11:02:36 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 11:29:00 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		ft_tab(char *nb, int n, int i)
{
	nb[i--] = ((n % 10) + 48);
	if (n >= 10)
		ft_tab(nb, (n / 10), i);
}

static char		*ft_spe(int n)
{
	char	*nb;

	if (n == -2147483648)
	{
		nb = ft_strnew(11);
		nb[11] = '\0';
		nb[0] = '-';
		nb[1] = '2';
		ft_tab(nb, 147483648, 10);
		return (nb);
	}
	nb = ft_strnew(1);
	nb[0] = '0';
	nb[1] = '\0';
	return (nb);
}

char			*ft_itoa(int n)
{
	char	*nb;
	int		i[2];

	i[0] = n;
	i[1] = 0;
	if (n == -2147483648 || n == 0)
		return (ft_spe(n));
	while (i[0] != 0 && i[1]++ >= 0)
		i[0] /= 10;
	if (n < 0)
	{
		if (!(nb = ft_strnew(i[1] + 1)))
			return (NULL);
		nb[i[1]] = '\0';
		nb[0] = '-';
		ft_tab(nb, -n, i[1]);
	}
	else
	{
		if (!(nb = ft_strnew(i[1])))
			return (NULL);
		nb[i[1] - 1] = '\0';
		ft_tab(nb, n, i[1] - 1);
	}
	return (nb);
}

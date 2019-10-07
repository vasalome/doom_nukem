/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   splitwhitespace.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 10:28:54 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 11:28:27 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		let(char *str, int i, char c)
{
	int	nbletters;

	nbletters = 0;
	while ((str[i] != c) && str[i])
	{
		nbletters++;
		i++;
	}
	return (nbletters);
}

static int		nb_words(char *str, char c)
{
	int i;
	int isword;
	int isspace;
	int nbwords;

	i = 0;
	isword = 0;
	isspace = 1;
	nbwords = 0;
	while (str[i])
	{
		if ((str[i] != c) && !isword)
		{
			isword = 1;
			isspace = 0;
			nbwords++;
		}
		if ((str[i] == c) && !isspace)
		{
			isspace = 1;
			isword = 0;
		}
		i++;
	}
	return (nbwords);
}

static char		**ft_whitespaces(char const *s, char c)
{
	int			i;
	int			j;
	int			k;
	char		**tab;

	tab = NULL;
	j = 0;
	i = 0;
	if (!(tab = malloc(sizeof(char *) * (nb_words((char *)s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			k = 0;
			tab[j] = malloc(sizeof(char) * let((char *)s, i, c) + 1);
			while (s[i] != c && s[i])
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	if (s)
		return (ft_whitespaces(s, c));
	return (NULL);
}

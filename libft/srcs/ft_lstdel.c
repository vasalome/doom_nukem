/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 15:01:08 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 15:12:14 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list	*alst2;

	alst2 = NULL;
	while ((*alst)->next)
	{
		del((*alst)->content, (*alst)->content_size);
		alst2 = (*alst);
		*alst = (*alst)->next;
		free(alst2);
		alst2 = NULL;
	}
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}

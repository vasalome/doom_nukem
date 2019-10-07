/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstiter.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 15:25:39 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 15:41:49 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f) (t_list *elem))
{
	t_list	*lst2;

	lst2 = lst->next;
	while (lst->next != NULL)
	{
		f(lst);
		lst = lst2;
		lst2 = lst->next;
	}
	f(lst);
}

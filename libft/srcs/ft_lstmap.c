/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 15:42:08 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 15:52:04 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*frst;

	tmp = f(lst);
	frst = tmp;
	lst = lst->next;
	while (lst)
	{
		tmp2 = f(lst);
		tmp->next = tmp2;
		tmp = tmp2;
		lst = lst->next;
	}
	return (frst);
}

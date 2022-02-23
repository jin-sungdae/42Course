/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 19:45:33 by sjin              #+#    #+#             */
/*   Updated: 2020/12/28 11:49:13 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_next;
	t_list	*new_node;

	if (!lst)
		return (NULL);
	if (!(new_head = ft_lstnew(f(lst->content))))
		return (NULL);
	new_node = new_head;
	lst = lst->next;
	while (lst)
	{
		if (!(new_next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		new_node->next = new_next;
		new_node = new_next;
		lst = lst->next;
	}
	return (new_head);
}

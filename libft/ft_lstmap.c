/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:58:15 by abisiani          #+#    #+#             */
/*   Updated: 2025/06/10 21:33:51 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_llist;
	t_list	*new_node;
	void	*content;

	new_llist = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			if (new_llist)
				ft_lstclear(&new_llist, del);
			return (NULL);
		}
		if (new_llist)
			ft_lstadd_back(&new_llist, new_node);
		else
			new_llist = new_node;
		lst = lst->next;
	}
	return (new_llist);
}

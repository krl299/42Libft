/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:35:34 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 18:39:23 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Deletes and frees the given node and every
// successor of that node, using the function ’del’
// and free(3).
// Finally, the pointer to the list must be set to
// NULL.
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (!lst || !*lst)
		return ;
	node = (*lst)->next;
	while (node)
	{
		ft_lstdelone(*lst, del);
		*lst = node;
		node = (*lst)->next;
	}
	ft_lstdelone(*lst, del);
	*lst = 0;
}

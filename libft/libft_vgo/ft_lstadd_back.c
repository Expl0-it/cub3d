/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:53:31 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/07 19:41:40 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
 * @brief Add node to the end of the list
 *
 * Adds the node ’new’ at the end of the list.
 *
 * @param lst The address of a pointer to the first link
 * @param new The address of a pointer to the node to be added
 * @return Void
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (NULL != lst && NULL != new)
	{
		if (NULL != *lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}

/*
#include <stdio.h>
int main(void)
{
	t_list	*node1 = ft_lstnew("123");
	t_list	*node2 = ft_lstnew("abc");
	if (NULL == node1 || NULL == node2)
	{
		return (1);
	}
	ft_lstadd_back(&node1, node2);
	printf("%p\n", node1->next);
	printf("%p", node2->next);
	return EXIT_SUCCESS;
}
*/

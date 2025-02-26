/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:46:35 by mamichal          #+#    #+#             */
/*   Updated: 2024/02/05 15:43:45 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/** @brief Free memory area.
 * 
 * 	Takes as a parameter the address of a memory area that needs 
 *	to be freed with free(3), then puts the pointer to NULL
 *
 *  @param ap pointer’s address that needs its memory freed and set to NULL.
 *  @return Void
 */
void	ft_memdel(void **ap)
{
	if (ap != NULL && *ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}

/*
#include <stdio.h>
int main(void)
{
	//void	*memory = ft_memalloc(4);
	//void	*memory = malloc(4*sizeof(char));
	printf("%p\n", memory);
	ft_memdel(&memory);
	printf("%p\n", memory);
	return 0;
}
*/

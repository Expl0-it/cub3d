/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:49:42 by mamichal          #+#    #+#             */
/*   Updated: 2024/02/05 15:52:41 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/** @brief Free memory area.
 * 
 * 	Takes as a parameter the address of a string that need to be
 * 	freed with free(3), then sets its pointer to NULL.
 *
 *  @param string’s address that needs to be freed
 *  @return Void
 */
void	ft_strdel(char **as)
{
	if (as != NULL && *as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

/*
#include <stdio.h>
int main(void)
{
	char	*str = ft_strnew(2);
	printf("%p\n", str);
	ft_strdel(&str);
	printf("%p\n", str);
	return 0;
}
*/

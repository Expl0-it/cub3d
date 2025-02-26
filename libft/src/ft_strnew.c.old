/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:47:10 by mamichal          #+#    #+#             */
/*   Updated: 2024/02/01 19:47:11 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/** @brief Allocate a string.
 * 
 * 	Allocates (with malloc(3)) and returns a “fresh” string
 *  ending with ’\0’. Each character of the string is initialized at
 * 	’\0’. If the allocation fails the function returns NULL.
 * 
 * 	@param size the size of the string to be allocated
 *  @return the string allocated and initialized to 0.
 */
char	*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc(size + 1));
}

/*
#include <stdio.h>
int main(void)
{
	char	*str = ft_strnew(2);
	printf("%p", str);
	free(str);
	return 0;
}
*/

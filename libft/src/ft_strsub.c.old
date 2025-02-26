/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:47:58 by mamichal          #+#    #+#             */
/*   Updated: 2024/02/05 16:06:03 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/** @brief Allocate a substring.
 * 
 * 	Allocates (with malloc(3)) and returns a “fresh” substring
 * 	from the string given as argument. The substring begins at
 * 	indexstart and is of size len. If start and len aren’t refering
 *  to a valid substring, the behavior is undefined. If the
 * 	allocation fails, the function returns NULL.
 * 
 * 	@param s string from which create the substring
 * 	@param start starting index of the substring
 * 	@param len maximum size of the substring
 *  @return the allocated substring
 */
char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	j;

	sub = ft_strnew(len);
	i = 0;
	j = 0;
	while (i < start)
	{
		i++;
	}
	while (j < len)
	{
		sub[j] = s[i];
		i++;
		j++;
	}
	return (sub);
}

/*
#include <stdio.h>
int main(void)
{
    char    *a = ft_strsub("abcdefghijk", 3, 5);
    printf("%s", a);
    return (0);
}
*/

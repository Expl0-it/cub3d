/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:48:10 by mamichal          #+#    #+#             */
/*   Updated: 2024/02/05 16:05:14 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/** @brief Locate a substring.
 * 
 * 	The strnstr() function finds the first occurrence
 *  of the substring needle in the string haystack.
 *  The terminating null bytes ('\0') are not compared.
 * 
 * 	@param haystack a string to scan
 * 	@param needle a string to find
 *  @return pointer to the beginning of the substring, or NULL if not found
 */
char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle == NULL || needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] != 0)
			j++;
		if (needle[j] == 0)
		{
			haystack += i;
			return ((char *)haystack);
		}
		i++;
	}
	return (NULL);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char *a = ft_strstr("abcdbadx", "bad");
	char *b = strstr("abacbadx", "bad");
	printf("%s, %s", a, b);
	return 0;
}
*/

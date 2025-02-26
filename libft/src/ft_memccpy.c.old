/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:44:53 by mamichal          #+#    #+#             */
/*   Updated: 2024/02/05 15:36:50 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/** @brief Copy memory area.
 * 
 * 	Copies no more than n bytes from memory area src to memory area dest,
 * 	stopping when the character c is found.
 * 	If the memory areas overlap, the results are undefined.
 *
 * 	@param dest memory area to copy to
 * 	@param src memory area to copy from
 *  @param c int value of character to be found within memory
 * 	@param n maximal number of bytes to copy
 *  @return a pointer to the next character in dest after c, or NULL if not found
 */
void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	while (n-- > 0)
	{
		*p_dest = *p_src;
		if (*p_src == (unsigned char)c)
			return ((void *)p_dest + 1);
		p_src++;
		p_dest++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int main(void)
{
	char	*a = "abcdefg";
	char	b[10];
	char	*p_b = ft_memccpy(b, a, 'c', 8);
	printf("%s, %s", p_b, b);
	return 0;
}
*/

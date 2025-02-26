/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:47:04 by mamichal          #+#    #+#             */
/*   Updated: 2024/02/05 15:59:17 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/** @brief Allocate a modified string.
 * 
 * 	Applies the function ’f’ to each character of the
 * 	string ’s’ to create a new string (with malloc(3))
 * 	resulting from successive applications of ’f’.

 *
 *  @param s the reference string
 * 	@param f the function to apply to each character
 *  @return string created from the applications of ’f’ or NULL at fail
 */
char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new;

	if (f && s)
	{
		i = 0;
		new = ft_strnew(ft_strlen(s));
		while (s[i])
		{
			new[i] = f(s[i]);
			i++;
		}
		return (new);
	}
	return (NULL);
}

/*

char	f(char c)
{
	if (c >= 32 && c <= 125)
	{
		c = c + 1;
	}
	
	return (c);
}

#include <stdio.h>
int main(void)
{
	char	*b = "abc";
	char	*a = ft_strmap(b, f);
	printf("%s", a);
	return 0;
}
*/

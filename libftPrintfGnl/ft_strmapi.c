/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:54:48 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/05/22 17:31:21 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*s1;
	int		i;

	i = 0;
	s1 = (char *)s;
	str = malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = (*f)(i, s1[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

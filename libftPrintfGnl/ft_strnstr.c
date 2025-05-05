/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:20:17 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/05/22 17:31:25 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lt, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (lt[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (0);
	while (big[i] && i < len)
	{
		while (big[i + j] == lt[j] && big[i + j] && i + j < len)
		{
			j++;
			if (lt[j] == 0)
				return ((char *)big + i);
		}
		i++;
		j = 0;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:26:06 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/05/22 17:30:58 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(ft_strlen((char *)(s1)) + ft_strlen((char *)(s2)) + 1);
	if (!res)
		return (0);
	while ((s1)[i])
	{
		res[i] = (s1)[i];
		i++;
	}
	while ((s2)[j])
	{
		res[i] = (s2)[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

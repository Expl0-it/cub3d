/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:49:12 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/03/13 16:32:09 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_trim(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_i;
	size_t	end_i;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start_i = 0;
	end_i = ft_strlen((char *)s1);
	while (to_trim(set, s1[start_i]))
		start_i++;
	if (start_i == end_i)
		return (ft_strdup(""));
	while (to_trim(set, s1[end_i - 1]))
		end_i--;
	trimmed = ft_substr(s1, start_i, end_i - start_i);
	return (trimmed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:28:14 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/05/22 17:30:10 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr_dst;
	char	*ptr_src;
	size_t	i;

	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	i = 0;
	if (!dst && !src)
		return (dst);
	else
	{
		while (i < n)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
		}
		return (ptr_dst);
	}
}

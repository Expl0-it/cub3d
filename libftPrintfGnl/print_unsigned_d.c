/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:19:50 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/05/22 17:38:37 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	unsigned_d_len(unsigned int nbr)
{
	int	c;

	c = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		c++;
	}
	return (c);
}

static char	*ft_udtoa(unsigned int n)
{
	unsigned int	nbr;
	int				length;
	char			*result;
	int				i;

	nbr = n;
	length = unsigned_d_len(nbr);
	result = malloc(length * sizeof(char) + 1);
	if (!result)
		return (0);
	if (nbr == 0)
		result[0] = '0';
	i = length - 1;
	while (nbr != 0)
	{
		result[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	result[length] = '\0';
	return (result);
}

int	print_unsigned_d(unsigned int number)
{
	char	*string;

	string = ft_udtoa(number);
	print_string(string);
	free(string);
	return (unsigned_d_len(number));
}

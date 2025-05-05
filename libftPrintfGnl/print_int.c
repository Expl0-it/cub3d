/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:15:21 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/05/22 17:38:09 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	int_len(long nbr)
{
	int	c;

	c = 0;
	if (nbr < 0)
	{
		c++;
		nbr = -nbr;
	}
	if (nbr == 0)
		c++;
	while (nbr != 0)
	{
		nbr /= 10;
		c++;
	}
	return (c);
}

// char	*ft_itoa(int n)
// {
// 	long	nbr;
// 	int		length;
// 	char	*result;
// 	int		i;

// 	nbr = n;
// 	length = int_len(nbr);
// 	result = malloc(length * sizeof(char) + 1);
// 	if (!result)
// 		return (0);
// 	if (nbr == 0)
// 		result[0] = '0';
// 	if (nbr < 0)
// 		nbr = -nbr;
// 	i = length - 1;
// 	while (nbr != 0)
// 	{
// 		result[i] = ((nbr % 10) + 48);
// 		nbr = nbr / 10;
// 		i--;
// 	}
// 	if (n < 0)
// 		result[0] = '-';
// 	result[length] = '\0';
// 	return (result);
// }

int	print_int(int number)
{
	char	*string;

	string = ft_itoa(number);
	print_string(string);
	free(string);
	return (int_len(number));
}

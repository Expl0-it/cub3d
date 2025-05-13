/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:58:53 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/05/22 17:38:22 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits_ptr(uintptr_t number)
{
	int	i;

	i = 0;
	if (number == 0)
		return (1);
	while (number > 0)
	{
		number /= 16;
		i++;
	}
	return (i);
}

int	print_pointer(void *number)
{
	char		*symbols;
	char		*result;
	int			counter;
	uintptr_t	nbr;
	int			res_int;

	if (!number)
		return (print_string("(nil)"));
	nbr = (uintptr_t)number;
	symbols = "0123456789abcdef";
	counter = count_digits_ptr(nbr);
	result = malloc(counter * sizeof(char) + 1);
	if (!result)
		return (0);
	result[counter] = '\0';
	print_string("0x");
	while (counter-- > 0)
	{
		result[counter] = symbols[nbr % 16];
		nbr /= 16;
	}
	print_string(result);
	res_int = ft_strlen(result);
	free(result);
	return (res_int + 2);
}

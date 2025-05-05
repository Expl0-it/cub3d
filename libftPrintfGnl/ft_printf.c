/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:17:21 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/05/23 19:22:51 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_print(char c, va_list args)
{
	if (c == 'c')
		return (print_char(va_arg(args, int)));
	if (c == 's')
		return (print_string(va_arg(args, char *)));
	if (c == 'i' || c == 'd')
		return (print_int(va_arg(args, int)));
	if (c == 'u')
		return (print_unsigned_d(va_arg(args, unsigned int)));
	if (c == 'p')
		return (print_pointer(va_arg(args, void *)));
	if (c == 'x' || c == 'X')
		return (print_hexadecimal(va_arg(args, unsigned int), c));
	if (c == '%')
		return (print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			counter += my_print(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			counter++;
		}
		i++;
	}
	va_end(args);
	return (counter);
}

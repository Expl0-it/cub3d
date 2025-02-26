/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:38:22 by mamichal          #+#    #+#             */
/*   Updated: 2024/02/20 18:05:31 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/** @brief Put a string followed by new line in file.
 * 
 * 	Outputs the string ’s’ to the given file
 * 	descriptor, followed by a newline.
 * 	STDFD:
 * 	0 => stdin;
 * 	1 => stdout;
 * 	2 => stderr;
 * 
 * 	@param s The string to output
 * 	@param fd The file descriptor on which to write
 *  @return Void.
 */
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*
int main(void)
{
	ft_putendl_fd("abc", 1);
	return (0);
}
*/

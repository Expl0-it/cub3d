/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:08:09 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/03/11 11:46:38 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int i)
{
	if (ft_isalpha(i) == 1)
		return (1);
	else if (ft_isdigit(i) == 1)
		return (1);
	else
		return (0);
}

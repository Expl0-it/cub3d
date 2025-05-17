/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:35:55 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/05/17 12:44:56 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **splitted)
{
	int	i;

	if (!splitted)
		return ;
	i = -1;
	while (splitted[++i])
		free(splitted[i]);
	free(splitted);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:35:55 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/05/05 17:35:57 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_free_split(char **splitted)
{
	int	i;

	i = -1;
	while (splitted[++i])
		free(splitted[i]);
	free(splitted);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:48:43 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/05/17 14:49:41 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_rows(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	count_columns(char **arr)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
			j++;
		if (j > count)
			count = j;
		i++;
	}
	return (count);
}

bool	has_valid_border(char **map)
{
	int	rows;
	int	cols;
	int	i;

	rows = count_rows(map);
	cols = count_columns(map);
	i = 0;
	while (i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}
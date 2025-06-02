/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:48:43 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/06/02 13:13:07 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_rows(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static int	count_columns(char **arr)
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

static void	pad_row(char **map, int i, int max_len)
{
	int		len;
	int		k;
	char	*new_row;

	len = ft_strlen(map[i]);
	k = 0;
	while (map[i][k] == ' ')
		map[i][k++] = '1';
	if (len < max_len)
	{
		new_row = malloc(max_len + 1);
		if (!new_row)
		{
			print_error("Failed to allocate padded row");
			exit(1);
		}
		ft_memcpy(new_row, map[i], len);
		ft_memset(new_row + len, '1', max_len - len);
		new_row[max_len] = '\0';
		free(map[i]);
		map[i] = new_row;
	}
}

void	pad_map_rows(char **map)
{
	int	max_len;
	int	i;

	max_len = count_columns(map);
	i = 0;
	while (map[i])
	{
		pad_row(map, i, max_len);
		i++;
	}
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

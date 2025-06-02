/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:48:43 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/06/02 17:17:30 by mbudkevi         ###   ########.fr       */
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

static bool	flood_fill(char **map, int x, int y, int rows)
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;

	if (x < 0 || y < 0 || y >= rows || x >= (int)ft_strlen(map[y]))
		return (false);
	if (map[y][x] == ' ')
		return (false);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (true);
	map[y][x] = 'V';
	up = flood_fill(map, x, y - 1, rows);
	down = flood_fill(map, x, y + 1, rows);
	left = flood_fill(map, x - 1, y, rows);
	right = flood_fill(map, x + 1, y, rows);
	return (up && down && left && right);
}

bool	is_map_closed(char **map)
{
	int		y;
	int		x;
	bool	found;

	y = 0;
	found = false;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSEW", map[y][x]))
			{
				found = true;
				break ;
			}
			x++;
		}
		if (found)
			break ;
		y++;
	}
	if (!found)
		return (false);
	return (flood_fill(map, x, y, count_rows(map)));
}

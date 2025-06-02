/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:10:50 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/06/02 17:09:48 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	replace_spaces_with_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}

static void	fill_empty_spots(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (map[i])
	{
		j = 0;
		k = ft_strlen(map[i]) - 1;
		while (map[i][j] == ' ' && map[i][j])
			j++;
		while (map[i][k] == ' ' && k > j)
			k--;
		while (map[i][j] && j < k)
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}

void	prepare_and_assign_map(t_data *data, char *map, t_game *game)
{
	char	**split_map;
	char	**map_copy;

	split_map = ft_split(map, '\n');
	map_copy = ft_split(map, '\n');
	free(map);
	replace_spaces_with_walls(map_copy);
	if (is_map_closed(map_copy) == false)
	{
		ft_free_split(map_copy);
		ft_free_split(split_map);
		clean_and_exit("Map doesn't have valid borders!\n", game);
	}
	fill_empty_spots(split_map);
	data->map = split_map;
	ft_free_split(map_copy);
}

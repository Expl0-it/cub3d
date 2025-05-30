/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validaion_helpers2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:10:50 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/05/30 17:50:53 by mbudkevi         ###   ########.fr       */
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

char	*build_map_string(int fd, char *line, t_game *game)
{
	char	*map;
	char	*tmp_map;

	map = ft_strdup("");
	if (!map)
		clean_and_exit("Memory allocation at assign map has failed\n", game);
	while (line)
	{
		tmp_map = map;
		map = ft_strjoin(tmp_map, line);
		free(tmp_map);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

void	validate_map_string(char *map, t_game *game)
{
	if (!map || validate_chars_players(map) == -1)
	{
		free(map);
		clean_and_exit("Validation chars has failed\n", game);
	}
}

void	prepare_and_assign_map(t_data *data, char *map, t_game *game)
{
	char	**split_map;
	char	**map_copy;

	split_map = ft_split(map, '\n');
	map_copy = ft_split(map, '\n');
	free(map);
	pad_map_rows(map_copy);
	replace_spaces_with_walls(map_copy);
	if (!has_valid_border(map_copy))
	{
		ft_free_split(map_copy);
		ft_free_split(split_map);
		clean_and_exit("Map doesn't have valid borders!\n", game);
	}
	fill_empty_spots(split_map);
	data->map = split_map;
	ft_free_split(map_copy);
}

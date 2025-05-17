/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:04:52 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/05/17 16:01:45 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pad_map_rows(char **map)
{
	int		max_len;
	int		i;
	int		k;
	int		len;
	char	*new_row;

	max_len = count_columns(map);
	i = 0;
	while (map[i])
	{
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
		i++;
	}
}

void	replace_spaces_with_walls(char **map)
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

/*
- check there is no new line in the middle of the map
- check there are only characters we expect
- check amount of players
*/
int	validate_chars_players(char *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (print_error("Empty line in the middle of map found"), -1);
		if (ft_strchr("01 \n", map[i]))
			i++;
		else if (ft_strchr("NSEW", map[i]) && ++j)
			i++;
		else
			return (print_error("Unexpected character in map"), -1);
	}
	if (j != 1)
		return (print_error("Too many or too few players"), -1);
	return (0);
}

void	fill_empty_spots(char **map)
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

/*
- read the rest of file(map) and append each line to map
- check characters
- split map
- assign to our structure
*/
void	assign_map(t_data *data, char *line, int fd)
{
	char	*map;
	char	*tmp_map;
	char	**split_map;
	char	**map_copy;

	if (!line)
		clean_and_exit("Empty or invalid map\n", data, fd);
	map = ft_strdup("");
	if (!map)
		clean_and_exit("Memory allocation at assign map has failed\n", data, fd);
	while (line)
	{
		tmp_map = map;
		map = ft_strjoin(tmp_map, line);
		free(tmp_map);
		free(line);
		line = get_next_line(fd);
	}
	if (validate_chars_players(map) == -1)
	{
		free(map);
		clean_and_exit("Validation chars has failed\n", data, fd);
	}
	close(fd);
	split_map = ft_split(map, '\n');
	map_copy = ft_split(map, '\n');
	free(map);
	pad_map_rows(map_copy);
	replace_spaces_with_walls(map_copy);
	if (!has_valid_border(map_copy))
	{
		ft_free_split(map_copy);
		ft_free_split(split_map);
		clean_and_exit("Map doesn't have valid borders!\n", data, fd);
	}
	fill_empty_spots(split_map);
	data->map = split_map;
	ft_free_split(map_copy);
}

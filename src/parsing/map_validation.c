/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:04:52 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/06/02 13:16:11 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*build_map_string(int fd, char *line, t_game *game)
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

/*
- check there is no new line in the middle of the map
- check there are only characters we expect
- check amount of players
*/
static int	validate_chars_players(char *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (print_error("Empty line in the middle of map found\n"), -1);
		if (ft_strchr("01 \n", map[i]))
			i++;
		else if (ft_strchr("NSEW", map[i]) && ++j)
			i++;
		else
			return (print_error("Unexpected character in map\n"), -1);
	}
	if (j != 1)
		return (print_error("Too many or too few players\n"), -1);
	return (0);
}

static void	validate_map_string(char *map, t_game *game)
{
	if (!map || validate_chars_players(map) == -1)
	{
		free(map);
		clean_and_exit("Validation chars has failed\n", game);
	}
}

static char	*trim_trailing_newlines(char *str)
{
	int		len;
	char	*trimmed;

	len = ft_strlen(str);
	while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == ' '))
		len--;
	trimmed = ft_substr(str, 0, len);
	free(str);
	return (trimmed);
}

/*
- read the rest of file(map) and append each line to map
- check characters
- split map
- assign to our structure
*/
void	assign_map(t_data *data, char *line, t_game *game, int fd)
{
	char	*map;

	if (!line)
		clean_and_exit("Empty or invalid map\n", game);
	map = build_map_string(fd, line, game);
	map = trim_trailing_newlines(map);
	validate_map_string(map, game);
	prepare_and_assign_map(data, map, game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:04:52 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/05/06 17:24:15 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
- check there is no new line in the middle of the map
- check there are only characters we expect
- check amount of players
*/
void	validate_chars(t_data *data, int fd, char *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (clean_file(data, fd), free(map), \
			print_error("Empty line in the middle of map found"));
		if (ft_strchr("01 \n", map[i]))
			i++;
		else if (ft_strchr("NSEW", map[i]) && ++j)
			i++;
		else
			return (clean_file(data, fd), free(map), \
			print_error("Unexpected character in map"));
	}
	if (j != 1)
		return (clean_file(data, fd), free(map), \
		print_error("Too many or too few players"));
}

/*
- read the rest of file(map) and append each line to map
- check characters
- split map
- assign to our structure
*/
void	create_map(t_data *data, char *line, int fd)
{
	char	*map;
	char	*tmp_map;
	char	**split_map;

	map = ft_strdup("");
	while (line)
	{
		tmp_map = map;
		map = ft_strjoin(tmp_map, line);
		free(tmp_map);
		free(line);
		line = get_next_line(fd);
	}
	validate_chars(data, fd, map);
	close(fd);
	split_map = ft_split(map, '\n');
	free(map);
	data->map = split_map;
	//validate_map(data);
}

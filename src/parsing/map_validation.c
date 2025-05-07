/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:04:52 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/05/07 13:44:08 by mbudkevi         ###   ########.fr       */
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

int	count_rows_for_column(char **arr, int col)
{
	int	row;

	row = 0;
	while (arr[row])
	{
		if (col < 0 || col >= (int)ft_strlen(arr[row]))
			break ;
		row++;
	}
	return (row);
}

bool	map_open_h(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]) - 1;
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] != '1' || map[i][len] != '1')
			return (true);
		i++;
	}
	return (false);
}

/*
- get total number of columns
- iterate over each of them
- get 1st and last row for each column
- skip first spaces
- check if the first char is 1

*/

bool	map_open_v(char **map)
{
	int	f_row;
	int	l_row;
	int	columns;
	int	cur_col;

	columns = count_columns(map);
	cur_col = 0;
	while (cur_col < columns)
	{
		f_row = 0;
		l_row = count_rows_for_column(map, cur_col) - 1;
		while (map[f_row][cur_col] == ' ')
			f_row++;
		if (map[f_row][cur_col] != '1')
			return (true);
		while (!map[l_row][cur_col])
			l_row--;
		while (l_row >= 0
			&& (map[l_row][cur_col] == ' ' || map[l_row][cur_col] == '\0'))
			l_row--;
		if (map[l_row][cur_col] != '1')
			return (true);
		cur_col++;
	}
	return (false);
}

bool	map_is_closed(char **map)
{
	if (map_open_h(map) || map_open_v(map))
		return (false);
	return (true);
}

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

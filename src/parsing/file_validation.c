/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:07:41 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/05/30 17:44:12 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
- check paths for textures exist
- check map extension
- check colors exist
- check file can be opened and read
*/
static int	validate_data(t_data *data)
{
	int	i;
	int	check_file;

	i = -1;
	while (++i <= 5)
	{
		if (i <= 3 && !data->elements[i].path)
			return (print_error("Missing texture\n"), -1);
		else if (i <= 3 && check_ext(data->elements[i].path, ".xpm"))
			return (print_error("Wrong texture file format\n"), -1);
		else if (i >= 4 && data->elements[i].rgb_letter[0] == -1)
			return (print_error("Color is missing!\n"), -1);
		else if (i <= 3 && data->elements[i].path)
		{
			check_file = open(data->elements[i].path, O_RDONLY);
			if (check_file == -1)
				return (print_error("Couldn't open the file\n"), -1);
			close(check_file);
		}
	}
	return (0);
}

static int	process_line(char *line, t_data *data, t_game *game)
{
	char	**split_result;
	int		result;

	split_result = ft_multi_split(line, " \n");
	result = check_path(data, split_result);
	if (result == -1)
	{
		ft_free_split(split_result);
		free(line);
		clean_and_exit("Error\n", game);
	}
	else if (result == 1)
	{
		ft_free_split(split_result);
		return (1);
	}
	ft_free_split(split_result);
	return (0);
}

static void	validate_data_or_exit(t_data *data, char *line, t_game *game)
{
	if (validate_data(data) == -1)
	{
		free(line);
		clean_and_exit("Error\n", game);
	}
}

void	init_validate_data(char *path, t_data *data, t_game *game)
{
	int		fd;
	char	*line;
	int		result;

	init_elements(data);
	fd = open_file(path);
	if (fd == -1)
		clean_and_exit("Error\n", game);
	line = get_next_line(fd);
	while (line)
	{
		result = process_line(line, data, game);
		if (result == 1)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	validate_data_or_exit(data, line, game);
	assign_map(data, line, game, fd);
}

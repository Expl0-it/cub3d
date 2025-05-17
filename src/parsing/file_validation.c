/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:07:41 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/05/17 15:48:57 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
give initial values to our elements(NO, SO, WE, EA, F, C)
if it is direction -> initial value is NULL
if it is a color -> -1
*/

void	init_elements(t_data *data)
{
	int	i;

	i = 0;
	data->map = NULL;
	data->elements[0].element_id = NO;
	data->elements[1].element_id = SO;
	data->elements[2].element_id = WE;
	data->elements[3].element_id = EA;
	data->elements[4].element_id = F;
	data->elements[5].element_id = C;
	while (i < 6)
	{
		data->elements[i].path = NULL;
		data->elements[i].rgb_letter[0] = -1;
		data->elements[i].rgb_letter[1] = -1;
		data->elements[i].rgb_letter[2] = -1;
		i++;
	}
}

/*check extension of the file. make sure it is a ".cub"*/

int	check_ext(char *str, char *ext)
{
	size_t	len;

	len = ft_strlen(str);
	if (len >= 4)
		return (ft_strncmp(&str[len - 4], ext, ft_strlen(ext)));
	return (-1);
}

int	open_file(char *path)
{
	int	fd;

	if (check_ext(path, ".cub") != 0)
	{
		print_error("Wrong file format\n");
		return (-1);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		print_error("Invalid file descriptor\n");
		return (-1);
	}
	return (fd);
}

/*
- split into char **
- check there are only 3 elements
- check they are within 0-255
*/
int	handle_rgb(t_data *data, char **split_line)
{
	char	**split_colors;
	int		i;

	if (ft_strncmp(split_line[0], "F", ft_strlen(split_line[0])) == 0)
		i = 4;
	else
		i = 5;
	split_colors = ft_split(split_line[1], ',');
	if (!split_colors[0] || !split_colors[1] || !split_colors[2] || \
		split_colors[3])
		return (print_error("Wrong color numbers in file\n"), -1);
	data->elements[i].rgb_letter[0] = ft_rgb_atoi(split_colors[0]);
	data->elements[i].rgb_letter[1] = ft_rgb_atoi(split_colors[1]);
	data->elements[i].rgb_letter[2] = ft_rgb_atoi(split_colors[2]);
	if (data->elements[i].rgb_letter[0] > 255 \
	|| data->elements[i].rgb_letter[1] > 255 \
	|| data->elements[i].rgb_letter[2] > 255 \
	|| data->elements[i].rgb_letter[0] < 0 || data->elements[i].rgb_letter[1] < 0 \
	|| data->elements[i].rgb_letter[2] < 0)
		return (print_error("Wrong color number\n"), -1);
	ft_free_split(split_colors);
	return (0);
}

/*check if paths have already been assigned to our data struct, if not -> assign*/

int	add_path(t_data *data, char **split_line)
{
	if (ft_strncmp(split_line[0], "NO", ft_strlen(split_line[0])) == 0 && !data->elements[0].path)
		return (data->elements[0].path = ft_strdup(split_line[1]), 0);
	else if (ft_strncmp(split_line[0], "SO", ft_strlen(split_line[0])) == 0 && !data->elements[1].path)
		return (data->elements[1].path = ft_strdup(split_line[1]), 0);
	else if (ft_strncmp(split_line[0], "WE", ft_strlen(split_line[0])) == 0 && !data->elements[2].path)
		return (data->elements[2].path = ft_strdup(split_line[1]), 0);
	else if (ft_strncmp(split_line[0], "EA", ft_strlen(split_line[0])) == 0 && !data->elements[3].path)
		return (data->elements[3].path = ft_strdup(split_line[1]), 0);
	else if ((ft_strncmp(split_line[0], "F", ft_strlen(split_line[0])) == 0 \
	&& data->elements[4].rgb_letter[0] == -1))
	{
		if (handle_rgb(data, split_line) == -1)
			return (-1);
	}
	else if (ft_strncmp(split_line[0], "C", ft_strlen(split_line[0])) == 0 \
	&& data->elements[5].rgb_letter[0] == -1)
	{
		if (handle_rgb(data, split_line) == -1)
			return (-1);
	}
	else
		return (print_error("Wrong id or a duplicate\n"), -1);
	return (0);
}

/*
- skip empty line,
- check if it is a map
- check there are exactly 2 arguments 
*/
int	check_path(t_data *data, char **split_res)
{
	if (!split_res[0])
		return (0);
	if (ft_strchr(split_res[0], '1'))
		return (1);
	if (!split_res[1] || split_res[2])
		return (print_error("Wrong elements in file\n"), -1);
	if (add_path(data, split_res) == -1)
		return (-1);
	return (0);
}

/*
- check paths for textures exist
- check map extension
- check colors exist
- check file can be opened and read
*/

int	validate_data(t_data *data)
{
	int	i;
	int	check_file;

	i = -1;
	while (++i <= 5)
	{
		if (i <= 3 && !data->elements[i].path)
			return (print_error("Missing texture\n"), -1);
		else if (i <= 3 && check_ext(data->elements[i].path, ".xpm"))
			return (print_error("Wrong file format\n"), -1);
		else if (i >= 4 && data->elements[i].rgb_letter[0] == -1)
			return (print_error("Color is missing!\n"), -1);
		else if (i <= 3)
		{
			check_file = open(data->elements[i].path, O_RDONLY);
			if (check_file == -1)
				return (print_error("Couldn't open the file\n"), -1);
			close(check_file);
		}
	}
	return (0);
}

void	init_validate_data(char *path, t_data *data)
{
	int		fd;
	char	*line;
	char	**split_result;

	init_elements(data);
	fd = open_file(path);
	if (fd == -1)
		exit(1);
	line = get_next_line(fd);
	while (line)
	{
		split_result = ft_multi_split(line, " \n");
		int result = check_path(data, split_result);
		if (result == -1)
		{
			ft_free_split(split_result);
			free(line);
			clean_file(data, fd);
			exit(1);
		}
		else if (result == 1)
		{
			ft_free_split(split_result);
			break;
		}
		// if (check_path(data, split_result) == -1)
		// {
		// 	ft_free_split(split_result);
		// 	break ;
		// }
		ft_free_split(split_result);
		free(line);
		line = get_next_line(fd);
	}
	if (validate_data(data) == -1)
	{
		free(line);
		clean_file(data, fd);
		exit(1);
	}
	assign_map(data, line, fd);
}
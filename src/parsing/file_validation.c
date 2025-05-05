/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:07:41 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/05/05 17:42:04 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

/*
give initial values to our elements(NO, SO, WE, EA, F, C)
if it is direction -> initial value is NULL
if it is a color -> -1
*/

void	init_elements(t_data *data)
{
	int	i;

	i = 0;
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

int	check_map_ext(char *str, char *ext)
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

	if (check_map_ext(path, ".cub") != 0)
		print_error("Wrong file format");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_error("Invalid file descriptor");
	return (fd);
}

void	ft_handle_colors(t_data *data, char **split_line, int fd, char *line)
{
	char	**split_colors;
	int		i;

	if (ft_strncmp(split_line[0], "F", ft_strlen(split_line[0])) == 0)
		i = 4;
	else
		i = 5;
	split_colors = ft_multi_split(split_line[1], ",");
	if (!split_colors[0] || !split_colors[1] || !split_colors[2] || \
		split_colors[3])
		// return (ft_free_split(split_colors), ft_free_split(split_line), \
		// 		clean_up(data, fd), free(line), \
		// 		error("Wrong color numbers in file"));
	data->elements[i].rgb_letter[0] = ft_color_atoi(split_colors[0]);
	data->elements[i].rgb_letter[1] = ft_color_atoi(split_colors[1]);
	data->elements[i].rgb_letter[2] = ft_color_atoi(split_colors[2]);
	if (data->elements[i].rgb_letter[0] > 255 \
	|| data->elements[i].rgb_letter[1] > 255 \
	|| data->elements[i].rgb_letter[2] > 255 \
	|| data->elements[i].rgb_letter[0] < 0 || data->elements[i].rgb_letter[1] < 0 \
	|| data->elements[i].rgb_letter[2] < 0)
		// return (ft_free_split(split_colors), ft_free_split(split_line), \
		// 	clean_up(data, fd), free(line), error("Wrong color number", 0));
	ft_free_split(split_colors);
}

int	add_single_path(t_data *data, char **split_line, int fd, char *line)
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
		ft_handle_colors(data, split_line, fd, line);
	else if (ft_strncmp(split_line[0], "C", ft_strlen(split_line[0])) == 0 \
	&& data->elements[5].rgb_letter[0] == -1)
		ft_handle_colors(data, split_line, fd, line);
	else
		// return (ft_free_split(split_line), clean_up(data, fd), \
		// free(line), error("Wrong id or a duplicate", 0), -1);
	return (0);
}

int	add_path(t_data *data, char **split_res, int fd, char *line)
{
	if (!split_res[0])
		return (ft_free_split(split_res), 0);
	if (ft_strchr(split_res[0], '1'))
		return (ft_free_split(split_res), -1);
	if (!split_res[1] || split_res[2])
	// update
		return 1;
	// 	return (ft_free_split(split_res), clean_up(data, fd), \
	// free(line), error("Wrong elements in file", 0), 0);
	add_single_path(data, split_res, fd, line);
	ft_free_split(split_res);
	return (0);
}

void	init_validate_data(char *path, t_data *data)
{
	int		fd;
	char	*line;
	char	**split_result;

	init_elements(data);
	fd = open_file(path);
	line = get_next_line(fd);
	while (line)
	{
		split_result = ft_multi_split(line, " \n");
		if (add_path(data, split_result, fd, line) == -1)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	//validate_data(data, line, fd);
	//create_map(data, line, fd);
}
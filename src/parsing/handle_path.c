/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:35:31 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/06/02 12:47:35 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	handle_rgb_color(t_data *data, char **split_line)
{
	if (ft_strncmp(split_line[0], "F", ft_strlen("F")) == 0
		&& data->elements[4].rgb_letter[0] == -1)
		return (handle_rgb(data, split_line));
	else if (ft_strncmp(split_line[0], "C", ft_strlen("C")) == 0
		&& data->elements[5].rgb_letter[0] == -1)
		return (handle_rgb(data, split_line));
	return (-1);
}

static int	handle_texture_path(t_data *data, char **split_line)
{
	if (ft_strncmp(split_line[0], "NO", ft_strlen("NO")) == 0
		&& !data->elements[0].path)
		return (data->elements[0].path = ft_strdup(split_line[1]), 0);
	else if (ft_strncmp(split_line[0], "SO", ft_strlen("SO")) == 0
		&& !data->elements[1].path)
		return (data->elements[1].path = ft_strdup(split_line[1]), 0);
	else if (ft_strncmp(split_line[0], "WE", ft_strlen("WE")) == 0
		&& !data->elements[2].path)
		return (data->elements[2].path = ft_strdup(split_line[1]), 0);
	else if (ft_strncmp(split_line[0], "EA", ft_strlen("EA")) == 0
		&& !data->elements[3].path)
		return (data->elements[3].path = ft_strdup(split_line[1]), 0);
	return (-1);
}

/*
check if paths have already been assigned
to our data struct, if not -> assign
*/
static int	add_path(t_data *data, char **split_line)
{
	if (handle_texture_path(data, split_line) == 0)
		return (0);
	if (handle_rgb_color(data, split_line) == 0)
		return (0);
	print_error("Wrong id or a duplicate\n");
	return (-1);
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

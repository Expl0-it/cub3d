/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:46:39 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/06/02 13:16:19 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_rgb_index(char **split_line)
{
	if (ft_strncmp(split_line[0], "F", ft_strlen(split_line[0])) == 0)
		return (4);
	else
		return (5);
}

static int	validate_rgb_components(char **split_colors)
{
	if (!split_colors[0] || !split_colors[1]
		|| !split_colors[2] || split_colors[3])
	{
		ft_free_split(split_colors);
		print_error("Wrong color numbers in file\n");
		return (-1);
	}
	return (0);
}

static int	assign_valid_rgb(t_data *data, char **split_colors, int index)
{
	int	*rgb;
	int	i;

	rgb = data->elements[index].rgb_letter;
	i = 0;
	rgb[0] = ft_rgb_atoi(split_colors[0]);
	rgb[1] = ft_rgb_atoi(split_colors[1]);
	rgb[2] = ft_rgb_atoi(split_colors[2]);
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			ft_free_split(split_colors);
			print_error("Wrong color number\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

/*
- split into char **
- check there are only 3 elements
- check they are within 0-255
*/
int	handle_rgb(t_data *data, char **split_line)
{
	int		index;
	char	**split_colors;

	index = get_rgb_index(split_line);
	split_colors = ft_multi_split(split_line[1], " ,");
	if (validate_rgb_components(split_colors) == -1)
		return (-1);
	if (assign_valid_rgb(data, split_colors, index) == -1)
		return (-1);
	ft_free_split(split_colors);
	return (0);
}

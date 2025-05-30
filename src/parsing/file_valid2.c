/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_valid2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:28:13 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/05/30 17:48:54 by mbudkevi         ###   ########.fr       */
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

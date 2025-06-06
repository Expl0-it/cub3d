/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:43:15 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/05/30 17:48:10 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_rgb_atoi(const char *nptr)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (nptr[i] >= 9 && nptr[i] <= 13)
		i++;
	while (nptr[i] && ft_isdigit(nptr[i]))
		count = (count * 10) + ((nptr[i++] - 48));
	if (nptr[i])
		return (-1);
	return (count);
}

void	clean_file(t_data *data, int fd)
{
	int	i;

	i = -1;
	while (++i <= 5)
	{
		if (data->elements[i].path)
		{
			free(data->elements[i].path);
			data->elements[i].path = NULL;
		}
	}
	free_gnl_stash();
	if (fd != -1)
		close(fd);
	if (data->map)
	{
		ft_free_split(data->map);
		data->map = NULL;
	}
}

void	free_game_textures(t_game *game)
{
	free(game->tpaths.north_path);
	free(game->tpaths.south_path);
	free(game->tpaths.west_path);
	free(game->tpaths.east_path);
	game->tpaths.north_path = NULL;
	game->tpaths.south_path = NULL;
	game->tpaths.west_path = NULL;
	game->tpaths.east_path = NULL;
}

int	rgb_to_int(int rgb[3])
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

int	add_data_to_game(t_game *game)
{
	game->map = game->data.map;
	game->tpaths.north_path = ft_strdup(game->data.elements[NO].path);
	game->tpaths.south_path = ft_strdup(game->data.elements[SO].path);
	game->tpaths.west_path = ft_strdup(game->data.elements[WE].path);
	game->tpaths.east_path = ft_strdup(game->data.elements[EA].path);
	if (!game->tpaths.north_path || !game->tpaths.south_path
		|| !game->tpaths.west_path || !game->tpaths.east_path)
	{
		free(game->tpaths.north_path);
		free(game->tpaths.south_path);
		free(game->tpaths.west_path);
		free(game->tpaths.east_path);
		print_error("Memory allocation failed");
		return (-1);
	}
	game->colors.floor_c = rgb_to_int(game->data.elements[F].rgb_letter);
	game->colors.ceil_c = rgb_to_int(game->data.elements[C].rgb_letter);
	return (OK);
}

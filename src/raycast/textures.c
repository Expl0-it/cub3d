/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:02:48 by mamichal          #+#    #+#             */
/*   Updated: 2025/05/09 14:13:34 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	load_texture(t_game *game, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx_s->p_mlx, path, \
							&texture->width, &texture->height);
	if (NULL == texture->img)
		return (false);
	texture->data = mlx_get_data_addr(texture->img, &texture->mlx_val.bpp, \
					&texture->mlx_val.line_len, &texture->mlx_val.endian);
	return (true);
}

bool	load_all_textures(t_game *game)
{
	if (false == load_texture(game, &game->tpoints.north, \
					game->tpaths.north_path))
		return (false);
	if (false == load_texture(game, &game->tpoints.south, \
						game->tpaths.south_path))
		return (false);
	if (false == load_texture(game, &game->tpoints.east, \
						game->tpaths.east_path))
		return (false);
	if (false == load_texture(game, &game->tpoints.west, \
						game->tpaths.west_path))
		return (false);
	return (true);
}

t_texture	*pick_texture(t_game *game, t_ray *ray)
{
	if (ray->side == SIDE)
	{
		if (ray->raydirx < 0)
			return (&game->tpoints.west);
		else
			return (&game->tpoints.east);
	}
	else
	{
		if (ray->raydiry < 0)
			return (&game->tpoints.north);
		else
			return (&game->tpoints.south);
	}
}

static void	free_texture(t_game *game, t_texture *texture)
{
	if (texture->img)
		mlx_destroy_image(game->mlx_s->p_mlx, texture->img);
}

void	free_all_textures(t_game *game)
{
	free_texture(game, &game->tpoints.north);
	free_texture(game, &game->tpoints.south);
	free_texture(game, &game->tpoints.east);
	free_texture(game, &game->tpoints.west);
}

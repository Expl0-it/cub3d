/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:10:03 by mamichal          #+#    #+#             */
/*   Updated: 2025/04/07 14:03:17 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool init_mlx(t_game *game)
{
	game->mlx_s->p_mlx = mlx_init();
	if (NULL == game->mlx_s->p_mlx)
		return (false);
	game->mlx_s->wnd = mlx_new_window(game->mlx_s->p_mlx, WIDTH, HEIGHT, "cub3d");
	if (NULL == game->mlx_s->wnd)
		return (false);
	game->mlx_s->img = mlx_new_image(game->mlx_s->p_mlx, WIDTH, HEIGHT);
	if (NULL == game->mlx_s->img)
		return (false);
	game->mlx_s->data = mlx_get_data_addr(game->mlx_s->img, &game->mlx_s->init.bpp, \
		&game->mlx_s->init.line_len, &game->mlx_s->init.endian);
	if (NULL == game->mlx_s->data)
		return (false);
	return (true);
}

bool	game_init(t_game *game)
{
	if (false == init_mlx(game))
		return (false);
	if (false == load_all_textures(game))
		return (false);
	return (true);
}

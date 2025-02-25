/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:10:03 by mamichal          #+#    #+#             */
/*   Updated: 2025/02/25 19:18:15 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool init_mlx(t_game *game)
{
	game->mlx.p_mlx = mlx_init();
	if (NULL == game->mlx.p_mlx)
		return (false);
	game->mlx.wnd = mlx_new_window(game->mlx.p_mlx, WIDTH, HEIGHT, "cub3d");
	if (NULL == game->mlx.wnd)
		return (false);
	game->mlx.img = mlx_new_image(game->mlx.p_mlx, WIDTH, HEIGHT);
	if (NULL == game->mlx.img)
		return (false);
	game->mlx.data = mlx_get_data_addr(game->mlx.img, &game->mlx.init.bits, \
		&game->mlx.init.len, &game->mlx.init.endian);
	if (NULL == game->mlx.data)
		return (false);
	return (true);
}

bool	game_init(t_game *game)
{
	if (false == init_mlx(game))
		return (false);
	return (true);
}

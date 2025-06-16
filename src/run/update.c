/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:25:14 by mamichal          #+#    #+#             */
/*   Updated: 2025/06/16 11:53:18 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update(t_game *game)
{
	t_player	*player;

	player = &game->player;
	rotate_player(player);
	move_player(game, player);
	clear_image(game);
	draw_floor_ceil(game);
	raycast(game, player);
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx_s->p_mlx,
			game->mlx_s->wnd, game->mlx_s->img, 0, 0);
	return (OK);
}

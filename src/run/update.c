/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:25:14 by mamichal          #+#    #+#             */
/*   Updated: 2025/03/31 22:55:56 by mamichal         ###   ########.fr       */
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
	return (OK);
}

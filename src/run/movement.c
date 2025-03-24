/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:23:19 by mamichal          #+#    #+#             */
/*   Updated: 2025/03/24 13:31:14 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_player *player)
{
	if (player->keys.rotate_left)
		player->angle -= ANGLE_SPEED;
	if (player->keys.rotate_right)
		player->angle += ANGLE_SPEED;
	if (player->angle > 2 * M_PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * M_PI;
}

static bool	touch(float px, float py, t_game *game)
{
	int	x1;
	int	y1;
	int	mapx;
	int	mapy;

	x1 = (int)((px + COLLISION_RADIUS) / BLOCK);
	y1 = (int)((py + COLLISION_RADIUS) / BLOCK);
	mapy = (int)((py - COLLISION_RADIUS) / BLOCK);
	while (mapy <= y1)
	{
		mapx = (int)((px - COLLISION_RADIUS) / BLOCK);
		while (mapx <= x1)
		{
			if (mapy < 0 || game->map[mapy] == NULL
				|| game->map[mapy][mapx] == '\0'
				|| game->map[mapy][mapx] == '1')
				return (true);
			mapx++;
		}
		mapy++;
	}
	return (false);
}


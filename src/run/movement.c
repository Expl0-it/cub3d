/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:23:19 by mamichal          #+#    #+#             */
/*   Updated: 2025/03/24 16:07:43 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static void	calc_new_pos(t_player *player, int *new_x, int *new_y, int speed)
{
	float	sin_angle;
	float	cos_angle;

	sin_angle = sin(player->angle);
	cos_angle = cos(player->angle);
	if (player->keys.key_up)
	{
		*new_x += cos_angle * speed;
		*new_y += sin_angle * speed;
	}
	if (player->keys.key_down)
	{
		*new_x -= cos_angle * speed;
		*new_y -= sin_angle * speed;
	}
	if (player->keys.key_left)
	{
		*new_x += sin_angle * speed;
		*new_y -= cos_angle * speed;
	}
	if (player->keys.key_right)
	{
		*new_x -= sin_angle * speed;
		*new_y += cos_angle * speed;
	}
}

void	move_player(t_game *game, t_player *player)
{
	int	new_x;
	int	new_y;

	new_x = player->x;
	new_y = player->x;
	calc_new_pos(player, &new_x, &new_y, SPEED);
	if (!touch(new_x, player->y, game))
		player->x = new_x;
	if (!touch(player->x, new_y, game))
		player->y = new_y;
}

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

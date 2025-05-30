/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:38:17 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/05/30 17:04:12 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_spawn_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	init_player_pos(t_player *player, int x, int y, char spawn_char)
{
	player->x = (x + 0.5f) * BLOCK;
	player->y = (y + 0.5f) * BLOCK;
	if (spawn_char == 'N')
		player->angle = 3 * (M_PI / 2);
	else if (spawn_char == 'S')
		player->angle = M_PI / 2;
	else if (spawn_char == 'E')
		player->angle = 0;
	else if (spawn_char == 'W')
		player->angle = M_PI;
}

void	find_player_spawn(t_game *game, t_player *player)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (is_spawn_char(game->map[y][x]))
			{
				init_player_pos(player, x, y, game->map[y][x]);
				return ;
			}
			x++;
		}
		y++;
	}
	perror("Invalid spawn");
	exit(1);
}

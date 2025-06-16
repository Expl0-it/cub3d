/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:55:53 by mamichal          #+#    #+#             */
/*   Updated: 2025/06/16 11:52:49 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_minimap_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	x *= MINIMAP_SQ_SIZE;
	y *= MINIMAP_SQ_SIZE;
	i = 0;
	while (i < MINIMAP_SQ_SIZE)
	{
		j = 0;
		while (j < MINIMAP_SQ_SIZE)
		{
			pixel_put(game->mlx_s, x + 1, y + 1, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	int	mapx;
	int	mapy;
	int	color;

	mapy = 0;
	while (game->map[mapy])
	{
		mapx = 0;
		while (game->map[mapy][mapx])
		{
			if (game->map[mapy][mapx] == '1')
				color = 0xFFFFFF;
			else if (ft_strchr("NSEW0", game->map[mapy][mapx]))
				color = 0x000000;
			else
			{
				mapx++;
				continue ;
			}
			draw_minimap_square(game, mapx, mapy, color);
			mapx++;
		}
		mapy++;
	}
	draw_minimap_square(game, game->player.x / BLOCK,
		game->player.y / BLOCK, 0xFF0000);
}

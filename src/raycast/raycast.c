/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:32:34 by mamichal          #+#    #+#             */
/*   Updated: 2025/03/31 22:56:43 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_game *game, t_player *player)
{
	float	ray_angle;
	float	angle_increment;
	int		column;

	ray_angle = player->angle - (M_PI / 6);
	angle_increment = (M_PI / 3) / WIDTH;
	column = 0;
	while (column < WIDTH)
	{
		calc_draw_line(game, player, ray_angle, column);
		ray_angle += angle_increment;
		column++;
	}
	// TODO: minimap
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:44:27 by mamichal          #+#    #+#             */
/*   Updated: 2025/05/13 12:00:57 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda(t_game *game, t_ray *ray)
{
	ray->hit = false;
	while (false == ray->hit)
	{
		if (ray->sidedistx < ray->deltadisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->side = SIDE;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = FRONT;
		}
		if (game->map[ray->mapy][ray->mapx] == '1')
			ray->hit = true;
	}
}

float	compute_distance(t_player *player, t_ray *ray, float ray_angle)
{
	float	perpwalldist;
	float	dist_in_pix;
	float	angle_diff;

	if (ray->side == SIDE)
	{
		perpwalldist = (ray->mapx - (player->x / BLOCK)
				+ (1 - ray->stepx) / 2.0f) / ray->raydirx;
	}
	else
	{
		perpwalldist = (ray->mapy - (player->y / BLOCK)
				+ (1 - ray->stepy) / 2.0f) / ray->raydiry;
	}
	dist_in_pix = perpwalldist * BLOCK;
	angle_diff = ray_angle - player->angle;
	dist_in_pix *= cosf(angle_diff);
	return (dist_in_pix);
}

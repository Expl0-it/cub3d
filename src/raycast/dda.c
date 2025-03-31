/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:44:27 by mamichal          #+#    #+#             */
/*   Updated: 2025/03/31 21:54:05 by mamichal         ###   ########.fr       */
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
			ray->side = FRONT;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = SIDE;
		}
		if (game->map[ray->mapy][ray->mapx] == '1')
			ray->hit = true;
	}
}

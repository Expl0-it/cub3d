/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:02:48 by mamichal          #+#    #+#             */
/*   Updated: 2025/03/31 22:11:40 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// NOTE: fn to load single and all textures for either me or Masha

t_texture	*pick_texture(t_game *game, t_ray *ray)
{
	if (ray->side == SIDE)
	{
		if (ray->raydirx < 0)
			return (&game->tpoints.west);
		else
			return (&game->tpoints.east);
	}
	else
	{
		if (ray->raydiry < 0)
			return (&game->tpoints.north);
		else
			return (&game->tpoints.south);
	}
}

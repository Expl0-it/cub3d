/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:25:14 by mamichal          #+#    #+#             */
/*   Updated: 2025/03/24 16:06:28 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_release(int key, t_game *game)
{
	if (XK_W == key)
		game->player.keys.key_up = false;
	if (XK_S == key)
		game->player.keys.key_down = false;
	if (XK_A == key)
		game->player.keys.key_left = false;
	if (XK_D == key)
		game->player.keys.key_right = false;
	if (XK_Left == key)
		game->player.keys.rotate_left = false;
	if (XK_Right == key)
		game->player.keys.rotate_right = false;
	return (OK);
}

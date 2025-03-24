/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:25:14 by mamichal          #+#    #+#             */
/*   Updated: 2025/03/24 16:04:48 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key, t_game *game)
{
	if (XK_Escape == key)
	{
		destroy(game);
		exit(OK);
	}
	if (XK_W == key)
		game->player.keys.key_up = true;
	if (XK_S == key)
		game->player.keys.key_down = true;
	if (XK_A == key)
		game->player.keys.key_left = true;
	if (XK_D == key)
		game->player.keys.key_right = true;
	if (XK_Left == key)
		game->player.keys.rotate_left = true;
	if (XK_Right == key)
		game->player.keys.rotate_right = true;
	return (OK);
}

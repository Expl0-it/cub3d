/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:25:14 by mamichal          #+#    #+#             */
/*   Updated: 2025/05/13 16:06:54 by mamichal         ###   ########.fr       */
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
	if (W == key)
		game->player.keys.key_up = true;
	if (S == key)
		game->player.keys.key_down = true;
	if (A == key)
		game->player.keys.key_left = true;
	if (D == key)
		game->player.keys.key_right = true;
	if (XK_Left == key)
		game->player.keys.rotate_left = true;
	if (XK_Right == key)
		game->player.keys.rotate_right = true;
	return (OK);
}

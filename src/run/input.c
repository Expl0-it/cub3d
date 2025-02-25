/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:25:14 by mamichal          #+#    #+#             */
/*   Updated: 2025/02/25 19:58:03 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	input(int key, void *game_cast)
{
	t_game	*game;

	game = (t_game *)game_cast;
	(void)game;
	(void)key;
	return (OK);
}

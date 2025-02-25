/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:42:00 by mamichal          #+#    #+#             */
/*   Updated: 2025/02/25 19:59:52 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroy(void *game_cast)
{
	t_game	*game;

	game = (t_game *)game_cast;
	mlx_loop_end(game->mlx_s.p_mlx);
	mlx_destroy_image(game->mlx_s.p_mlx, game->mlx_s.img);
	mlx_destroy_window(game->mlx_s.p_mlx, game->mlx_s.wnd);
	mlx_destroy_display(game->mlx_s.p_mlx);
	free(game->mlx_s.p_mlx);
	return (OK);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:42:00 by mamichal          #+#    #+#             */
/*   Updated: 2025/03/04 10:15:49 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroy(t_game *game)
{
	mlx_loop_end(game->mlx_s.p_mlx);
	mlx_destroy_image(game->mlx_s.p_mlx, game->mlx_s.img);
	mlx_destroy_window(game->mlx_s.p_mlx, game->mlx_s.wnd);
	mlx_destroy_display(game->mlx_s.p_mlx);
	free(game->mlx_s.p_mlx);
	return (OK);
}

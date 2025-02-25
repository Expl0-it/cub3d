/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:21:01 by mamichal          #+#    #+#             */
/*   Updated: 2025/02/25 19:46:31 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	run(t_game *game)
{
	mlx_loop_hook(game->mlx_s.p_mlx, update, game);
	mlx_hook(game->mlx_s.wnd, KeyPress, KeyPressMask, input, game);
	mlx_hook(game->mlx_s.wnd, DestroyNotify, StructureNotifyMask, destroy, game);
}

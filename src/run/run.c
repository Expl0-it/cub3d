/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:21:01 by mamichal          #+#    #+#             */
/*   Updated: 2025/05/09 14:13:59 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	run(t_game *game)
{
	mlx_hook(game->mlx_s->wnd, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->mlx_s->wnd, KeyRelease, KeyReleaseMask, key_release, game);
	mlx_hook(game->mlx_s->wnd, DestroyNotify, 0, destroy, game);
	mlx_loop_hook(game->mlx_s->p_mlx, update, game);
	mlx_loop(game->mlx_s->p_mlx);
}

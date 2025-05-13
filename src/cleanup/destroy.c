/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:42:00 by mamichal          #+#    #+#             */
/*   Updated: 2025/05/05 17:43:24 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroy(t_game *game)
{
	mlx_loop_end(game->mlx_s->p_mlx);
	mlx_destroy_image(game->mlx_s->p_mlx, game->mlx_s->img);
	mlx_destroy_window(game->mlx_s->p_mlx, game->mlx_s->wnd);
	mlx_destroy_display(game->mlx_s->p_mlx);
	free(game->mlx_s->p_mlx);
	exit(OK);
}

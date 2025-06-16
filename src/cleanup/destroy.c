/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:42:00 by mamichal          #+#    #+#             */
/*   Updated: 2025/06/16 12:21:16 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *msg)
{
	printf("%s", msg);
}

void	cleanup_game(t_game *game)
{
	clean_file(&game->data, -1);
	free_game_textures(game);
	free(game->mlx_s);
	game->mlx_s = NULL;
}

void	clean_and_exit(char *msg, t_game *game)
{
	print_error(msg);
	cleanup_game(game);
	exit(1);
}

int	destroy(t_game *game)
{
	mlx_loop_end(game->mlx_s->p_mlx);
	cleanup_game(game);
	free_all_textures(game);
	mlx_destroy_image(game->mlx_s->p_mlx, game->mlx_s->img);
	mlx_destroy_window(game->mlx_s->p_mlx, game->mlx_s->wnd);
	mlx_destroy_display(game->mlx_s->p_mlx);
	free(game->mlx_s->p_mlx);
	exit(OK);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:34:55 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/05/30 16:58:49 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	default_player(t_player *player)
{
	player->x = -1;
	player->y = -1;
	player->angle = -1;
	player->keys.key_up = false;
	player->keys.key_down = false;
	player->keys.key_left = false;
	player->keys.key_right = false;
	player->keys.rotate_left = false;
	player->keys.rotate_right = false;
}

static void	default_game_mlx(t_game *game)
{
	game->mlx_s = malloc(sizeof(t_mlx));
	if (!game->mlx_s)
	{
		perror("Failed to allocate mlx_s");
		exit(EXIT_FAILURE);
	}
	game->mlx_s->wnd = NULL;
	game->mlx_s->img = NULL;
	game->mlx_s->data = NULL;
	game->map = NULL;
	game->tpaths.north_path = NULL;
	game->tpaths.south_path = NULL;
	game->tpaths.east_path = NULL;
	game->tpaths.west_path = NULL;
}

void	fill_default_values(t_game *game)
{
	default_game_mlx(game);
	default_player(&game->player);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		print_error("Error!\nPlease check the amount of the args!\n");
		exit(1);
	}
	fill_default_values(&game);
	init_validate_data(argv[1], &game.data, &game);
	add_data_to_game(&game);
	find_player_spawn(&game, &game.player);
	if (false == game_init(&game))
	{
		print_error("game_init() failed\n");
		cleanup_game(&game);
		exit(EXIT_FAILURE);
	}
	run(&game);
	cleanup_game(&game);
	return (OK);
}

#include "cub3d.h"

static void	default_player(t_player *player)
{
	player->x = (float)WIDTH / 2;
	player->y = (float)HEIGHT / 2;
	player->angle = M_PI / 2;
	player->keys.key_up = false;
	player->keys.key_down= false;
	player->keys.key_left = false;
	player->keys.key_right = false;
	player->keys.rotate_left = false;
	player->keys.rotate_right = false;
}

static void	default_game_mlx(t_game *game)
{
	game->mlx_s.p_mlx = NULL;
	game->mlx_s.wnd = NULL;
	game->mlx_s.img = NULL;
	game->mlx_s.data = NULL;
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
	t_game game;

	fill_default_values(&game);
	// parse;

	(void)argc;
	(void)argv;
	game_init(&game);
	run(&game);
	return (OK);
}

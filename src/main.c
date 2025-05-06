#include "cub3d.h"

void	print_error(char *msg)
{
	printf("%s", msg);
}

void	print_error_exit(char *msg)
{
	printf("%s", msg);
	exit(1);
}

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
	game->mlx_s->p_mlx = NULL;
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
		print_error_exit("Error!\nPlease check the amount of the args!");
	fill_default_values(&game);
	// parse;

	(void)argv;
	if (false == game_init(&game))
		return (false);
	run(&game);
	return (OK);
}

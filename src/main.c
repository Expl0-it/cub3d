#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game game;

	// parse;

	(void)argc;
	(void)argv;
	game_init(&game);
	run(&game);
	return (OK);
}

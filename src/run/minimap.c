#include "cub3d.h"

static void	draw_minimap_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	x *= MINIMAP_SQ_SIZE;
	y *= MINIMAP_SQ_SIZE;
	i = 0;
	while (i < MINIMAP_SQ_SIZE)
	{
		j = 0;
		while (j < MINIMAP_SQ_SIZE)
		{
			pixel_put(game->mlx_s->p_mlx, x + 1, y + 1, color);
			j++;
		}
		i++;
	}
}


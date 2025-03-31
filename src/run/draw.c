/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:07:17 by mamichal          #+#    #+#             */
/*   Updated: 2025/03/31 11:29:08 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	offset = ((y * mlx->init.line_len) + (x * (mlx->init.bpp / 8)));
	dst = mlx->data + offset;
	*(unsigned int *)dst = color;
}

void	clear_image(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_put(game->mlx_s, x, y, 0);
			x++;
		}
		y++;
	}
}

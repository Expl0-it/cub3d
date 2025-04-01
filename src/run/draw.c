/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:07:17 by mamichal          #+#    #+#             */
/*   Updated: 2025/03/31 22:54:37 by mamichal         ###   ########.fr       */
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

void	draw_floor_ceil(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_put(game->mlx_s, x, y, game->colors.ceil_c);
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_put(game->mlx_s, x, y, game->colors.floor_c);
			x++;
		}
		y++;
	}
}

void	draw_column(t_game *game, t_texture *texture, int col, t_line *line)
{
	float	step;
	float	tex_pos;
	int		y;
	int		tex_y;
	int		color;

	step = (float)texture->height / (float)line->height;
	tex_pos = (line->start_y - HEIGHT / 2 + line->height / 2) * step;
	y = line->start_y;
	while (y < line->end_y)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		color = *(int *)(texture->data + (tex_y * texture->mlx_val.line_len) + line->texture_x * (texture->mlx_val.bpp / 8));
		pixel_put(game->mlx_s->p_mlx, col, y, color);
		tex_pos += step;
		y++;
	}
}

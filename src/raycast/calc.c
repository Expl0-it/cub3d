/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:03:10 by mamichal          #+#    #+#             */
/*   Updated: 2025/05/13 15:40:04 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray(t_ray *ray, t_player *player, float ray_angle)
{
	ray->raydirx = cosf(ray_angle);
	ray->raydiry = sinf(ray_angle);
	ray->mapx = (int)(player->x / BLOCK);
	ray->mapy = (int)(player->y / BLOCK);
}

static void	calc_delta_dist(t_ray *ray)
{
	if (0 == ray->raydirx)
		ray->deltadistx = 1e30f;
	else
		ray->deltadistx = fabsf(1.0f / ray->raydirx);
	if (0 == ray->raydiry)
		ray->deltadisty = 1e30f;
	else
		ray->deltadisty = fabsf(1.0f / ray->raydiry);
}

static void	init_step(t_ray *ray, t_player *player)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = ((player->x / BLOCK) - ray->mapx)
			* ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = ((ray->mapx + 1) - (player->x / BLOCK))
			* ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = ((player->y / BLOCK) - ray->mapy)
			* ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = ((ray->mapy + 1) - (player->y / BLOCK))
			* ray->deltadisty;
	}
}

static void	calc_line(t_player *player, t_ray *ray, \
				t_texture *texture, t_line *line)
{
	float	wallx;

	line->height = (int)(BLOCK * HEIGHT / line->distance);
	line->start_y = (HEIGHT - line->height) / 2;
	line->end_y = line->start_y + line->height;
	if (line->start_y < 0)
		line->start_y = 0;
	if (line->end_y >= HEIGHT)
		line->end_y = HEIGHT - 1;
	if (ray->side == SIDE)
		wallx = (player->y / BLOCK) + ((line->distance / BLOCK)
				* ray->raydiry);
	else
		wallx = (player->x / BLOCK) + ((line->distance / BLOCK)
				* ray->raydirx);
	wallx = wallx - floor(wallx);
	line->texture_x = (int)(wallx * texture->width);
	if (line->texture_x < 0)
		line->texture_x = 0;
	if (line->texture_x >= texture->width)
		line->texture_x = texture->width - 1;
}

void	calc_draw_line(t_game *game, t_player *player, \
		float ray_angle, int col)
{
	t_ray		ray;
	t_line		line;
	t_texture	*texture;

	init_ray(&ray, player, ray_angle);
	calc_delta_dist(&ray);
	init_step(&ray, player);
	dda(game, &ray);
	texture = pick_texture(game, &ray);
	if (NULL == texture || NULL == texture->data)
		return ;
	line.distance = compute_distance(player, &ray, ray_angle);
	calc_line(player, &ray, texture, &line);
	draw_column(game, texture, col, &line);
}

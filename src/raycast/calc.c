static void	init_ray(t_ray *ray, t_player *player, float ray_angle)
{
	ray->raydirx = cosf(ray_angle);
	ray->raydiry = sinf(ray_angle);
	// NOTE: Cast to int or not?? (int)(player->x||y / BLOCK)
	ray->mapx = player->x / BLOCK;
	ray->mapy = player->y / BLOCK;
}

static void	calc_deta_dist(t_ray *ray)
{
	if (0 == ray->raydirx)
		ray->deltadistx = 1e30f;
	else
		ray->deltadistx = fabs(1.0f / ray->raydirx);
	if (0 == ray->raydiry)
		ray->deltadisty = 1e30f;
	else
		ray->deltadisty = fabs(1.0f / ray->raydiry);
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
	if (ray->raydirx < 0)
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


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


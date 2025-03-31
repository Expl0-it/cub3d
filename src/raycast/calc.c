static void	init_ray(t_ray *ray, t_player *player, float ray_angle)
{
	ray->raydirx = cosf(ray_angle);
	ray->raydiry = sinf(ray_angle);
	// NOTE: Cast to int or not?? (int)(player->x||y / BLOCK)
	ray->mapx = player->x / BLOCK;
	ray->mapy = player->y / BLOCK;
}


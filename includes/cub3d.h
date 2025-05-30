#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WIDTH 1280
# define HEIGHT 720
# define BLOCK 64
# define COLLISION_RADIUS 10
# define ANGLE_SPEED 0.03
# define SPEED 3
# define MINIMAP_SQ_SIZE 8

// NOTE: KEYCODES
# define W 119
# define S 115
# define A 97
# define D 100

typedef enum	type_id
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
}	type_id;

typedef struct	s_element
{
	type_id		element_id;
	char		*path;
	int			rgb_letter[3];
}	t_element;

typedef struct s_keys
{
	bool	key_up;
	bool	key_down;
	bool	key_right;
	bool	key_left;
	bool	rotate_right;
	bool	rotate_left;
}				t_keys;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	t_keys	keys;
}				t_player;

typedef struct	s_data
{
	t_element	elements[6];
	char		**map;
}	t_data;

enum e_err
{
	OK = 0,
	MALLOC_ERR = 1,
};

typedef struct s_mlx_val
{
	int		bpp;
	int		line_len;
	int		endian;
}				t_mlx_val;

typedef struct s_mlx
{
	t_mlx_val	init;
	void		*p_mlx;
	void		*wnd;
	void		*img;
	void		*data;
}				t_mlx;

typedef struct s_texture
{
	void		*img;
	char		*data;
	int			width;
	int			height;
	t_mlx_val	mlx_val;
}				t_texture;

typedef struct s_line
{
	float	height;
	float	distance;
	int		start_y;
	int		end_y;
	int		texture_x;
}				t_line;

typedef struct s_tpaths
{
	char	*north_path;
	char	*south_path;
	char	*east_path;
	char	*west_path;
}				t_tpaths;

typedef struct s_tpoints
{
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
}				t_tpoints;

typedef enum e_side
{
	SIDE = 0,
	FRONT = 1,
}			t_side;

typedef struct s_ray
{
	float	raydirx;
	float	raydiry;
	float	sidedistx;
	float	sidedisty;
	float	deltadistx;
	float	deltadisty;
	float	perpwalldist;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		side;
	bool	hit;
}				t_ray;

typedef struct s_colors
{
	int	floor_c;
	int	ceil_c;
}				t_colors;

typedef struct s_game
{
	t_mlx		*mlx_s;
	t_player	player;
	t_data		data;
	t_tpaths	tpaths;
	t_tpoints	tpoints;
	t_colors	colors;
	char		**map;
}				t_game;

//parsing
void	print_error(char *msg);
void	clean_and_exit(char *msg, t_data *data, int fd);
int		ft_rgb_atoi(const char *nptr);
void	clean_file(t_data *data, int fd);
void	init_validate_data(char *path, t_data *data);
int		count_columns(char **arr);
bool	has_valid_border(char **map);
int		add_data_to_game(t_game *game);
void	assign_map(t_data *data, char *line, int fd);
void	find_player_spawn(t_game *game, t_player *player);
void	cleanup_game(t_game *game);

//		DECLARATIONS
//
//		init
//	init.c
bool	game_init(t_game *game);

//		run
//	run.c
void	run(t_game *game);
//	key_press.c
int		key_press(int key, t_game *game);
//	key_release.c
int		key_release(int key, t_game *game);
//	update.c
int		update(t_game *game);
//	movement.c
void	move_player(t_game *game, t_player *player);
void	rotate_player(t_player *player);
//	draw.c
void	pixel_put(t_mlx *mlx, int x, int y, int color);
void	clear_image(t_game *game);
void	draw_floor_ceil(t_game *game);
void	draw_column(t_game *game, t_texture *texture, int col, t_line *line);
//	minimap.c
void	draw_minimap(t_game *game);

//		raycast
//	raycast.c
void	raycast(t_game *game, t_player *player);
//	calc.c
void	calc_draw_line(t_game *game, t_player *player, \
			float ray_angle, int col);
//	dda.c
void	dda(t_game *game, t_ray *ray);
float	compute_distance(t_player *player, t_ray *ray, float ray_angle);
//	textures.c
bool	load_all_textures(t_game *game);
t_texture	*pick_texture(t_game *game, t_ray *ray);

//		cleanup
//	destroy.c
int		destroy(t_game *game);

#endif

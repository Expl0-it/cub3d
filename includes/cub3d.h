#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
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

# define WIDTH 800
# define HEIGHT 600

enum e_err
{
	OK = 0,
	MALLOC_ERR = 1,
};

typedef struct s_mlx_init
{
	int	bits;
	int	len;
	int	endian;
}				t_mlx_init;

typedef struct s_mlx
{
	t_mlx_init	init;
	void		*p_mlx;
	void		*wnd;
	void		*img;
	void		*data;
}				t_mlx;

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

typedef struct s_texture
{
	void	*img;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
};

typedef struct s_game
{
	t_mlx	mlx_s;
}				t_game;

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

//		cleanup
//	destroy.c
int		destroy(t_game *game);

#endif

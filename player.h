#ifndef PLAYER_H
# define PLAYER_H

# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include "animation.h"
# include "map.h"
# define PLAYER_LEFT			1
# define PLAYER_RIGHT			2
# define PLAYER_UP				3
# define PLAYER_DOWN			4
# define PLAYER_STOP_RIGHT		0
# define PLAYER_STOP_LEFT		5
# define PLAYER_STOP_UP			6
# define PLAYER_STOP_DOWN		7

typedef struct	s_player
{
	int				x;
	int				y;
	int				speed;
	t_animation		**animations;
	int				number_of_animations;
	int				animation_status;
	mlx_image_t		*image;
	int				switch_button;
}					t_player;


typedef struct game
{
	mlx_t		*mlx;
	t_player	*player;
	t_map		*map;
}				t_game;

t_player    *init_player(void	*mlx);

void        destroy_player(mlx_t *mlx, t_player *player);
void        turbo_shift(t_player *player);
void        move_up(t_player *player);
void        move_down(t_player *player);
void        move_left(t_player *player);
void        move_right(t_player *player);
void        walking_speed(t_player *player);
void		update_player(t_player *player);
void		path_breath(t_player *player);


#endif

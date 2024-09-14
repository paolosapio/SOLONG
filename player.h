 #ifndef PLAYER_H
# define PLAYER_H

#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include "animation.h"

typedef struct	s_player
{
	int				x;
	int				y;
	int				speed;
	t_animation		*animation;

}				t_player;



typedef struct mlx_player
{
	t_player	*player;
	mlx_t		*mlx;
}				t_mlx_player;



t_player    *init_player(void	*mlx);

void        destroy_player(mlx_t *mlx, t_player *player);
void        turbo_shift(t_player *player);
void        move_up(t_player *player);
void        move_down(t_player *player);
void        move_left(t_player *player);
void        move_right(t_player *player);
void        walking_speed(t_player *player);

#endif

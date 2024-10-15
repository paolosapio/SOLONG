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
	t_hitbox		hitbox;
}					t_player;

typedef struct s_textures_files
{
	char        *paths_walk_to_up[5];
    char        *paths_walk_to_down[4];
    char        *paths_walk_to_right[8];
    char        *paths_walk_to_left[8];
    char        *paths_breath_left[6];
    char        *paths_breath_right[6];

}	t_textures_files;

t_player    *init_player(mlx_t	*mlx);

void        destroy_player(mlx_t *mlx, t_player *player);
void        turbo_shift(t_player *player);
void        move_up(t_player *player, t_map *map);
void        move_down(t_player *player, t_map *map);
void        move_left(t_player *player, t_map *map);
void        move_right(t_player *player, t_map *map);
void        walking_speed(t_player *player);
void		update_player(t_player *player, t_map *map);
void		path_breath(t_player *player);
int			is_collision_up(t_player *player, t_map *map);
int			is_collision_down(t_player *player, t_map *map);
int			is_collision_left(t_player *player, t_map *map);
int			is_collision_right(t_player *player, t_map *map);
void breath(t_textures_files *textures);

#endif

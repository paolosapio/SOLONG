#ifndef SOLONG_H
# define SOLONG_H

#include <stdio.h>
#include <fcntl.h>
#include "player.h"
#include "GNL/get_next_line.h"

typedef struct game
{
	mlx_t		*mlx;
	t_player	*player;
	t_map		*map;
}				t_game;

void        ft_hook_keys(void *data2);
void        key_hook(mlx_key_data_t keydata, void* data2);
char        **read_n_copy_map(char *path_map);
void        update_game(t_game *game);

#endif
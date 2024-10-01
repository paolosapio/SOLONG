#ifndef SOLONG_H
# define SOLONG_H

#include <stdio.h>
#include <fcntl.h>
#include "player.h"
#include "GNL/get_next_line.h"
void        ft_hook_keys(void *data2);
void        key_hook(mlx_key_data_t keydata, void* data2);
void        maps_of_blocks(t_game *data);
char        **read_n_copy_map(char *path_map);

#endif
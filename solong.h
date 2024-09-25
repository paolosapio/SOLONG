#ifndef SOLONG_H
# define SOLONG_H


#define WIDTH 1280
#define HEIGHT 720

#include <stdio.h>
#include "player.h"



void        ft_hook_keys(void *data2);
void        key_hook(mlx_key_data_t keydata, void* data2);
void        maps_of_blocks(t_game *data);


#endif
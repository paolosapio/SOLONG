#include <stdlib.h>
#include "player.h"
#include "solong.h"
#include "MLX42/include/MLX42/MLX42.h"

void turbo_shift(t_player *player)
{
	player->animations[0]->speed_frame = 3;
	player->speed = 10; 
}

void move_up(t_player *player, t_map *map)
{
	if (is_collision_up(player, map) ==  0)
		player->y -= player->speed;
}

void move_down(t_player *player, t_map *map)
{	
	if (is_collision_down(player, map) ==  0)
		player->y += player->speed;
}

void move_left(t_player *player, t_map *map)
{
	if (is_collision_left(player, map) ==  0)
		player->x -= player->speed;
}

void move_right(t_player *player, t_map *map)
{
	if (is_collision_right(player, map) ==  0)
		player->x += player->speed;
}

void walking_speed(t_player *player)
{
	player->speed = 3; 
	player->animations[0]->speed_frame = 9;
}

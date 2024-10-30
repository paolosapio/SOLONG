#include "solong.h"


void normal_shift(t_player *player)
{
	player->animations[0].speed_frame = 9;
	player->animations[1].speed_frame = 9;
	player->animations[2].speed_frame = 9;
	player->animations[3].speed_frame = 9;
	player->animations[4].speed_frame = 9;
	player->speed = 10; 
}
void move_up(t_player *player, t_map *map)
{
	if (is_collision_up(player, map) ==  1)
		return ;
	player->y -= player->speed;
	player->steps++;
}

void move_down(t_player *player, t_map *map)
{	
	if (is_collision_down(player, map) ==  1)
		return ;
	player->y += player->speed;
	player->steps++;
}

void move_left(t_player *player, t_map *map)
{
	if (is_collision_left(player, map) ==  1)
		return ;
	player->x -= player->speed;
	player->steps++;
}

void move_right(t_player *player, t_map *map)
{
	if (is_collision_right(player, map) ==  1)
		return ;
	player->x += player->speed;
	player->steps++;
}

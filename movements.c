#include <stdlib.h>
#include "player.h"
#include "solong.h"
#include "MLX42/include/MLX42/MLX42.h"

void turbo_shift(t_player *player)
{
	player->speed = 10; 
}

void move_up(t_player *player)
{
	player->y -= player->speed;
}

void move_down(t_player *player)
{	
	player->y += player->speed;
}

void move_left(t_player *player)
{	
	player->x -= player->speed;
}

void move_right(t_player *player)
{
	player->x += player->speed;
}

void walking_speed(t_player *player)
{

	player->speed = 1; 
}

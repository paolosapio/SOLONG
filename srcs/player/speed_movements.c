#include "solong.h"


void turbo_shift(t_player *player)
{
	player->animations[0].speed_frame = 3;
	player->animations[1].speed_frame = 3;
	player->animations[2].speed_frame = 3;
	player->animations[3].speed_frame = 3;
	player->animations[4].speed_frame = 3;
	player->speed = 10; 
}
void walking_speed(t_player *player)
{ 
	player->animations[0].speed_frame = 9;
	player->speed = 3;
}
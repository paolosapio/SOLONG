#include "player.h"

void update_player(t_player *player)
{	
    player->animations[0]->image->instances[0].x = player->x;
    player->animations[0]->image->instances[0].y = player->y;
    player->animations[1]->image->instances[0].x = player->x;
    player->animations[1]->image->instances[0].y = player->y;
    animation_update(player->animations[0]);
 //   animation_update(player->animations[1]);
}
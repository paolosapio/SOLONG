#include "player.h"

void update_player(t_player *player)
{	
    player->image->instances[0].x = player->x;
    player->image->instances[0].y = player->y;
    animation_update(player->animations[player->animation_status]);
}
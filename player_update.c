#include "player.h"

void update_player(t_player *player)
{
    player->animation->image->instances[0].x = player->x;
    player->animation->image->instances[0].y = player->y;
    animation_update(player->animation);
}
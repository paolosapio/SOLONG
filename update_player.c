#include "player.h"

void update_player(t_player *player)
{	
    player->image->instances[0].x = player->x;
    player->image->instances[0].y = player->y - 32;
    animation_update(player->animations[player->animation_status]);
    if (player->switch_button == PLAYER_LEFT)
        move_left(player);
    if (player->switch_button == PLAYER_RIGHT)
        move_right(player);
    if (player->switch_button == PLAYER_UP)
        move_up(player);
    if (player->switch_button == PLAYER_DOWN)
        move_down(player);
}
#include "player.h"

void update_player(t_player *player, t_map *map)
{	
    player->image->instances[0].x = player->x;
    player->image->instances[0].y = player->y - 32;
    animation_update(player->animations[player->animation_status]);
    if (player->switch_button == PLAYER_LEFT)
        move_left(player, map);
    if (player->switch_button == PLAYER_RIGHT)
        move_right(player, map);
    if (player->switch_button == PLAYER_UP)
        move_up(player, map);
    if (player->switch_button == PLAYER_DOWN)
        move_down(player, map);
    if (query_map_coordinate(map, player->y + 16, player->x + 16) == 'C')
            change_texture_map(map, player->y + 16, player->x + 16);
}
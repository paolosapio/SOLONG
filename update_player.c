#include "player.h"

void update_player(t_player *player, t_map *map)
{	
    player->image->instances[0].x = player->x;
    player->image->instances[0].y = player->y - IMG_SIZE;
    animation_update(player->animations[player->animation_status]);
    if (player->switch_button == PLAYER_LEFT)
        move_left(player, map);
    if (player->switch_button == PLAYER_RIGHT)
        move_right(player, map);
    if (player->switch_button == PLAYER_UP)
        move_up(player, map);
    if (player->switch_button == PLAYER_DOWN)
        move_down(player, map);
    if (query_map_coordinate(map, player->y + IMG_SIZE / 2, player->x + IMG_SIZE / 2) == 'C')
    {
        change_texture_map(map, player->y + IMG_SIZE / 2, player->x + IMG_SIZE / 2);
    }
    if ((query_map_coordinate(map, player->y + IMG_SIZE / 2, player->x + IMG_SIZE / 2) == 'E')
        && (map->collectables_to_take == map->total_collectables))
    {
        exit(1);
    }
}

#include "parser.h"
#include "solong.h"
#include "libft/libft.h"

int is_collision_up(t_player *player, t_map *map)
{
    char corner_up_left;
    char corner_up_right;

    corner_up_left = query_map_coordinate(map, player->y  - player->speed + IMG_SIZE / 2, player->x + 7);
    corner_up_right = query_map_coordinate(map, player->y - player->speed + IMG_SIZE / 2, player->x + IMG_SIZE - 7);

    if (corner_up_left == '1')
        return (1);
    else if (corner_up_right == '1')
        return (1);
    return (0);
}
int is_collision_down(t_player *player, t_map *map)
{
    char corner_down_left;
    char corner_down_right;

    corner_down_left = query_map_coordinate(map, player->y + IMG_SIZE + player->speed, player->x + 7);
    corner_down_right = query_map_coordinate(map, player->y + IMG_SIZE + player->speed, player->x + IMG_SIZE - 7);

    if (corner_down_left == '1')
        return (1);
    else if (corner_down_right == '1')
        return (1);
    return (0);
}
int is_collision_left(t_player *player, t_map *map)
{
    char corner_left_up;
    char corner_left_down;

    corner_left_up = query_map_coordinate(map, player->y + IMG_SIZE / 2, player->x - player->speed + 7);
    corner_left_down = query_map_coordinate(map, player->y + IMG_SIZE, player->x - player->speed + 7);

    if (corner_left_up == '1')
        return (1);
    else if (corner_left_down == '1')
        return (1);
    return (0);
}
int is_collision_right(t_player *player, t_map *map)
{
    char corner_right_up;
    char corner_right_down;

    corner_right_up = query_map_coordinate(map, player->y + IMG_SIZE / 2, player->x + IMG_SIZE + player->speed - 7);
    corner_right_down = query_map_coordinate(map, player->y + IMG_SIZE, player->x +IMG_SIZE + player->speed - 7);

    if (corner_right_up == '1')
        return (1);
    else if (corner_right_down == '1')
        return (1);
    return (0);
}
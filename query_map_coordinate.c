#include "parser.h"
#include "solong.h"
#include "libft/libft.h"

char query_map_coordinate(t_map *map, int y, int x)
{
    y /= 32;
    x /= 32;
    return (map->str_map[y][x]);
}
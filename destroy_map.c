#include "map.h"
#include <stdlib.h>
# include "MLX42/include/MLX42/MLX42.h"

void destroy_map(t_map *map)
{
    int y;

    y = 0;
    while (y < map->height)
    {
        free(map->str_map[y]);
        y++;
    }
    free(map->str_map);
    free(map);
}
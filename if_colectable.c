#include "parser.h"
#include "solong.h"
#include "libft/libft.h"

int32_t change_texture_map(t_map *map, int y, int x)
{
    int32_t instance;
    x /= 32;
    y /= 32;
    x *= 32;
    y *= 32;
    map->str_map[y/32][x/32] = '0';
    instance = mlx_image_to_window(map->mlx, map->image_paviment, x, y);
    mlx_set_instance_depth(&map->image_paviment->instances[instance], 1);
    // map->image_paviment->instances[instance].z = 1;
    return (instance);
}

#include "parser.h"
#include "solong.h"
#include "libft/libft.h"

int32_t change_texture_map(t_map *map, int y, int x)
{
    int32_t instance;
    x /= IMG_SIZE;
    y /= IMG_SIZE;
    x *= IMG_SIZE;
    y *= IMG_SIZE;
    map->str_map[y/IMG_SIZE][x/IMG_SIZE] = '0';
    instance = mlx_image_to_window(map->mlx, map->image_paviment, x, y);
    mlx_set_instance_depth(&map->image_paviment->instances[instance], 1);
    map->collectables_to_take++;
    printf("map->collectables_to_take: %d\n", map->collectables_to_take);
    return (instance);
}

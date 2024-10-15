#include "parser.h"
#include "solong.h"
#include "libft/libft.h"

void change_texture_map(t_map *map, int y, int x)
{
    x /= 32;
    y /= 32;
    x *= 32;
    y *= 32;
    map->str_map[y/32][x/32] = '0';
	mlx_image_to_window(map->mlx, map->image_paviment, x, y);
}

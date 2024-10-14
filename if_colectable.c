#include "parser.h"
#include "solong.h"
#include "libft/libft.h"

void change_texture_map(mlx_t *mlx, t_map *map, int y, int x)
{
    map->str_map[y][x] = '0';
	mlx_image_to_window(mlx, map->image_paviment, x, y);
}
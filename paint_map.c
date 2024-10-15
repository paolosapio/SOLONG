#include <stdlib.h>
#include "player.h"
#include "solong.h"
#include "MLX42/include/MLX42/MLX42.h"	

void paint_map(mlx_t *mlx, t_map *map)
{
	mlx_texture_t	*paviment;
	mlx_texture_t	*pc;
	mlx_texture_t	*bottle;
	int				x;
	int				y;

	x = 0;
	y = 0;
	paviment = mlx_load_png("sprites/texturas/paviment_claster.png");
	map->image_paviment = mlx_texture_to_image(mlx, paviment);
	mlx_delete_texture(paviment);
	bottle = mlx_load_png("sprites/texturas/bottle.png");
	map->image_bottle = mlx_texture_to_image(mlx, bottle);
	mlx_delete_texture(bottle);
	pc = mlx_load_png("sprites/texturas/pc.png");
	map->image_pc = mlx_texture_to_image(mlx, pc);
	mlx_delete_texture(pc);
	while (y < map->height * 32)
	{
		x = 0;
		while (x < map->width * 32)
		{
			if (map->str_map[y / 32][x / 32] == '0')
				mlx_image_to_window(mlx, map->image_paviment, x, y);
			if (map->str_map[y / 32][x / 32] == '1')
				mlx_image_to_window(mlx, map->image_pc, x, y);
			if (map->str_map[y / 32][x / 32] == 'C')
				mlx_image_to_window(mlx, map->image_bottle, x, y);
			x += 32;
		}
		y += 32;
	}

	printf("Profundidad: %d\n", map->image_paviment->instances[0].x);
}
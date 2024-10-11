#include <stdlib.h>
#include "player.h"
#include "solong.h"
#include "MLX42/include/MLX42/MLX42.h"	

void paint_map(mlx_t *mlx, t_map *map)
{
	mlx_texture_t	*paviment;
	mlx_image_t		*image_paviment;
	mlx_texture_t	*pc;
	mlx_image_t		*image_pc;
	mlx_texture_t	*bottle;
	mlx_image_t		*image_bottle;

	int				x;
	int				y;

	x = 0;
	y = 0;
	paviment = mlx_load_png("sprites/texturas/paviment_claster.png");
	image_paviment = mlx_texture_to_image(mlx, paviment);

	bottle = mlx_load_png("sprites/texturas/bottle.png");
	image_bottle = mlx_texture_to_image(mlx, bottle);
	
	pc = mlx_load_png("sprites/texturas/pc.png");
	image_pc = mlx_texture_to_image(mlx, pc);
	while (y < map->height * 32)
	{
		x = 0;
		while (x < map->width * 32)
		{
			if (map->str_map[y / 32][x / 32] == '0')
				mlx_image_to_window(mlx, image_paviment, x, y);
			if (map->str_map[y / 32][x / 32] == '1')
				mlx_image_to_window(mlx, image_pc, x, y);
			if (map->str_map[y / 32][x / 32] == 'C')
				mlx_image_to_window(mlx, image_bottle, x, y);
			x += 32;
		}
		y += 32;
	}
}
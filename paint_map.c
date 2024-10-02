#include <stdlib.h>
#include "player.h"
#include "solong.h"
#include "MLX42/include/MLX42/MLX42.h"	

void paint_map(mlx_t *mlx, t_map *map)
{
	mlx_texture_t	*textura;
	mlx_image_t		*image;
	mlx_texture_t	*textura2;
	mlx_image_t		*image2;
	int				x;
	int				y;

	x = 0;
	y = 0;
	textura = mlx_load_png("sprites/texturas/paviment_claster.png");
	image = mlx_texture_to_image(mlx, textura);
	
	textura2 = mlx_load_png("sprites/texturas/pc.png");
	image2 = mlx_texture_to_image(mlx, textura2);
	while (y < map->height * 32)
	{
		x = 0;
		while (x < map->width * 32)
		{
			if (map->str_map[y / 32][x / 32] == '0')
				mlx_image_to_window(mlx, image, x, y);
			if (map->str_map[y / 32][x / 32] == '1')
				mlx_image_to_window(mlx, image2, x, y);
			x += 32;

		}
		y += 32;
	}
}
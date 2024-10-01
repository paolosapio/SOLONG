#include <stdlib.h>
#include "player.h"
#include "solong.h"
#include "MLX42/include/MLX42/MLX42.h"	
	
	
void maps_of_blocks(t_game *data)
{
	char *path_valdosa;
	mlx_texture_t *textura;
	mlx_image_t *image;
	mlx_texture_t *textura2;
	mlx_image_t *image2;

	int x;
	int y;

	x = 0;
	y = 0;

	path_valdosa = "sprites/texturas/paviment_claster.png";
	textura = mlx_load_png(path_valdosa);
	image = mlx_texture_to_image(data->mlx, textura);

	textura2 = mlx_load_png("sprites/texturas/pc.png");
	image2 = mlx_texture_to_image(data->mlx, textura2);
	
	while (y < data->map->height * 32)
	{
		x = 0;
		while (x < data->map->width * 32)
		{
			if (data->map->str_map[y / 32][x / 32] == '0')
				mlx_image_to_window(data->mlx, image, x, y);
			if (data->map->str_map[y / 32][x / 32] == '1')
				mlx_image_to_window(data->mlx, image2, x, y);
			x += 32;

		}
		y += 32;
	}
}
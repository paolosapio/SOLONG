#include <stdlib.h>
#include "player.h"
#include "solong.h"
#include "MLX42/include/MLX42/MLX42.h"	
	
	
void maps_of_blocks(t_game *data)
{
	char *path_valdosa;
	mlx_texture_t *textura;
	mlx_image_t *image;
	int x;
	int y;

	x = 0;
	y = 0;
	path_valdosa = "sprites/texturas/paviment_claster.png";
	textura = mlx_load_png(path_valdosa);
	image = mlx_texture_to_image(data->mlx, textura);

	
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			mlx_image_to_window(data->mlx, image, x, y);
			x += 32;
		}
		y += 32;
	}
}
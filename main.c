#include <stdlib.h>
#include "player.h"
#include "solong.h"
#include "MLX42/include/MLX42/MLX42.h"



int main (void)
{
	t_game data;
	char *path_valdosa;
	mlx_texture_t *textura;
	mlx_image_t *image;
	mlx_image_t *image2;

	data.mlx = mlx_init(WIDTH, HEIGHT, "HOLA JAVI", false);
	if (!data.mlx)
		return (0);

//	hacer un block.h paara gestionar el mapa
//	hacer una funcion que ponga bloques en todaa la imagen


	maps_of_blocks(&data);


	data.player = init_player(data.mlx);

	mlx_loop_hook(data.mlx, update_player, data.player);
	mlx_key_hook(data.mlx, key_hook, &data);


	 mlx_loop(data.mlx);
	// mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}

//crear un estring que segun si el caracter es 1 o 0 ponga distintas texturas
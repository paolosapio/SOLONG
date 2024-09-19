#include <stdlib.h>
#include "player.h"
#include "solong.h"
#include "MLX42/include/MLX42/MLX42.h"

#define WIDTH 1280
#define HEIGHT 720


int main (void)
{
	t_game data;

	data.mlx = mlx_init(WIDTH, HEIGHT, "HOLA JAVI", true);
	if (!data.mlx)
		return (0);
	
	data.player = init_player(data.mlx);

	mlx_loop_hook(data.mlx, update_player, data.player);
	mlx_loop_hook(data.mlx, ft_hook_keys, &data);
	mlx_key_hook(data.mlx, key_hook, &data);


	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}


//arreglar la funcion key hook que sea la buena solamente

//preparar animacioonee arriba y abajo

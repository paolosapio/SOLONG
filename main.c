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

//en update player le pasaremos la animacion que queremos proyectar en la imagen del jugador
//el jugador necessita una variable para saber en que animacion estamos
//el jugador tiene que querear una imagen (que hara se esta creando dentro de la cada animacion)
// y todas las animaciones tienen que apuntar a la misma imagen,
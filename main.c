#include <stdlib.h>
#include "player.h"
#include "solong.h"
#include "parser.h"
#include "MLX42/include/MLX42/MLX42.h"



int main (int argn, char **argv)
{
	if(argn != 2)
		return(printf("EL MAPA, COÑO\n"), 1);
	t_game			data;
	t_parser		*parser;
	parser = parser_map(argv[1]);
	if (parser == NULL)
		return (EXIT_FAILURE);

	data.map = init_map(parser->str_map);
	data.mlx = mlx_init(data.map->width * 32, data.map->height * 32, "HOLA JAVI", false);
	if (!data.mlx)
		return (0);

	paint_map(data.mlx, data.map);
	data.player = init_player(data.mlx);
	data.player->x = parser->player.x;
	data.player->y = parser->player.y;
	mlx_loop_hook(data.mlx, update_player, data.player);
	mlx_key_hook(data.mlx, key_hook, &data);
	mlx_loop(data.mlx);
	destroy_map(data.map);
	destroy_player(data.mlx, data.player);
	mlx_terminate(data.mlx);
return (EXIT_SUCCESS);
}

//crear un parser
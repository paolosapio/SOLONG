/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:58:24 by psapio            #+#    #+#             */
/*   Updated: 2024/10/24 17:42:55 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "player.h"
#include "solong.h"
#include "parser.h"
#include "MLX42/include/MLX42/MLX42.h"

// arg_ber_check(char *arg_ber)
// {
// 	int i;
	
// }


int	main (int argn, char **argv)
{
	if(argn != 2)
		return(printf("EL MAPA, COÑO\n"), 1);
	
	t_game			data;
	t_parser		*parser;
	
	parser = parser_map(argv[1]);
	if (parser == NULL)
		return (EXIT_FAILURE);
	data.map = init_map(parser);
	data.mlx = mlx_init(data.map->width * IMG_SIZE,
		data.map->height * IMG_SIZE, "HOLA JAVI", false);
	res_check(data);
	data.map->mlx = data.mlx;
	if (!data.mlx)
		return (0);

	paint_map(data.mlx, data.map);
	data.player = init_player(data.mlx);
	data.player->x = parser->player.x;
	data.player->y = parser->player.y;
	mlx_loop_hook(data.mlx, update_game, &data);
	mlx_key_hook(data.mlx, key_hook, &data);
	mlx_loop(data.mlx);
	destroy_all(data);
return (EXIT_SUCCESS);
}
//comparar el tamano de ventana!
//falta controlar alrgunmen tos!
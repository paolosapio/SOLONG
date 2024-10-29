/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:58:24 by psapio            #+#    #+#             */
/*   Updated: 2024/10/29 14:40:38 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void arg_ber_check(char *arg_ber)
{
	int len;

	len = ft_strlen(arg_ber);
	if (len <= 4)
		ft_print_error("Invalid filename");
	len--;
	if (arg_ber[len] == 'r')
		len--;
	if (arg_ber[len] == 'e')
		len--;
	if (arg_ber[len] == 'b')
		len--;
	if (arg_ber[len] == '.'  && arg_ber[len - 1] == '/')
		ft_print_error("Invalid filename");
}

int	main(int argn, char **argv)
{
	t_game			data;
	t_parser		*parser;
	
	if(argn != 2)
		ft_print_error("Map not included");
	arg_ber_check(argv[1]);	
	parser = parser_map(argv[1]);
	if (parser == NULL)
		ft_print_error("Parser map error");
	data.map = init_map(parser);
	data.mlx = mlx_init(data.map->width * IMG_SIZE,
		data.map->height * IMG_SIZE, "so_long", false);
	res_check(data);
	data.map->mlx = data.mlx;
	if (!data.mlx)
		ft_print_error("MLX error");
	paint_map(data.mlx, data.map);
	data.player = init_player(data.mlx);
	data.player->x = parser->player.x;
	data.player->y = parser->player.y - 1;
	mlx_loop_hook(data.mlx, update_game, &data);
	mlx_key_hook(data.mlx, key_hook, &data);
	mlx_loop(data.mlx);
	destroy_all(data);
	return (EXIT_SUCCESS);
}

//me faltan meensajees de errores
//en check_map.c se puede asignar valor asi?
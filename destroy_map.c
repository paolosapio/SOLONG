/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:13:00 by psapio            #+#    #+#             */
/*   Updated: 2024/10/23 18:15:20 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdlib.h>
#include "MLX42/include/MLX42/MLX42.h"

void	destroy_map(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		free(map->str_map[y]);
		y++;
	}
	free(map->str_map);
	free(map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:13:00 by psapio            #+#    #+#             */
/*   Updated: 2024/10/29 12:55:21 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

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

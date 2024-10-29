/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:26:33 by psapio            #+#    #+#             */
/*   Updated: 2024/10/29 12:58:21 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"


t_map	*init_map(t_parser *parser)
{
	t_map	*map;
	int		y;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = ft_strlen(parser->str_map[0]);
	y = 0;
	while (parser->str_map[y] != NULL)
	{
		y++;
	}
	map->height = y;
	map->str_map = parser->str_map;
	map->total_collectables = parser->total_collectables;
	map->collectables_to_take = 0;
	return (map);
}

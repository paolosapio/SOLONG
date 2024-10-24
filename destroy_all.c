/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:10:25 by psapio            #+#    #+#             */
/*   Updated: 2024/10/24 13:00:13 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	destroy_all(t_game data)
{
	destroy_map(data.map);
	destroy_player(data.mlx, data.player);
	mlx_terminate(data.mlx);
}

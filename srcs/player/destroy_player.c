/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:15:26 by psapio            #+#    #+#             */
/*   Updated: 2024/10/30 16:33:06 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	destroy_player(mlx_t *mlx, t_player *player)
{
	int	i;

	(void)mlx;
	i = 0;
	while (i < player->n_anim)
	{
		destroy_animation(mlx, &player->animations[i]);
		i++;
	}
	//free(player->animations);
	return ;
}

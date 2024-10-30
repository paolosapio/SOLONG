/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:18:24 by psapio            #+#    #+#             */
/*   Updated: 2024/10/30 17:19:23 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_animation(t_animation *animation, mlx_t *mlx, int n_frames, char **pat_png)
{
	int			i;

	(void)mlx;
	i = 0;
	animation->textures = malloc(n_frames * sizeof(mlx_texture_t *));
	while (i < n_frames)
	{
		animation->textures[i] = mlx_load_png(pat_png[i]);
		i++;
	}
	animation->speed_frame = 1;
	animation->current_frame_total_game = 0;
	animation->total_texture = n_frames;
	animation->current_texture = 0;
}

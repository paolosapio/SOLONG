/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_animation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:10:25 by psapio            #+#    #+#             */
/*   Updated: 2024/10/29 12:55:12 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"


void	destroy_animation(mlx_t *mlx, t_animation *animation)
{
	int	i;

	i = 0;
	while (i < animation->total_texture)
	{
		mlx_delete_texture(animation->textures[i]);
		i++;
	}
	mlx_delete_image(mlx, animation->image);
	free (animation->textures);
	free (animation);
}

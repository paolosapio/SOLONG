/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_next_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:45:44 by psapio            #+#    #+#             */
/*   Updated: 2024/10/30 17:59:31 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	animation_next_texture(t_game *game, t_animation *animation)
{
	if (animation->current_texture == animation->total_texture)
		animation->current_texture = 0;
	//animation->image->pixels = animation->textures[animation->current_texture]->pixels;
	//la anterior imagen ???
	//mlx_delete_image(game->mlx, animation->image);
	mlx_delete_image(game->mlx, game->player.animations[game->player.anim_stat].image);
	animation->image = mlx_texture_to_image(game->mlx, animation->textures[animation->current_texture]);
	mlx_image_to_window(game->mlx, animation->image, game->player.x, game->player.y - IMG_SIZE);
	animation->current_texture++;
}

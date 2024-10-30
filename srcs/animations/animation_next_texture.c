/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_next_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:45:44 by psapio            #+#    #+#             */
/*   Updated: 2024/10/29 12:49:34 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	animation_next_texture(t_animation *animation)
{
	if (animation->current_texture == animation->total_texture)
		animation->current_texture = 0;
	animation->image->pixels
		= animation->textures[animation->current_texture]->pixels;
	animation->current_texture++;
}
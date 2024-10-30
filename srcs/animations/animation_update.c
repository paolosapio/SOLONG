/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:45:44 by psapio            #+#    #+#             */
/*   Updated: 2024/10/29 12:52:59 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	animation_update(t_animation *animation)
{
	if (animation->current_frame_total_game % animation->speed_frame == 0)
		animation_next_texture(animation);
	animation->current_frame_total_game++;
}
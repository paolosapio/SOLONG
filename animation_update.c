/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:45:44 by psapio            #+#    #+#             */
/*   Updated: 2023/11/20 15:57:40 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "player.h"
#include "solong.h"
#include "MLX42/include/MLX42/MLX42.h"

void animation_update(t_animation *animation)
{    
     if (animation->current_frame_total_game % animation->speed_frame == 0)
        animation_next_texture(animation);
     animation->current_frame_total_game++;
}
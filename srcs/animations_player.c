/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:45:44 by psapio            #+#    #+#             */
/*   Updated: 2024/10/29 12:54:50 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	breath(t_textures_files *textures)
{
	textures->paths_breath_left[0] = "sprites/boy/left/breath/01.png";
	textures->paths_breath_left[1] = "sprites/boy/left/breath/02.png";
	textures->paths_breath_left[2] = "sprites/boy/left/breath/03.png";
	textures->paths_breath_left[3] = "sprites/boy/left/breath/04.png";
	textures->paths_breath_left[4] = "sprites/boy/left/breath/05.png";
	textures->paths_breath_left[5] = "sprites/boy/left/breath/06.png";
	textures->paths_breath_right[0] = "sprites/boy/right/breath/01.png";
	textures->paths_breath_right[1] = "sprites/boy/right/breath/02.png";
	textures->paths_breath_right[2] = "sprites/boy/right/breath/03.png";
	textures->paths_breath_right[3] = "sprites/boy/right/breath/04.png";
	textures->paths_breath_right[4] = "sprites/boy/right/breath/05.png";
	textures->paths_breath_right[5] = "sprites/boy/right/breath/06.png";
}

void	walk(t_textures_files *textures)
{
	textures->paths_walk_to_right[0] = "sprites/boy/right/walk/no_wap/01.png";
	textures->paths_walk_to_right[1] = "sprites/boy/right/walk/no_wap/02.png";
	textures->paths_walk_to_right[2] = "sprites/boy/right/walk/no_wap/03.png";
	textures->paths_walk_to_right[3] = "sprites/boy/right/walk/no_wap/04.png";
	textures->paths_walk_to_right[4] = "sprites/boy/right/walk/no_wap/05.png";
	textures->paths_walk_to_right[5] = "sprites/boy/right/walk/no_wap/06.png";
	textures->paths_walk_to_right[6] = "sprites/boy/right/walk/no_wap/07.png";
	textures->paths_walk_to_right[7] = "sprites/boy/right/walk/no_wap/08.png";
	textures->paths_walk_to_left[0] = "sprites/boy/left/walk/no_wap/01.png";
	textures->paths_walk_to_left[1] = "sprites/boy/left/walk/no_wap/02.png";
	textures->paths_walk_to_left[2] = "sprites/boy/left/walk/no_wap/03.png";
	textures->paths_walk_to_left[3] = "sprites/boy/left/walk/no_wap/04.png";
	textures->paths_walk_to_left[4] = "sprites/boy/left/walk/no_wap/05.png";
	textures->paths_walk_to_left[5] = "sprites/boy/left/walk/no_wap/06.png";
	textures->paths_walk_to_left[6] = "sprites/boy/left/walk/no_wap/07.png";
	textures->paths_walk_to_left[7] = "sprites/boy/left/walk/no_wap/08.png";
	textures->paths_walk_to_up[0] = "sprites/boy/up/walk/no_wap/01.png";
	textures->paths_walk_to_up[1] = "sprites/boy/up/walk/no_wap/02.png";
	textures->paths_walk_to_up[2] = "sprites/boy/up/walk/no_wap/03.png";
	textures->paths_walk_to_up[3] = "sprites/boy/up/walk/no_wap/04.png";
	textures->paths_walk_to_up[4] = "sprites/boy/up/walk/no_wap/05.png";
	textures->paths_walk_to_down[0] = "sprites/boy/down/walk/no_wap/01.png";
	textures->paths_walk_to_down[1] = "sprites/boy/down/walk/no_wap/02.png";
	textures->paths_walk_to_down[2] = "sprites/boy/down/walk/no_wap/03.png";
	textures->paths_walk_to_down[3] = "sprites/boy/down/walk/no_wap/04.png";
}

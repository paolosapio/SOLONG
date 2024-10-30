/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:42:52 by psapio            #+#    #+#             */
/*   Updated: 2024/10/30 16:18:56 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	player_stop_lr(mlx_t *mlx, t_player *player, t_textures_files textures)
{
	init_animation(&player->animations[PLAYER_STOP_RIGHT], mlx, 6, textures.paths_breath_right);
	player->animations[PLAYER_STOP_RIGHT].speed_frame = 9;
	player->image = mlx_texture_to_image(mlx, player->animations[PLAYER_STOP_RIGHT].textures[0]);
	player->animations[PLAYER_STOP_RIGHT].image = player->image;

	init_animation(&player->animations[PLAYER_STOP_LEFT], mlx, 6, textures.paths_breath_left);
	player->animations[PLAYER_STOP_LEFT].speed_frame = 9;
	player->animations[PLAYER_STOP_LEFT].image = player->image;
}

void	player_lr(mlx_t *mlx, t_player *player, t_textures_files textures)
{
	init_animation(&player->animations[PLAYER_LEFT], mlx, 8, textures.paths_walk_to_left);
	player->animations[PLAYER_LEFT].speed_frame = 9;
	player->animations[PLAYER_LEFT].image = player->image;
	init_animation(&player->animations[PLAYER_RIGHT], mlx, 8, textures.paths_walk_to_right);
	player->animations[PLAYER_RIGHT].speed_frame = 9;
	player->animations[PLAYER_RIGHT].image = player->image;
}

void	player_ud(mlx_t *mlx, t_player *player, t_textures_files textures)
{
	
	init_animation(&player->animations[PLAYER_UP], mlx, 5, textures.paths_walk_to_up);
	player->animations[PLAYER_UP].speed_frame = 9;
	player->animations[PLAYER_UP].image = player->image;
	
	init_animation(&player->animations[PLAYER_DOWN], mlx, 4, textures.paths_walk_to_down);
	player->animations[PLAYER_DOWN].speed_frame = 9;
	player->animations[PLAYER_DOWN].image = player->image;
}

void init_player(t_game *data)
{
	t_player			*player;
	t_textures_files	textures;

	player = &data->player;
	player->speed = 3;
	player->n_anim = 6;
	breath(&textures);
	walk(&textures);
	player->animations = malloc(sizeof(t_animation) * player->n_anim);
	player_stop_lr(data->mlx, player, textures);
	player_lr(data->mlx, player, textures);
	player_ud(data->mlx, player, textures);
	mlx_image_to_window(data->mlx, player->image, 0, 0);
	mlx_set_instance_depth(&player->image->instances[0], 2);
	mlx_resize_image(player->image, IMG_SIZE, IMG_SIZE * 2);
}

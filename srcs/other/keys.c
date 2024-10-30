/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:44:06 by psapio            #+#    #+#             */
/*   Updated: 2024/10/30 17:50:16 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"


void	key_release(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_RELEASE)
	{
		normal_shift(&game->player);
		walking_speed(&game->player);
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
	{
		game->player.switch_button = PLAYER_STOP_UP;
		game->player.anim_stat = PLAYER_STOP_RIGHT;
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
	{
		game->player.switch_button = PLAYER_STOP_DOWN;
		game->player.anim_stat = PLAYER_STOP_RIGHT;
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
	{
		game->player.switch_button = PLAYER_STOP_RIGHT;
		game->player.anim_stat = PLAYER_STOP_RIGHT;
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
	{
		game->player.switch_button = PLAYER_STOP_LEFT;
		game->player.anim_stat = PLAYER_STOP_LEFT;
	}
}

void	key_press(mlx_key_data_t keydata, t_game *game)
{
	//printf("key press, animation: %i\n", game->player.anim_stat);
	//game->player.animations[game->player.anim_stat].image->enabled = false;
	//mlx_delete_image(game->mlx, game->player.animations[game->player.anim_stat].image);
	//printf("pos %i %i\n", game->player.animations->image->instances[0].x, game->player.animations->image->instances[0].y);
	if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_PRESS)
		turbo_shift(&game->player);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		game->player.switch_button = PLAYER_UP;
		game->player.anim_stat = PLAYER_UP;
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		game->player.switch_button = PLAYER_DOWN;
		game->player.anim_stat = PLAYER_DOWN;
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		game->player.switch_button = PLAYER_RIGHT;
		game->player.anim_stat = PLAYER_RIGHT;
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		game->player.switch_button = PLAYER_LEFT;
		game->player.anim_stat = PLAYER_LEFT;
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		printf("Escape\n");
		destroy_all(game);
		exit(0);
	}
}

void	key_hook(mlx_key_data_t keydata, void *game2)
{
	t_game	*game;

	game = game2;
	mlx_delete_image(game->mlx, game->player.animations[game->player.anim_stat].image);
	key_press(keydata, game);
	key_release(keydata, game);
}

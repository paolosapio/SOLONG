#include <stdlib.h>
#include "player.h"
#include "MLX42/include/MLX42/MLX42.h"
#include "solong.h"

void key_hook(mlx_key_data_t keydata, void* game2)
{
	t_game *game;

	game = game2;

	 if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_PRESS)
	 {
		turbo_shift(game->player);
	 }
	 if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_RELEASE)
	 {
		normal_shift(game->player);
	 	walking_speed(game->player);
	 }

	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		game->player->switch_button = PLAYER_UP;
		game->player->animation_status = PLAYER_UP;
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
	{
		game->player->switch_button = PLAYER_STOP_UP;
		game->player->animation_status = PLAYER_STOP_RIGHT;
	}


	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		game->player->switch_button = PLAYER_DOWN;
		game->player->animation_status = PLAYER_DOWN;
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
	{
		game->player->switch_button = PLAYER_STOP_DOWN;
		game->player->animation_status = PLAYER_STOP_RIGHT;
	}


	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		game->player->switch_button = PLAYER_RIGHT;
		game->player->animation_status = PLAYER_RIGHT;
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
	{
		game->player->switch_button = PLAYER_STOP_RIGHT;
		game->player->animation_status = PLAYER_STOP_RIGHT;
	}


	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		game->player->switch_button = PLAYER_LEFT;
		game->player->animation_status = PLAYER_LEFT;
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
	{
		game->player->switch_button = PLAYER_STOP_LEFT;
		game->player->animation_status = PLAYER_STOP_LEFT;
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		exit(1);
	}
}

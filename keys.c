#include <stdlib.h>
#include "player.h"
#include "MLX42/include/MLX42/MLX42.h"
#include "solong.h"


void ft_hook_keys(void *game2)
{
	t_game *game;

	game = game2;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		move_up(game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		move_down(game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		move_left(game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		move_right(game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
		turbo_shift(game->player);
}

void key_hook(mlx_key_data_t keydata, void* game2)
{
	t_game *game;

	game = game2;
	if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_RELEASE)
		game->player->speed = 1;
}

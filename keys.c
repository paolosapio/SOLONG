#include <stdlib.h>
#include "player.h"
#include "MLX42/include/MLX42/MLX42.h"
#include "solong.h"


void ft_hook_keys(void *data2)
{
	t_mlx_player *data;

	data = data2;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		move_up(data->player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		move_down(data->player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		move_left(data->player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		move_right(data->player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
		turbo_shift(data->player);
}

void key_hook(mlx_key_data_t keydata, void* data2)
{
	t_mlx_player *data;

	data = data2;
	if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_RELEASE)
		data->player->speed = 1;
}

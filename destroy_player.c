#include <stdlib.h>
#include "player.h"
#include "MLX42/include/MLX42/MLX42.h"
#include "solong.h"

void destroy_player(mlx_t *mlx, t_player *player)
{
	int i;

	i= 0;
	while (i < player->number_of_animations)
	{
		destroy_animation(mlx, player->animations[i]);
		i++;
	}
	free(player->animations);
	free(player);
	return ;
}

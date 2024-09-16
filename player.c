#include <stdlib.h>
#include "player.h"
#include "MLX42/include/MLX42/MLX42.h"
#include "solong.h"


void destroy_player(mlx_t *mlx, t_player *player)
{
	destroy_animation(mlx, player->animation);
	free(player);
	return ;
}

#include <stdlib.h>
#include "player.h"
#include "MLX42/include/MLX42/MLX42.h"
#include "solong.h"


void destroy_player(mlx_t *mlx, t_player *player)
{
	mlx_delete_image(mlx, player->image_sprite);
	free(player);

	return ;
}

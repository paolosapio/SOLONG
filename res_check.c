#include "solong.h"
#include "MLX42/include/MLX42/MLX42.h"

void	res_check(t_game data)
{
	int32_t		width;
	int32_t		height;

	mlx_get_monitor_size(0, &width, &height);
	
	if (width > 3840 && height >2160)
	{
		destroy_all(data);
		exit(1);
	}

}
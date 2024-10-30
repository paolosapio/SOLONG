#include "solong.h"

void	res_check(t_game data)
{
	const int	game_size_width = data.map.width * 32;
	const int	game_size_height = data.map.height * 32;

	if (game_size_width > 1920 || game_size_height > 1080)
	{
		printf("hola pepe\n");
		// destroy_all(data);
		exit(1);

	}
}

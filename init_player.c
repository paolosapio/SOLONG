#include "player.h"

t_player *init_player(void	*mlx)
{
	t_player		*player;
    char            *paths[20];

	player = malloc(sizeof(t_player));//proteger
	player->x = 1280 / 2;
	player->y = 720 / 2;
	player->speed = 1;

    paths[0] = "sprites/billy/respiro/BillyBoy_statico_01.png";
    paths[1] = "sprites/billy/respiro/BillyBoy_statico_02.png";
    paths[2] = "sprites/billy/respiro/BillyBoy_statico_03.png";
    paths[3] = "sprites/billy/respiro/BillyBoy_statico_03.png";
    paths[4] = "sprites/billy/respiro/BillyBoy_statico_02.png";
    paths[5] = "sprites/billy/respiro/BillyBoy_statico_01.png";
    paths[6] = "sprites/billy/respiro/BillyBoy_statico_01.png";
    paths[7] = "sprites/billy/respiro/BillyBoy_statico_01.png";
    paths[8] = "sprites/billy/respiro/BillyBoy_statico_02.png";
    paths[9] = "sprites/billy/respiro/BillyBoy_statico_03.png";
    paths[10] = "sprites/billy/respiro/BillyBoy_statico_02.png";
    paths[11] = "sprites/billy/respiro/BillyBoy_statico_01.png";
    paths[12] = "sprites/billy/respiro/BillyBoy_statico_01.png";
    paths[13] = "sprites/billy/respiro/BillyBoy_statico_01.png";
    paths[14] = "sprites/billy/mirada_atras/BillyBoy_statico_04.png";
    paths[15] = "sprites/billy/mirada_atras/BillyBoy_statico_05.png";
    paths[16] = "sprites/billy/mirada_atras/BillyBoy_statico_06.png";
    paths[17] = "sprites/billy/mirada_atras/BillyBoy_statico_06.png";
    paths[18] = "sprites/billy/mirada_atras/BillyBoy_statico_05.png";
    paths[19] = "sprites/billy/mirada_atras/BillyBoy_statico_04.png";
    player->animation = init_animation(mlx, 20, paths);
    player->animation->image->instances[0].x = player->x;
    player->animation->image->instances[0].y = player->y;
	return(player);
}

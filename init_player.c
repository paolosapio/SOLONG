#include "player.h"

t_player *init_player(void	*mlx)
{
	t_player		*player;
    char            *paths[8];

	player = malloc(sizeof(t_player));//proteger
	player->x = 1280 / 2;
	player->y = 720 / 2;
	player->speed = 1;

    paths[0] = "sprites/billyboy/to_right/walk/no_wapons/01.png";
    paths[1] = "sprites/billyboy/to_right/walk/no_wapons/02.png";
    paths[2] = "sprites/billyboy/to_right/walk/no_wapons/03.png";
    paths[3] = "sprites/billyboy/to_right/walk/no_wapons/04.png";
    paths[4] = "sprites/billyboy/to_right/walk/no_wapons/05.png";
    paths[5] = "sprites/billyboy/to_right/walk/no_wapons/06.png";
    paths[6] = "sprites/billyboy/to_right/walk/no_wapons/07.png";
    paths[7] = "sprites/billyboy/to_right/walk/no_wapons/08.png";

    player->animation = init_animation(mlx, 8, paths);
    player->animation->image->instances[0].x = player->x;
    player->animation->image->instances[0].y = player->y;
	return(player);
}

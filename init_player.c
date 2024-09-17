#include "player.h"

t_player *init_player(void	*mlx)
{
	t_player		*player;
    char            *paths_walk_to_right[8];
    char            *paths_breath[6];

	player = malloc(sizeof(t_player));//proteger
	player->x = 1280 / 2;
	player->y = 720 / 2;
	player->speed = 3;

    paths_walk_to_right[0] = "sprites/billyboy/to_right/walk/no_wapons/01.png";
    paths_walk_to_right[1] = "sprites/billyboy/to_right/walk/no_wapons/02.png";
    paths_walk_to_right[2] = "sprites/billyboy/to_right/walk/no_wapons/03.png";
    paths_walk_to_right[3] = "sprites/billyboy/to_right/walk/no_wapons/04.png";
    paths_walk_to_right[4] = "sprites/billyboy/to_right/walk/no_wapons/05.png";
    paths_walk_to_right[5] = "sprites/billyboy/to_right/walk/no_wapons/06.png";
    paths_walk_to_right[6] = "sprites/billyboy/to_right/walk/no_wapons/07.png";
    paths_walk_to_right[7] = "sprites/billyboy/to_right/walk/no_wapons/08.png";

    paths_breath[0] = "sprites/billyboy/breath/01.png";
    paths_breath[1] = "sprites/billyboy/breath/02.png";
    paths_breath[2] = "sprites/billyboy/breath/03.png";
    paths_breath[3] = "sprites/billyboy/breath/04.png";
    paths_breath[4] = "sprites/billyboy/breath/05.png";
    paths_breath[5] = "sprites/billyboy/breath/06.png";

    player->animations = malloc(sizeof(t_animation*) * 2);

    player->animations[0] = init_animation(mlx, 8, paths_walk_to_right);
    player->animations[0]->speed_frame = 9;
    player->animations[0]->image->instances[0].x = player->x;
    player->animations[0]->image->instances[0].y = player->y;

    player->animations[1] = init_animation(mlx, 6, paths_breath);
    player->animations[1]->speed_frame = 9;
    player->animations[1]->image->instances[0].x = player->x;
    player->animations[1]->image->instances[0].y = player->y;
    player->number_of_animations = 2;
	return(player);
}

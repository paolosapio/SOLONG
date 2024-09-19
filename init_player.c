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
    player->number_of_animations = 2;
    player->animation_status = 0;//nueva variable para saber que animacion

    paths_breath[0] = "sprites/billyboy/breath/01.png";
    paths_breath[1] = "sprites/billyboy/breath/02.png";
    paths_breath[2] = "sprites/billyboy/breath/03.png";
    paths_breath[3] = "sprites/billyboy/breath/04.png";
    paths_breath[4] = "sprites/billyboy/breath/05.png";
    paths_breath[5] = "sprites/billyboy/breath/06.png";

    paths_walk_to_right[0] = "sprites/billyboy/to_right/walk/no_wapons/01.png";
    paths_walk_to_right[1] = "sprites/billyboy/to_right/walk/no_wapons/02.png";
    paths_walk_to_right[2] = "sprites/billyboy/to_right/walk/no_wapons/03.png";
    paths_walk_to_right[3] = "sprites/billyboy/to_right/walk/no_wapons/04.png";
    paths_walk_to_right[4] = "sprites/billyboy/to_right/walk/no_wapons/05.png";
    paths_walk_to_right[5] = "sprites/billyboy/to_right/walk/no_wapons/06.png";
    paths_walk_to_right[6] = "sprites/billyboy/to_right/walk/no_wapons/07.png";
    paths_walk_to_right[7] = "sprites/billyboy/to_right/walk/no_wapons/08.png";

    player->animations = malloc(sizeof(t_animation*) * 2);

    player->animations[0] = init_animation(mlx, 6, paths_breath);
    player->animations[0]->speed_frame = 9;
    player->image = mlx_texture_to_image(mlx, player->animations[0]->textures[0]); 
    player->animations[0]->image = player->image;

    player->animations[1] = init_animation(mlx, 8, paths_walk_to_right);
    player->animations[1]->speed_frame = 9;
    player->animations[1]->image = player->image;
    mlx_image_to_window(mlx, player->image, 0, 0); //llamada final paara ver el fotograma completo en ventana

	return(player);
}

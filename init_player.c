#include "player.h"

t_player *init_player(mlx_t	*mlx)
{
	t_player    *player;
    char        *paths_walk_to_up[5];
    char        *paths_walk_to_down[4];
    char        *paths_walk_to_right[8];
    char        *paths_walk_to_left[8];
    char        *paths_breath_left[6];
    char        *paths_breath_right[6];

	player = malloc(sizeof(t_player));
	player->x = 0;
	player->y = 0;
	player->speed = 3;
    player->number_of_animations = 6;
    player->animation_status = 0;
    player->switch_button = 0;

    paths_breath_left[0] = "sprites/billyboy/to_left/breath/01.png";
    paths_breath_left[1] = "sprites/billyboy/to_left/breath/02.png";
    paths_breath_left[2] = "sprites/billyboy/to_left/breath/03.png";
    paths_breath_left[3] = "sprites/billyboy/to_left/breath/04.png";
    paths_breath_left[4] = "sprites/billyboy/to_left/breath/05.png";
    paths_breath_left[5] = "sprites/billyboy/to_left/breath/06.png";

    paths_breath_right[0] = "sprites/billyboy/to_right/breath/01.png";
    paths_breath_right[1] = "sprites/billyboy/to_right/breath/02.png";
    paths_breath_right[2] = "sprites/billyboy/to_right/breath/03.png";
    paths_breath_right[3] = "sprites/billyboy/to_right/breath/04.png";
    paths_breath_right[4] = "sprites/billyboy/to_right/breath/05.png";
    paths_breath_right[5] = "sprites/billyboy/to_right/breath/06.png";

    paths_walk_to_right[0] = "sprites/billyboy/to_right/walk/no_wapons/01.png";
    paths_walk_to_right[1] = "sprites/billyboy/to_right/walk/no_wapons/02.png";
    paths_walk_to_right[2] = "sprites/billyboy/to_right/walk/no_wapons/03.png";
    paths_walk_to_right[3] = "sprites/billyboy/to_right/walk/no_wapons/04.png";
    paths_walk_to_right[4] = "sprites/billyboy/to_right/walk/no_wapons/05.png";
    paths_walk_to_right[5] = "sprites/billyboy/to_right/walk/no_wapons/06.png";
    paths_walk_to_right[6] = "sprites/billyboy/to_right/walk/no_wapons/07.png";
    paths_walk_to_right[7] = "sprites/billyboy/to_right/walk/no_wapons/08.png";

    paths_walk_to_left[0] = "sprites/billyboy/to_left/walk/no_wapons/01.png";
    paths_walk_to_left[1] = "sprites/billyboy/to_left/walk/no_wapons/02.png";
    paths_walk_to_left[2] = "sprites/billyboy/to_left/walk/no_wapons/03.png";
    paths_walk_to_left[3] = "sprites/billyboy/to_left/walk/no_wapons/04.png";
    paths_walk_to_left[4] = "sprites/billyboy/to_left/walk/no_wapons/05.png";
    paths_walk_to_left[5] = "sprites/billyboy/to_left/walk/no_wapons/06.png";
    paths_walk_to_left[6] = "sprites/billyboy/to_left/walk/no_wapons/07.png";
    paths_walk_to_left[7] = "sprites/billyboy/to_left/walk/no_wapons/08.png";

    paths_walk_to_up[0] = "sprites/billyboy/to_up/walk/no_wapons/01.png";
    paths_walk_to_up[1] = "sprites/billyboy/to_up/walk/no_wapons/02.png";
    paths_walk_to_up[2] = "sprites/billyboy/to_up/walk/no_wapons/03.png";
    paths_walk_to_up[3] = "sprites/billyboy/to_up/walk/no_wapons/04.png";
    paths_walk_to_up[4] = "sprites/billyboy/to_up/walk/no_wapons/05.png";

    paths_walk_to_down[0] = "sprites/billyboy/to_down/walk/no_wapons/01.png";
    paths_walk_to_down[1] = "sprites/billyboy/to_down/walk/no_wapons/02.png";
    paths_walk_to_down[2] = "sprites/billyboy/to_down/walk/no_wapons/03.png";
    paths_walk_to_down[3] = "sprites/billyboy/to_down/walk/no_wapons/04.png";

    player->animations = malloc(sizeof(t_animation*) * player->number_of_animations);

    player->animations[PLAYER_STOP_RIGHT] = init_animation(mlx, 6, paths_breath_right);
    player->image = mlx_texture_to_image(mlx, player->animations[PLAYER_STOP_RIGHT]->textures[0]); 
    player->animations[PLAYER_STOP_RIGHT]->speed_frame = 9;
    player->animations[PLAYER_STOP_RIGHT]->image = player->image;

    player->animations[PLAYER_STOP_LEFT] = init_animation(mlx, 6, paths_breath_left);
    player->animations[PLAYER_STOP_LEFT]->speed_frame = 9;
    player->animations[PLAYER_STOP_LEFT]->image = player->image;

    player->animations[PLAYER_RIGHT] = init_animation(mlx, 8, paths_walk_to_right);
    player->animations[PLAYER_RIGHT]->speed_frame = 9;
    player->animations[PLAYER_RIGHT]->image = player->image;

    player->animations[PLAYER_LEFT] = init_animation(mlx, 8, paths_walk_to_left);
    player->animations[PLAYER_LEFT]->speed_frame = 9;
    player->animations[PLAYER_LEFT]->image = player->image;

    player->animations[PLAYER_UP] = init_animation(mlx, 5, paths_walk_to_up);
    player->animations[PLAYER_UP]->speed_frame = 9;
    player->animations[PLAYER_UP]->image = player->image;

    player->animations[PLAYER_DOWN] = init_animation(mlx, 4, paths_walk_to_down);
    player->animations[PLAYER_DOWN]->speed_frame = 9;
    player->animations[PLAYER_DOWN]->image = player->image;

    mlx_image_to_window(mlx, player->image, 0, 0); //llamada final paara ver el fotograma completo en ventana

	return(player);
}

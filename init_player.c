#include "player.h"

t_player *init_player(mlx_t	*mlx)
{
	t_player    *player;
    t_textures_files textures;

	player = malloc(sizeof(t_player));
	player->x = 0;
	player->y = 0;
	player->speed = 3;
    player->number_of_animations = 6;
    player->animation_status = 0;
    player->switch_button = 0;

   breath(&textures);
   walk(&textures);

    player->animations = malloc(sizeof(t_animation*) * player->number_of_animations);

    player->animations[PLAYER_STOP_RIGHT] = init_animation(mlx, 6, textures.paths_breath_right);
    player->image = mlx_texture_to_image(mlx, player->animations[PLAYER_STOP_RIGHT]->textures[0]);
//    mlx_resize_image(player->image, IMG_SIZE, IMG_SIZE * 2);
    player->animations[PLAYER_STOP_RIGHT]->speed_frame = 9;
    player->animations[PLAYER_STOP_RIGHT]->image = player->image;

    player->animations[PLAYER_STOP_LEFT] = init_animation(mlx, 6, textures.paths_breath_left);
    player->animations[PLAYER_STOP_LEFT]->speed_frame = 9;
    player->animations[PLAYER_STOP_LEFT]->image = player->image;

    player->animations[PLAYER_RIGHT] = init_animation(mlx, 8, textures.paths_walk_to_right);
    player->animations[PLAYER_RIGHT]->speed_frame = 9;
    player->animations[PLAYER_RIGHT]->image = player->image;

    player->animations[PLAYER_LEFT] = init_animation(mlx, 8, textures.paths_walk_to_left);
    player->animations[PLAYER_LEFT]->speed_frame = 9;
    player->animations[PLAYER_LEFT]->image = player->image;

    player->animations[PLAYER_UP] = init_animation(mlx, 5, textures.paths_walk_to_up);
    player->animations[PLAYER_UP]->speed_frame = 9;
    player->animations[PLAYER_UP]->image = player->image;

    player->animations[PLAYER_DOWN] = init_animation(mlx, 4, textures.paths_walk_to_down);
    player->animations[PLAYER_DOWN]->speed_frame = 9;
    player->animations[PLAYER_DOWN]->image = player->image;

    mlx_image_to_window(mlx, player->image, 0, 0);
    mlx_set_instance_depth(&player->image->instances[0], 2);

	return(player);
}

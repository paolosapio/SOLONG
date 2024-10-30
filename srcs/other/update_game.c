#include "solong.h"

void update_game(void *game)
{
    t_game *game1;

    game1 = (t_game *)game;
	//mlx_delete_image(game1->mlx, game1->player.animations[game1->player.anim_stat].image);
    update_player(game1, &game1->player, &game1->map);
    // write(1, "\033cSteps: ", 10);
    // ft_putnbr_fd(game1->player->steps / 32, 1);
    // write(1, "\n", 1);
}
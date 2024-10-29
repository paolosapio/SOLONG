#include "solong.h"

void update_game(void *game)
{
    t_game *game1;

    game1 = (t_game *)game;
    update_player(game1->player, game1->map);
    // write(1, "\033cSteps: ", 10);
    // ft_putnbr_fd(game1->player->steps / 32, 1);
    // write(1, "\n", 1);
}
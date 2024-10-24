#include "solong.h"

void update_game(void *game)
{
    t_game *game1;

    game1 = (t_game *)game;
    update_player(game1->player, game1->map);
}
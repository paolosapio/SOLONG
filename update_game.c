#include "solong.h"

void update_game(t_game *game)
{
    update_player(game->player, game->map);
}
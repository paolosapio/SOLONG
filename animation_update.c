#include <stdlib.h>
#include "player.h"
#include "solong.h"
#include "MLX42/include/MLX42/MLX42.h"

void animation_update(t_animation *animation)
{    
     if (animation->current_frame_total_game % animation->speed_frame == 0)
        animation_next_texture(animation);
     animation->current_frame_total_game++;
}
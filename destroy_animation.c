#include "animation.h"
#include <stdlib.h>

void destroy_animation(mlx_t *mlx, t_animation *animation)
{
    int i;

    i = 0;
    while(i< animation->total_texture)
    {
        mlx_delete_texture(animation->textures[i]);
        i++;
    }
    mlx_delete_image(mlx, animation->image);
    free (animation->textures);
    free (animation);
}

#include "animation.h"
#include <stdlib.h>

t_animation *init_animation(mlx_t *mlx, int n_frames, char **pat_png)
{
    t_animation *animation;
    int i;
    i = 0;
    animation = malloc(sizeof(t_animation));
    animation->textures = malloc(n_frames * sizeof(mlx_texture_t*));
    while (i< n_frames)
    {
        animation->textures[i] = mlx_load_png(pat_png[i]);
        i++;
    }
    animation->speed_frame = 1;
    animation->current_frame_total_game = 0;
    animation->total_texture = n_frames;
    animation->current_texture = 0;
    return (animation);
}

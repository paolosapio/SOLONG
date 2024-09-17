
#include "animation.h"
#include "libft/libft.h"
#include <stdio.h>

void animation_next_texture(t_animation *animation)
{
	if (animation->current_texture == animation->total_texture)
		animation->current_texture = 0;
	ft_memmove(animation->image->pixels, animation->textures[animation->current_texture]->pixels, animation->textures[animation->current_texture]->width * animation->textures[animation->current_texture]->height * sizeof(int));
	animation->current_texture++;
}

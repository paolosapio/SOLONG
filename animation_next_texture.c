
#include "animation.h"
#include "libft/libft.h"
#include <stdio.h>

void animation_next_texture(t_animation *animation)
{
	int index;
	index = animation->current_texture % animation->total_texture;

	ft_memmove(animation->image->pixels, animation->textures[index]->pixels, animation->textures[index]->width * animation->textures[index]->height * sizeof(int));
	animation->current_texture++;
}

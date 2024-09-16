
#include "animation.h"
#include "libft/libft.h"
#include <stdio.h>

void animation_next_texture(t_animation *animation)
{
	int index;
	index = animation->current_frame % animation->total_texture; // AQUI he solucionado inicializando total teexure
	ft_memmove(animation->image->pixels, animation->textures[index]->pixels, animation->textures[index]->width * animation->textures[index]->height * sizeof(int));
	animation->current_texture++;
}

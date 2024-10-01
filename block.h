#ifndef BLOCK_H
# define BLOCK_H

# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include "animation.h"

typedef struct	s_block
{
	int				x;
	int				y;
	mlx_image_t		*image;
	int				collision;
	
}					t_block;

#endif
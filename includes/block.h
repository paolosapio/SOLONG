#ifndef BLOCK_H
# define BLOCK_H

# include <stdlib.h>
# include "solong.h"

typedef struct	s_block
{
	int				x;
	int				y;
	mlx_image_t		*image;
	int				collision;
	
}					t_block;

#endif
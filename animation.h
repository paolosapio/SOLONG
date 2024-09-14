 #ifndef ANIMATION_H
# define ANIMATION_H

#include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>

typedef struct s_animation
{
	mlx_texture_t	**textures;
	int				current_texture;
	int				total_texture;
	mlx_image_t		*image;
	int				speed_frame;
	int				current_frame;
}               t_animation;

void		animation_next_texture(t_animation *animation);
t_animation	*init_animation(mlx_t *mlx, int n_frames, char **pat_png);
void		animation_update(t_animation *animation);
void		destoy_animation(mlx_t *mlx, t_animation *animation);

#endif
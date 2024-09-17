 #ifndef ANIMATION_H
# define ANIMATION_H

#include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>



typedef struct s_animation
{
	mlx_texture_t	**textures; //puntero a animacionees (array de array de texturas)
	int				current_texture; //indice del fotograma actaula para poner en imagen
	int				total_texture; //texturas totales que definen una anumacion
	mlx_image_t		*image; //puntero a imagen de la mlx al cual le pasamos las texturas
	int				speed_frame; //no lo se
	int				current_frame_total_game; // contador de los fotogramas totales del juego
}               t_animation;

void		animation_next_texture(t_animation *animation);
t_animation	*init_animation(mlx_t *mlx, int n_frames, char **pat_png);
void		animation_update(t_animation *animation);
void		destroy_animation(mlx_t *mlx, t_animation *animation);

#endif
#ifndef MAP_H
# define MAP_H

# include "MLX42/include/MLX42/MLX42.h"

typedef struct	s_map
{
	int	    width;
	int	    height;
	char    **str_map;
}   t_map;

t_map		*init_map(char **map);
void        destroy_map(t_map *map);
void		paint_map(mlx_t *mlx, t_map *map);

#endif
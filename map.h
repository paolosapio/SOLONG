#ifndef MAP_H
# define MAP_H

# include "MLX42/include/MLX42/MLX42.h"

typedef struct	s_map
{
	int	    width;
	int	    height;
	char    **str_map;
}   t_map;

typedef struct	s_hitbox
{
	int	    width;
	int	    height;
}   t_hitbox;

t_map		*init_map(char **map);
void        destroy_map(t_map *map);
void		paint_map(mlx_t *mlx, t_map *map);
char		query_map_coordinate(t_map *map, int y, int x);

#endif
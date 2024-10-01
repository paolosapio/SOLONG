#ifndef MAP_H
# define MAP_H

typedef struct	s_map
{
	int	    width;
	int	    height;
	char    **str_map;	
}   t_map;

t_map		*init_map(char **map);
void        destroy_map(t_map *map);
int			parsek_map(str_map);

#endif
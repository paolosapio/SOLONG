#ifndef PARSER_H
# define PARSER_H

# include "MLX42/include/MLX42/MLX42.h"
# include "coordinate.h"

typedef struct	s_parser
{
	t_coordinate	player;
	t_coordinate	exit;
	char			**str_map;
	int				total_collectables;
}   t_parser;

t_parser	*parser_map(char *path_map);
int			check_rectangle_map(char **map);
int			check_closed_map(char **map);
bool		flood_fill(t_parser *parser);

#endif
#ifndef PARSER_H
# define PARSER_H

# include "MLX42/include/MLX42/MLX42.h"
# include "coordinate.h"

typedef struct	s_parser
{
	t_coordinate	player;
	char			**str_map;
}   t_parser;

t_parser *parser_map(char *path_map);

#endif
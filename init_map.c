#include "solong.h"
#include "libft/libft.h"
#include "parser.h"

t_map *init_map(t_parser *parser)
{
	t_map	*map;
	int		x;
    int     y;
	map = malloc(sizeof(t_map));
	if(!map)
		return (NULL);
    map->width = ft_strlen(parser->str_map[0]);
	y = 0;
	while (parser->str_map[y] != NULL)
	{
		y++;
	}
	map->height = y;
	map->str_map = parser->str_map;
	map->total_collectables = parser->total_collectables;
	map->collectables_to_take = 0;
	printf("totales botellas: %d\n", map->total_collectables);

    return  (map);
}

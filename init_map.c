#include "solong.h"
#include "libft/libft.h"

t_map *init_map(char **str_map)
{
	t_map	*map;
	int		x;
    int     y;
	map = malloc(sizeof(t_map));
	if(!map)
		return (NULL);
    map->width = ft_strlen(str_map[0]);
	y = 0;
	while (str_map[y] != NULL)
	{
		y++;
	}
	map->height = y;
	map->str_map = str_map;
    return  (map);
}

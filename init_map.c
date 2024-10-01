#include "solong.h"
#include "libft/libft.h"

t_map *init_map(char **str_map)
{
	t_map	*map;
	int		i;
    int     y;

	map = malloc(sizeof(t_map));
	if(!map)
		return (NULL);
    map->width = ft_strlen(str_map[0]);
	i = 0;
	while (str_map[i] != NULL)
	{
		i++;
	}

	map->str_map = malloc(i * sizeof(char*));
	
    map->height = i;

    y = 0;
    while (y < map->height)
    {
        map->str_map[y] = ft_strdup(str_map[y]);
        y++;    
    }
    return  (map);
}

#include "parser.h"
#include "solong.h"
#include "libft/libft.h"

int elements_count_map(char **map)
{
    int counts[3];
    int x;
    int y;

    counts[0] = 0;
    counts[1] = 0;
    counts[2] = 0;
    y = 0;
    while (map[y] != NULL)
    {
        x = -1;
        while (map[y][++x] != '\0')
        {
            if ((map[y][x] == 'P') && (++counts[0] == 2))
                return (1);
            if ((map[y][x] == 'E') && (++counts[1] == 2))
                return (1);
            if (map[y][x] == 'C')
                counts[2]++;
        }
        y++;
    }
    if ((counts[0] == 0) || (counts[1] == 0) || (counts[2] == 0))
        return (1);
    return (0);
}

flood_fill(char **map, int collectables)
{
    //hacer el floodfill que detecte que el player pueda llegar a 'E' y a los 'C'
}
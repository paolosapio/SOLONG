#include "solong.h"

char **read_n_copy_map(char *path_map)
{
    int fd;
    int i;
    int k;
    char **str_map;

    fd = open(path_map, O_RDONLY);
    i = 0;
    while (get_next_line(fd) != NULL)
    {
        i++;
    }
    str_map = malloc(sizeof(char*) * i + 1);
    k = i;
    i = 0;
    close(fd);
    fd = open(path_map, O_RDONLY);

    while (i < k)
    {
        str_map[i] = get_next_line(fd);
        printf("%s", str_map[i]);
        i++;
    }
    str_map[i] = NULL;
    
    parsek_map(str_map);

    return(str_map);
}
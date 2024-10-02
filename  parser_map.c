#include "parser.h"
#include "solong.h"

t_parser *parser_map(char *path_map)
{
    t_parser *parser;
    int x;
    int y;

    x = 0;
    y = 0;
    parser = malloc(sizeof(t_parser));
    parser->str_map = read_n_copy_map(path_map);
    while (parser->str_map[y] != NULL)
    {
        x = 0;
        while (parser->str_map[y][x] != '\0')
        {
            if (parser->str_map[y][x] == 'P')
            {
                parser->str_map[y][x] = '0';
                parser->player.x = x * 32;
                parser->player.y = y * 32;
            }
            x++;
        }
        y++;
    }
    return (parser);
}

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
    str_map = malloc(sizeof(char*) * (i + 1));
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
    close(fd);
    str_map[i] = NULL;
    return(str_map);
}
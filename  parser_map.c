#include "parser.h"
#include "solong.h"
#include "libft/libft.h"
t_parser *parser_map(char *path_map)
{
	t_parser *parser;
	int x;
	int y;

	x = 0;
	y = 0;
	parser = malloc(sizeof(t_parser));
	parser->str_map = read_n_copy_map(path_map);
	if (check_rectangle_map(parser->str_map) == 1)
		return (NULL); //liberar el mapa  **char (hacer una funcion qeu libera el pun ero doble)
	if (check_closed_map(parser->str_map) == 1)
		return (NULL); //liberar el mapa  **char (hacer una funcion qeu libera el pun ero doble)
	if (flood_fill(parser->str_map) == 1)
			return (NULL);
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
			if (parser->str_map[y][x] == 'E')
			{
				parser->exit.x = x * 32;
				parser->exit.y = y * 32;
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
	char *aux;
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
		aux = get_next_line(fd);
		str_map[i] = ft_strtrim(aux, "\n");
		free(aux);
		printf("%s\n", str_map[i]);
		i++;
	}
	close(fd);
	str_map[i] = NULL;
	return(str_map);
}
int check_rectangle_map(char **map)
{
	int i;

	i = 0;
	while ((map[i] != NULL) && map[i + 1] != NULL)
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			return (1);
		i++;
	}
	if (i < 2)
	    return (1);
	if (ft_strlen(map[0]) < 3)
		return (1);
	return (0);
}

int check_closed_map(char **map)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (map[0][x] != '\0')
	{
		if (map[0][x] != '1')
			return (1);
		x++;
	}
	while (map[y] != NULL)
	{
		if (map[y][0] != '1')
			return (1);
		if (map[y][ft_strlen(map[y]) - 1] != '1')
			return (1);
		y++;
	}
	x = 0;
	y--;
	while (map[y][x] != '\0')
	{
		if (map[y][x] != '1')
			return (1);
		x++;
	}
	return (0);
}
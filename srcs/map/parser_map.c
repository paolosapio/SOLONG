/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:18:07 by psapio            #+#    #+#             */
/*   Updated: 2024/10/30 13:35:37 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"


void parser_map(t_parser *parser, char *path_map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	parser->str_map = read_n_copy_map(path_map);
	if (check_chars_map(parser->str_map) == 1)
		ft_print_error("Parser map error");
	if (check_rectangle_map(parser->str_map) == 1)
		ft_print_error("Parser map error"); //liberar el mapa  **char (hacer una funcion qeu libera el pun ero doble)
	if (check_closed_map(parser->str_map) == 1)
		ft_print_error("Parser map error"); //liberar el mapa  **char (hacer una funcion qeu libera el pun ero doble)
	if (flood_fill(parser) == 1)
		ft_print_error("Parser map error");
	while (parser->str_map[y] != NULL)
	{
		x = 0;
		while (parser->str_map[y][x] != '\0')
		{
			if (parser->str_map[y][x] == 'P')
			{
				parser->str_map[y][x] = '0';
				parser->player.x = x * IMG_SIZE;
				parser->player.y = y * IMG_SIZE;
			}
			if (parser->str_map[y][x] == 'E')
			{
				parser->exit.x = x * IMG_SIZE;
				parser->exit.y = y * IMG_SIZE;
			}
			x++;
		}
		y++;
	}
}

char **read_n_copy_map(char *path_map)
{
	int fd;
	int i;
	char **str_map;
	char *aux;
	char *line;
	
	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		ft_print_error("can't open file");
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free (line);
		i++;
	}
	str_map = malloc(sizeof(char*) * (i + 1));
	i = 0;
	close(fd);
	fd = open(path_map, O_RDONLY);
	while (1)
	{
		aux = get_next_line(fd);
		str_map[i] = ft_strtrim(aux, "\n");
		if (str_map[i] == NULL)
			break ;
		free(aux);
		printf("%s\n", str_map[i]);
		i++;
	}
	close(fd);
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

int	check_chars_map(char **path_map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (path_map[y] != NULL)
	{
		x = 0;
		while (path_map[y][x] != '\0') 
		{
			if (ft_strchr("01PEC", path_map[y][x]) == NULL)
			{
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
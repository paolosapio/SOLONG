#include "parser.h"
#include "solong.h"
#include "libft/libft.h"

int count_collectables_map(t_parser *parser)
{
	int counts[3];
	int x;
	int y;

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	y = 0;
	while (parser->str_map[y] != NULL)
	{
		x = -1;
		while (parser->str_map[y][++x] != '\0')
		{
			if ((parser->str_map[y][x] == 'P') && (++counts[0] == 2))
				return (0);
			if (parser->str_map[y][x] == 'C')
				counts[1]++;
			if ((parser->str_map[y][x] == 'E') && (++counts[2] == 2))
				return (0);
		}
		y++;
	}
	if ((counts[0] == 0) || (counts[1] == 0) || (counts[2] == 0))
		return (0);
	parser->total_collectables = counts[1];
	return (counts[1]);
}

void serch_objects(char **map, int *objects, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] < 0)
		return ;
	if (map[y][x] == 'C')
		objects[0]++;
	if (map[y][x] == 'E')
		objects[1]++;
	map[y][x] *= -1;
	serch_objects(map, objects, y + 1, x);
	serch_objects(map, objects, y - 1, x);
	serch_objects(map, objects, y, x + 1);
	serch_objects(map, objects, y, x - 1);
	return ;
}
void map_positive_converter(char **map)
{
	int y;
	int x;

	y = 0;
   while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] < 0)
				map[y][x] *= -1;
			x++;
		}
		y++;
	}
}
bool flood_fill(t_parser *parser)
{
	int objects[2] = {0, 0};
	int y;
	int x;
	int flag;

	flag = 0;
	y = 0;
	while (parser->str_map[y] != NULL)
	{
		x = 0;
		while (parser->str_map[y][x] != '\0')
		{
			if (parser->str_map[y][x] == 'P')
			{
				flag = 1;
				break;
			}
			x++;
		}
		if (flag == 1)
			break;
		y++;
	}
	if (flag == 0)
		return (1);
	serch_objects(parser->str_map, objects, y, x);
	map_positive_converter(parser->str_map);
	if ((count_collectables_map(parser) != objects[0]) || (objects[0] == 0))
		return (1);
   if (objects[1] != 1)
		return (true);
	return (false);
}

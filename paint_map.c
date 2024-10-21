#include <stdlib.h>
#include "player.h"
#include "solong.h"
#include "MLX42/include/MLX42/MLX42.h"	

//funcion VOID para eescrivir en ventana 


void paint_map(mlx_t *mlx, t_map *map)
{
	mlx_texture_t	*paviment;
	mlx_texture_t	*pc;
	mlx_texture_t	*bottle;
	int				x;
	int				y;

	x = 0;
	y = 0;
	paviment = mlx_load_png("sprites/texturas/paviment_claster.png");
	map->image_paviment = mlx_texture_to_image(mlx, paviment);
	mlx_resize_image(map->image_paviment, IMG_SIZE, IMG_SIZE);

	mlx_delete_texture(paviment);
	bottle = mlx_load_png("sprites/texturas/bottle.png");
	map->image_bottle = mlx_texture_to_image(mlx, bottle);
	mlx_resize_image(map->image_bottle, IMG_SIZE, IMG_SIZE);

	mlx_delete_texture(bottle);
	pc = mlx_load_png("sprites/texturas/pc.png");
	map->image_pc = mlx_texture_to_image(mlx, pc);
	mlx_resize_image(map->image_pc, IMG_SIZE, IMG_SIZE);
	mlx_delete_texture(pc);
	while (y < map->height * IMG_SIZE)
	{
		x = 0;
		while (x < map->width * IMG_SIZE)
		{
			if (map->str_map[y / IMG_SIZE][x / IMG_SIZE] == '0')
			{
				int instance = mlx_image_to_window(mlx, map->image_paviment, x, y);
				mlx_set_instance_depth(&map->image_paviment->instances[instance], 0);
			}
			if (map->str_map[y / IMG_SIZE][x / IMG_SIZE] == '1')
			{
				int instance = mlx_image_to_window(mlx, map->image_pc, x, y);
				mlx_set_instance_depth(&map->image_pc->instances[instance], 0);
			}
			if (map->str_map[y / IMG_SIZE][x / IMG_SIZE] == 'C')
			{
				int instance = mlx_image_to_window(mlx, map->image_bottle, x, y);
				mlx_set_instance_depth(&map->image_bottle->instances[instance], 0);
			}
			x += IMG_SIZE;
		}
		y += IMG_SIZE;
	}
}
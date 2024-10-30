/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:53:06 by psapio            #+#    #+#             */
/*   Updated: 2024/10/30 16:59:26 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include "MLX42/MLX42.h"
# include "libft.h"

typedef struct	game t_game;
typedef struct	s_parser t_parser;


/* MAP */
# define IMG_SIZE 64
typedef struct	s_map
{
	mlx_image_t		*image_paviment;
	mlx_image_t		*image_pc;
	mlx_image_t		*image_bottle;
	mlx_t			*mlx;
	int				width;
	int				height;
	char			**str_map;
	int				total_collectables;
	int				collectables_to_take;
}   t_map;

typedef struct	s_hitbox
{
	int	width;
	int	height;
}   t_hitbox;


void		init_map(t_game *data, t_parser *parser);
void		destroy_map(t_map *map);
void		paint_map(mlx_t *mlx, t_map *map);
char		query_map_coordinate(t_map *map, int y, int x);
int32_t		change_texture_map(t_map *map, int y, int x);
int			check_chars_map(char **path_map);


/* ANIMATIONS */
typedef struct s_animation
{
	mlx_texture_t	**textures;
	mlx_image_t		*image;
	int				current_texture;
	int				total_texture;
	int				speed_frame;
	int				current_frame_total_game;
}               t_animation;

void	init_animation(t_animation *animation, mlx_t *mlx, int n_frames, char **pat_png);
void	animation_next_texture(t_game *game, t_animation *animation);
void	animation_update(t_game *game, t_animation *animation);
void	destroy_animation(mlx_t *mlx, t_animation *animation);


/* PLAYER */
# define PLAYER_STOP_RIGHT		0
# define PLAYER_LEFT			1
# define PLAYER_RIGHT			2
# define PLAYER_UP				3
# define PLAYER_DOWN			4
# define PLAYER_STOP_LEFT		5
# define PLAYER_STOP_UP			6
# define PLAYER_STOP_DOWN		7

typedef struct	s_player
{
	t_animation		*animations;
	int				x;
	int				y;
	int				speed;
	int				n_anim;
	int				anim_stat;
	mlx_image_t		*image;
	int				switch_button;
	t_hitbox		hitbox;
	size_t			steps;
}					t_player;

typedef struct s_textures_files
{
	char	*paths_walk_to_up[5];
	char	*paths_walk_to_down[4];
	char	*paths_walk_to_right[8];
	char	*paths_walk_to_left[8];
	char	*paths_breath_left[6];
	char	*paths_breath_right[6];

}	t_textures_files;

void	init_player(t_game *data);
void	destroy_player(mlx_t *mlx, t_player *player);
void	turbo_shift(t_player *player);
void	move_up(t_player *player, t_map *map);
void	move_down(t_player *player, t_map *map);
void	move_left(t_player *player, t_map *map);
void	move_right(t_player *player, t_map *map);
void	walking_speed(t_player *player);
void	update_player(t_game *game, t_player *player, t_map *map);
int		is_collision_up(t_player *player, t_map *map);
int		is_collision_down(t_player *player, t_map *map);
int		is_collision_left(t_player *player, t_map *map);
int		is_collision_right(t_player *player, t_map *map);
void	breath(t_textures_files *textures);
void	walk(t_textures_files *textures);
void	normal_shift(t_player *player);

/* COORDINATE */
typedef struct s_coordinate
{
	int x;
	int y;
} 
	t_coordinate;

typedef struct s_collectible
{
	int count;
}	t_collectible;


/* PARSER */
typedef struct	s_parser
{
	t_coordinate	player;
	t_coordinate	exit;
	char			**str_map;
	int				total_collectables;
}	t_parser;

void	parser_map(t_parser *parser, char *path_map);
int		check_rectangle_map(char **map);
int		check_closed_map(char **map);
bool	flood_fill(t_parser *parser);


/* BLOCK */
typedef struct	s_block
{
	mlx_image_t		*image;
	int				x;
	int				y;
	int				collision;
	
}					t_block;


/* GAME */
typedef struct game
{
	mlx_t		*mlx;
	t_player	player;
	t_map		map;
}				t_game;

void ft_print_error(char *str);
void	ft_hook_keys(void *data2);
void	key_hook(mlx_key_data_t keydata, void *data2);
char	**read_n_copy_map(char *path_map);
void	update_game(void *game);
void	destroy_all(t_game *data);
void	res_check(t_game  data);

#endif
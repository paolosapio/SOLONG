/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:53:06 by psapio            #+#    #+#             */
/*   Updated: 2024/10/29 13:17:19 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>


# include "MLX42/MLX42.h"
# include "libft.h"

# include "coordinate.h"
# include "player.h"
# include "animation.h"
# include "map.h"
# include "parser.h"


typedef struct game
{
	mlx_t		*mlx;
	t_player	*player;
	t_map		*map;
}				t_game;

void ft_print_error(char *str);

void	ft_hook_keys(void *data2);
void	key_hook(mlx_key_data_t keydata, void *data2);
char	**read_n_copy_map(char *path_map);
void	update_game(void *game);
void	destroy_all(t_game data);
void	res_check(t_game  data);

#endif
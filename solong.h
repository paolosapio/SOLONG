/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:53:06 by psapio            #+#    #+#             */
/*   Updated: 2024/10/24 17:39:43 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdio.h>
# include <fcntl.h>
# include "player.h"
# include "GNL/get_next_line.h"

typedef struct game
{
	mlx_t		*mlx;
	t_player	*player;
	t_map		*map;
}				t_game;

void	ft_hook_keys(void *data2);
void	key_hook(mlx_key_data_t keydata, void *data2);
char	**read_n_copy_map(char *path_map);
void	update_game(void *game);
void	destroy_all(t_game data);
void	res_check(t_game  data);

#endif
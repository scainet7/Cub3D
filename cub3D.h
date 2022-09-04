/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:55:24 by snino             #+#    #+#             */
/*   Updated: 2022/09/04 17:56:52 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define MAG "\033[35m"
# define END "\033[0m"
# define UP 			13
# define DOWN 			1
# define LEFT 			0
# define RIGHT			2

enum e_exit
{
	leave,
	clean,
	mlx,
	map
};

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	*map_name;
} t_game;

void	ft_check_map(t_game *game, int argc, char **argv);
void	ft_free_game(t_game *game);
void	ft_free_map_game(t_game *game);
void	ft_error_handler(t_game *game, char *str, int sweep);
#endif

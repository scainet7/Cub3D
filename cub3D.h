/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:55:24 by snino             #+#    #+#             */
/*   Updated: 2022/09/20 19:46:41 by snino            ###   ########.fr       */
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
	map,
	memory
};

typedef struct s_map
{
	char			**maps_line;
	struct s_map	*next;
}	t_map;

typedef struct s_game
{
	int		type;
	int		color;
	int		enter;
	void	*mlx;
	void	*win;
	char	*map_name;
	char	**map;
	t_list	*type_list;
	t_list	*color_list;
	t_list	*map_list;
	t_map 	*types;
	t_map   *colors;
}	t_game;

void	ft_check_map_mass(t_game *game);
void	ft_pars_map_mass(t_game *game);
void	ft_pars_color_mass(t_game *game);
void	ft_check_color_mass(t_game *game);
void	ft_free_mass(t_map *line);
t_map 	*ft_line_new(void *line);
void	ft_lineadd_back(t_map **mass, t_map *new);
int		ft_memory_num(t_list *list);
void	ft_check_type_mass(t_game *game);
void	ft_pars_map(t_game *game, char *line);
void	ft_pars_map_list(t_game *game, char *line);
void	ft_pars_type_mass(t_game *game);
void	ft_check_map(t_game *game, int argc, char **argv);
void	ft_free_game(t_game *game);
void	ft_free_map_game(t_game *game);
void	ft_error_handler(t_game *game, char *str, int sweep);
void	show(t_list *list, char *str);
void	show1(t_map *maps, char *place);
void	show2(char **maps, char *place);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:55:24 by snino             #+#    #+#             */
/*   Updated: 2022/10/17 16:34:29 by snino            ###   ########.fr       */
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
# define WIDTH			1024
# define HEIGHT			512
# define X_DESTROY		17
# define X_EXPOSE		12
# define FOV			0.66
# define IMG			64
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

typedef struct s_player_position
{
	int 		x;
	int 		y;
	float		p_x;
	float		p_y;
	double		plane_x;
	double		plane_y;
	double		dir_x;
	double		dir_y;
}	t_pp;

typedef struct s_img
{
	int 	floor[3];
	int 	ceiling[3];
	int		line_length;
	int		bits_per_pixel;
	int		endian;
	char	*addr;
	void	*wall_no;
	void	*wall_so;
	void	*wall_we;
	void	*wall_ea;
	void	*wall;
	void	*ptr;
}	t_img;

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
	t_img 	*img;
	t_list	*type_list;
	t_list	*color_list;
	t_list	*map_list;
	t_map	*types;
	t_map	*colors;
	t_pp	*player;
}	t_game;
//init_game
void	ft_init_game(t_game *game);
//init_struckt
void	ft_init_struckt(t_game *game);
//pars
t_map	*ft_line_new(void *line);
int		ft_memory_num(t_list *list);
int		ft_memory_num1(t_list *list);
void	ft_pars_map_mass(t_game *game);
void	ft_pars_type_mass(t_game *game);
void	ft_check_map_mass(t_game *game);
void	ft_pars_color_mass(t_game *game);
void	ft_check_type_mass(t_game *game);
void	ft_check_color_mass(t_game *game);
void	ft_pars_map(t_game *game, char *line);
void	ft_lineadd_back(t_map **mass, t_map *new);
void	ft_pars_map_list(t_game *game, char *line);
void	ft_check_map_mass_angle(t_game *game, int n);
void	ft_check_map(t_game *game, int argc, char **argv);
//draft
int		ft_draw_game(t_game *game);
void	ft_record(t_game *game);
void	ft_player_position(t_game *game);
//close_&_free
int		ft_close_window(t_game *game);
void	ft_free_map(t_game *game);
void	ft_free_mass(t_map *line);
void	ft_free_game(t_game *game);
void	ft_free_map_game(t_game *game);
void	ft_error_handler(t_game *game, char *str, int sweep);
//show
void	show(t_list *list, char *str);
void	show1(t_map *maps, char *place);
void	show2(char **maps, char *place);
void	show_struct_img(t_img *img);
void	show_struct_pp(t_pp *player);
void	show_struct_game(t_game *game);

#endif

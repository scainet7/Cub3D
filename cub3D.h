/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:55:24 by snino             #+#    #+#             */
/*   Updated: 2022/10/18 20:14:09 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "minilibxo/mlx.h"
# include "libft/libft.h"

# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define MAG "\033[35m"
# define END "\033[0m"
# define WIDTH			1024
# define HEIGHT			512
# define SPEED			0.03
# define ROTATE_SPEED	-0.03
# define FOV			0.66
# define IMG			64
# define WALL_DISTANCE 	0.3
# define CORNER			0.25

# define MOVE_LEFT 		0
# define MOVE_RIGHT 	2
# define MOVE_DOWN 		1
# define MOVE_UP 		13
# define ROTATE_LEFT 	123
# define ROTATE_RIGHT 	124
# define ESCAPE 		53

enum e_exit
{
	leave,
	clean,
	mlx,
	map,
	memory
};

enum e_tex
{
	north = 0,
	east = 1,
	west = 2,
	south = 3,
};

typedef struct s_controls
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	rotate_left;
	int	rotate_right;
	int	escape;
}	t_controls;

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

typedef struct s_wall
{

	int		bottom;
	int		top;
	int		x;
	double	step;
	double	position;
	int		direction;
	char	type;
	int		vertical;
	int		horizontal;
}	t_wall;

typedef struct s_raycast
{
	float	camera;
	double	dir_x;
	double	dir_y;
	double	delta_x;
	double	delta_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	perp_wall_dist;
}	t_ray;

typedef struct s_img
{
	int		endian;
	int 	floor[3];
	int 	ceiling[3];
	int		line_length;
	int		bits_per_pixel;
	int		east_wall[IMG][IMG];
	int		west_wall[IMG][IMG];
	int		north_wall[IMG][IMG];
	int		south_wall[IMG][IMG];
	char	*addr;
	char	*mlx_addr;
	void	*ptr;
	void	*wall;
	void	*wall_no;
	void	*wall_so;
	void	*wall_we;
	void	*wall_ea;
	void	*shotgun;
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
	t_pp	*player;
	t_img 	*img;
	t_ray	*ray;
	t_map	*types;
	t_map	*colors;
	t_wall	*wall;
	t_list	*type_list;
	t_list	*color_list;
	t_list	*map_list;
	t_controls	controls;
}	t_game;


int	exit_game(t_game *game, int exit_state);
//control

int	wall_left_x(t_game *game, double len);
int	wall_left_y(t_game *game, double len);
int	wall_right_x(t_game *game, double len);
int	wall_right_y(t_game *game, double len);
int	wall_behind_x(t_game *game, double len);
int	wall_behind_y(t_game *game, double len);
int	wall_in_front_x(t_game *game, double len);
int	wall_in_front_y(t_game *game, double len);
void	redrawing(t_game *game, int keycode);
void	check_events(t_game *game);
int	key_press(int keycode, t_game *game);
int	key_release(int key, t_game *game);
//raycast
double 	ft_get_perp_wall_dist(t_game *game);
void	ft_raycast(t_game *game, int x);
void	ft_searching_wall(t_game *game);
void	ft_draw_walls(t_game *game, int x);
//void	ft_set_direction(t_game *game);
//textures
int		create_rgb(int r, int g, int b);
int		my_mlx_pixel_get(t_img *img, int x, int y);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	ft_get_wall_pixels(t_img *img, int type);
//init_game
void	ft_init_game(t_game *game);
//init_struckt
void	ft_init_struckt(t_game *game);
//pars
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
t_map	*ft_line_new(void *line);
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
void	show_struct_wall(t_wall *wall);

#endif

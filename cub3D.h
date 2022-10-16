/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:55:24 by snino             #+#    #+#             */
/*   Updated: 2022/10/15 20:46:12 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"

# define END "\033[0m"
# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define MAG "\033[35m"
# define WIDTH			900
# define HEIGHT			700
# define ROTSPEED  0.5
# define MOVESPEED 0.11
# define X_EXPOSE		12
# define X_DESTROY		17
# define FOV			0.66
# define IMG			64
#  define UP		126
#  define DOWN	    125
#  define LEFT	    123
#  define RIGHT	    124
#  define W_UP		13
#  define S_DOWN 	1
#  define A_LEFT 	0
#  define D_RIGHT	2
#  define ESC		53

enum e_exit
{
	mlx,
	map,
	leave,
	clean,
	memory
};

typedef struct s_player_position
{
	int 			x;
	int 			y;
	float			p_x;
	float 			p_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			rot_speed;
	double			move_speed;
}	t_pp;

typedef struct s_img
{
	int				endian;
	int 			floor[3];
	int 			ceiling[3];
	int				line_length;
	int				bits_per_pixel;
	char			*addr;
	char			*tex_no;
	char			*tex_so;
	char			*tex_we;
	char			*tex_ea;
	void			*wall_no;
	void			*wall_so;
	void			*wall_we;
	void			*wall_ea;
	void			*wall;
	void			*ptr;
}	t_img;

typedef struct s_raycast
{
	int				hit;
	int				side;
	int 			map_x;
	int 			map_y;
	int				tex_x;
	int				tex_y;
	int				step_x;
	int				step_y;
	int				draw_end;
	int				draw_start;
	int				line_height;
	double			wall;
	double			step;
	double			camera;
	double			tex_pos;
	double			s_dist_x;
	double			s_dist_y;
	double			ray_dir_x;
	double			ray_dir_y;
	double			delt_dist_x;
	double			delt_dist_y;
	double			perp_wall_dist;
	unsigned int	color;
}	t_ray;

typedef struct s_map
{
	char			**maps_line;
	struct s_map	*next;
}	t_map;

typedef struct s_window
{
	int				x;
	int				y;
	int				end;
	int				bpp;
	int				l_len;
	char			*addr;
	void			*mlx;
	void			*img;
	void			*win;
}	t_win;

typedef struct s_game
{
<<<<<<< HEAD
	int				type;
	int 			width;
	int				color;
	int				enter;
	int 			height;
	char			**map;
	char			*map_name;
	t_pp			*player;
	t_img 			img;
	t_win			*win;
	t_win			*s_tex;
	t_win			*n_tex;
	t_win			*w_tex;
	t_win			*e_tex;
	t_ray			*raycast;
	t_list			*map_list;
	t_list			*type_list;
	t_list			*color_list;
	t_map			*types;
	t_map			*colors;

=======
	int		type;
	int		color;
	int		enter;
	void	*mlx;
	void	*win;
	char	*map_name;
	char	**map;
	t_img 	img;
	t_list	*type_list;
	t_list	*color_list;
	t_list	*map_list;
	t_map	*types;
	t_map	*colors;
	t_pp	*player;
>>>>>>> parent of 3f6eeec (V1.0 fixed init textur)
}	t_game;

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
//draw
void	ft_record(t_game *game);
void	ft_raycast(t_game *game);
void	ft_init_game(t_game *game);
void	ft_player_position(t_game *game);
void	ft_draw_game(t_game *game, int x);
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
//utils
void	init_data_for_textures_and_speed(t_game *game);
int		add_shade(double distance, int color);
int		create_rgb(int r, int g, int b);
//mlx_utils
void	img_to_xpm_data_my(t_win *win, char *path, t_win *data);
unsigned int	get_tex_color_pixel(t_win *img, int x, int y);
void			my_mlx_pixel_put(t_win *win, int x, int y, int color);
//hook
void	move_player_right_left(t_game *game, int key_code, double move_speed);
void	rotate_player_view(t_game *game, double rot_speed);
void	move_player_up_down(t_game *game, int key_code, double move_speed);
int	close_win(t_game *game);
int	key_hook(int key_code, t_game *game);
#endif

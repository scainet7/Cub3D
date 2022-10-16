/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:54:57 by snino             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/15 21:22:51 by snino            ###   ########.fr       */
=======
/*   Updated: 2022/09/25 20:50:28 by snino            ###   ########.fr       */
>>>>>>> parent of 3f6eeec (V1.0 fixed init textur)
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_data_for_textures_and_speed(t_game *game)
{
<<<<<<< HEAD
	game->s_tex = malloc(sizeof(t_win));
	game->w_tex = malloc(sizeof(t_win));
	game->e_tex = malloc(sizeof(t_win));
	game->n_tex = malloc(sizeof(t_win));
	img_to_xpm_data_my(game->win, game->img.tex_no, game->s_tex);
	img_to_xpm_data_my(game->win, game->img.tex_so, game->n_tex);
	img_to_xpm_data_my(game->win, game->img.tex_we, game->e_tex);
	img_to_xpm_data_my(game->win, game->img.tex_ea, game->w_tex);
	game->player->move_speed = MOVESPEED;
	game->player->rot_speed = ROTSPEED;
=======
	int x;
	int y;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH,
							  HEIGHT, "cub3D");
	if (game->win == NULL)
		ft_error_handler(game, "Error\nINVALID_WINDOW", clean);
	game->img.ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->img.ptr == NULL)
		ft_error_handler(game, "Error\nFailure of creating image pointer\n", clean);
	game->img.addr = mlx_get_data_addr(game->img.ptr, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	if (game->img.addr == NULL)
		ft_error_handler(game, "Error\nFailure of creating image address\n", clean);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &x, &y);
	mlx_put_image_to_window(game->mlx, game->win, game->img.wall,(IMG * 4), (IMG * 4));
	mlx_hook(game->win, X_DESTROY, (0L), &ft_close_window, &game);
	mlx_loop(game->mlx);
//	mlx_loop_hook(game->mlx, ft_draw_game, &game);
>>>>>>> parent of 3f6eeec (V1.0 fixed init textur)
}

void ft_free_map(t_game *game)
{
	ft_freelst(game->type_list);
	ft_freelst(game->color_list);
	ft_freelst(game->map_list);
	ft_free_mass(game->types);
	ft_free_mass(game->colors);
	free(game->map);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_pp	*player;
	t_win 	*win;

	player = malloc(sizeof(t_pp));
	win = malloc(sizeof(t_win));
	game.win = win;
	game.player = player;
	ft_check_map(&game, argc, argv);
	ft_record(&game);
//	ft_player_position(&game);
	ft_init_game(&game);
//	mlx_put_image_to_window(game.mlx, game.win, game.wall.ptr,
//							(IMG * 4), (IMG * 4));
//	mlx_loop(game.mlx);
//	mlx_hook(game.win, X_EXPOSE, (1L << 15), &ft_move_window, &game);
//	show(game.type_list, "type_list");
//	show(game.color_list, "color_list");
//	show(game.map_list, "map_list");
//	show1(game.types, "TUPE");
//	show1(game.colors, "COLOR");
//	show2(game.map, "MAP");
//	mlx_destroy_image(game.mlx, game.img.ptr);
	return (0);
}

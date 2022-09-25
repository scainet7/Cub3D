/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:54:57 by snino             #+#    #+#             */
/*   Updated: 2022/09/25 20:50:28 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//int	ft_draw_game(t_game *game)
//{
//
//}

void	ft_init_game(t_game *game)
{
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

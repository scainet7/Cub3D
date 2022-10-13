/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:52:22 by snino             #+#    #+#             */
/*   Updated: 2022/10/13 19:55:08 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_game(t_game *game)
{
	game->win.mlx = mlx_init();
	game->win.win = mlx_new_window(game->win.mlx, WIDTH,
							   HEIGHT, "cub3D");
	if (game->win.win == NULL)
		ft_error_handler(game, "Error\nINVALID_WINDOW", clean);
	ft_record(game);
	ft_player_position(game);
	game->img.ptr = mlx_new_image(game->win.mlx, WIDTH, HEIGHT);
	if (game->img.ptr == NULL)
		ft_error_handler(game, "Error\nFailure of creating image pointer\n", clean);
	game->img.addr = mlx_get_data_addr(game->img.ptr, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	ft_raycast(game);
	mlx_hook(game->win.win, X_DESTROY, (0L), &ft_close_window, &game);
	mlx_loop(game->win.mlx);
//	mlx_loop_hook(game->mlx, ft_draw_game, &game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:52:22 by snino             #+#    #+#             */
/*   Updated: 2022/10/15 21:20:05 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_game(t_game *game)
{
	t_ray			*raycast;

	raycast = malloc(sizeof(t_ray));
	game->raycast = raycast;
	game->win->mlx = mlx_init();
	init_data_for_textures_and_speed(game);
	game->win->win = mlx_new_window(game->win->mlx, WIDTH,
							   HEIGHT, "cub3D");
	if (game->win->win == NULL)
		ft_error_handler(game, "Error\nINVALID_WINDOW", clean);
	ft_record(game);
	ft_player_position(game);
	game->win->img = mlx_new_image(game->win->mlx, WIDTH, HEIGHT);
	if (game->win->img == NULL)
		ft_error_handler(game, "Error\nFailure of creating image pointer\n", clean);
	game->win->addr = mlx_get_data_addr(game->win->img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	ft_raycast(game);
	mlx_put_image_to_window(game->win->mlx, game->win->win, game->win->img, 0, 0);
	mlx_do_key_autorepeaton(game->win->mlx);
	mlx_hook(game->win->win, 2, 0x1, key_hook, game);
	mlx_hook(game->win->win, 33, (1L << 17), close_win, game);
	mlx_loop(game->win->mlx);
}

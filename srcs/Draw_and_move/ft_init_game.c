/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:06:47 by snino             #+#    #+#             */
/*   Updated: 2022/10/23 17:32:00 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	ft_init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_exit_game(game, "Error\nMLX_INIT", EXIT_FAILURE);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (game->win == NULL)
		ft_exit_game(game, "Error\nWIN_INIT", EXIT_FAILURE);
	game->img->ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->img->ptr == NULL)
		ft_exit_game(game, "Error\nMLX_IMAGE", EXIT_FAILURE);
	ft_record(game);
	game->img->mlx_addr = mlx_get_data_addr(game->img->ptr,
			&game->img->bits_per_pixel, &game->img->line_length,
			&game->img->endian);
	if (game->img->mlx_addr == NULL)
		ft_exit_game(game, "Error\nMLX_ADDR", EXIT_FAILURE);
}

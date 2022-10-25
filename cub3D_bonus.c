/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:41:09 by snino             #+#    #+#             */
/*   Updated: 2022/10/23 19:28:28 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.flag = 1;
	ft_check_map(&game, argc, argv);
	ft_init_struckt(&game);
	ft_player_position(&game);
	ft_init_game(&game);
	mlx_loop_hook(game.mlx, ft_draw_game, &game);
	mlx_hook(game.win, 6, 1L << 0, mouse_hook, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 0, key_release, &game);
	mlx_hook(game.win, 17, 1L << 17, ft_exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}

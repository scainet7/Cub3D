/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:54:57 by snino             #+#    #+#             */
/*   Updated: 2022/10/18 20:15:18 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	exit_game(t_game *game, int exit_state)
{
	mlx_destroy_image(game->mlx, game->img->ptr);
	mlx_destroy_window(game->mlx, game->win);
	ft_free_map(game);
	if (exit_state == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void ft_free_map(t_game *game)
{
	free(game->player);
	free(game->img);
	free(game->ray);
	free(game->wall);
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
	ft_init_struckt(&game);
	ft_player_position(&game);
	ft_init_game(&game);
	mlx_loop_hook(game.mlx, ft_draw_game, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 0, key_release, &game);
	mlx_hook(game.win, 17, 1L << 17, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}

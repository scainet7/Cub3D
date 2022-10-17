/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:06:47 by snino             #+#    #+#             */
/*   Updated: 2022/10/17 17:36:37 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_error_handler(game, "Error\nMALLOC_STRUCKT_PLAYER_POSITION", leave);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "CUB3D");
	if (game->win == NULL)
		ft_error_handler(game, "Error\nMALLOC_STRUCKT_PLAYER_POSITION", leave);
//	game->img->ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
//	if (game->img->ptr == NULL)
//		ft_error_handler(game, "Error\nMALLOC_STRUCKT_PLAYER_POSITION", leave);
	ft_record(game);;
}


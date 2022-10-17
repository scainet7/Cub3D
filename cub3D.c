/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:54:57 by snino             #+#    #+#             */
/*   Updated: 2022/10/17 21:12:10 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ft_free_map(t_game *game)
{
	free(game->player);
	free(game->img);
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
//	mlx_loop(game.mlx);
//	show(game.color_list, "color_list");
//	show(game.map_list, "map_list");
//	show1(game.types, "TUPE");
//	show1(game.colors, "COLOR");
//	show2(game.map, "MAP");
	show_struct_game(&game);
	show_struct_pp(game.player);
	show_struct_img(game.img);
	ft_free_game(&game);
	ft_free_map(&game);
	return (0);
}

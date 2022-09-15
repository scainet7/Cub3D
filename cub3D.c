/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:54:57 by snino             #+#    #+#             */
/*   Updated: 2022/09/15 19:34:02 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_check_map(&game, argc, argv);
	show(game.type_list, "type_list");
	show(game.color_list, "color_list");
	show(game.map_list, "map_list");
	show1(game.types, "TUPE");
	ft_freelst(game.type_list);
	ft_freelst(game.color_list);
	ft_freelst(game.map_list);
	ft_free_mass(game.types);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:07:23 by snino             #+#    #+#             */
/*   Updated: 2022/10/29 14:43:54 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	ft_init_struckt(t_game *game)
{
	t_pp	*player;
	t_img	*img;
	t_ray	*ray;
	t_wall	*wall;

	ft_memset(&(game->controls), -1, sizeof(t_controls));
	player = malloc(sizeof(t_pp));
	if (!player)
		ft_exit_game(game,
			"Error\nMALLOC_STRUCKT_PLAYER_POSITION", EXIT_FAILURE);
	game->player = player;
	img = malloc(sizeof(t_img));
	if (!img)
		ft_exit_game(game, "Error\nMALLOC_STRUCKT_IMG", EXIT_FAILURE);
	game->img = img;
	ray = malloc(sizeof(t_ray));
	if (!ray)
		ft_exit_game(game, "Error\nMALLOC_STRUCKT_RAYCAST", EXIT_FAILURE);
	game->ray = ray;
	wall = malloc(sizeof(t_wall));
	if (!wall)
		ft_exit_game(game, "Error\nMALLOC_STRUCKT_WALL", EXIT_FAILURE);
	game->wall = wall;
}

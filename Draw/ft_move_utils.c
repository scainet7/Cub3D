/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:44:15 by snino             #+#    #+#             */
/*   Updated: 2022/10/18 19:59:26 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	wall_in_front_x(t_game *game, double len)
{
	int			x;
	int			y;

	if (game->player->dir_x > 0)
		y = (int)((game->player->p_x + (game->player->dir_x) / len * SPEED) + WALL_DISTANCE);
	else
		y = (int)((game->player->p_x + (game->player->dir_x) / len * SPEED) - WALL_DISTANCE);
	x = (int)(game->player->p_y);
	if (game->map[y][x] == '0')
		return (false);
	return (true);
}

int	wall_behind_x(t_game *game, double len)
{
	int		x;
	int		y;

	if (game->player->dir_x > 0)
		y = (int)((game->player->p_x - (game->player->dir_x) / len * SPEED) - WALL_DISTANCE);
	else
		y = (int)((game->player->p_x - (game->player->dir_x) / len * SPEED) + WALL_DISTANCE);
	x = (int)(game->player->p_y);
	if (game->map[y][x] == '0')
		return (false);
	return (true);
}

int	wall_left_x(t_game *game, double len)
{
	int		x;
	int		y;

	if (game->player->dir_y > 0)
		y = (int)(game->player->p_x - WALL_DISTANCE);
	else
		y = (int)(game->player->p_x + WALL_DISTANCE);
	x = (int)(game->player->p_y - (game->player->dir_y) / len * SPEED);
	if (game->map[y][x] == '0')
		return (false);
	return (true);
}

int	wall_right_x(t_game *game, double len)
{
	int		x;
	int		y;

	if (game->player->dir_y > 0)
		y = (int)(game->player->p_x + WALL_DISTANCE);
	else
		y = (int)(game->player->p_x - WALL_DISTANCE);
	x = (int)(game->player->p_y - (game->player->dir_y) / len * SPEED);
	if (game->map[y][x] == '0')
		return (false);
	return (true);
}


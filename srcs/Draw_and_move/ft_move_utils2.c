/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:51:06 by snino             #+#    #+#             */
/*   Updated: 2022/10/23 12:13:40 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	wall_in_front_y(t_game *game, double len)
{
	int			x;
	int			y;
	static int	timeout;

	if (game->player->dir_y > 0)
		y = (int)((game->player->p_y + (game->player->dir_y)
					/ len * SPEED) + WALL_DISTANCE);
	else
		y = (int)((game->player->p_y + (game->player->dir_y)
					/ len * SPEED) - WALL_DISTANCE);
	x = (int)(game->player->p_x);
	if (open_horizone_door(game) == EXIT_SUCCESS && ++timeout < 5)
	{
		close_horizone_door(game);
		return (true);
	}
	timeout = 0;
	if (game->map[x][y] == '0')
		return (false);
	return (true);
}

int	wall_behind_y(t_game *game, double len)
{
	int		x;
	int		y;

	if (game->player->dir_y > 0)
		y = (int)((game->player->p_y - (game->player->dir_y)
					/ len * SPEED) - WALL_DISTANCE);
	else
		y = (int)((game->player->p_y - (game->player->dir_y)
					/ len * SPEED) + WALL_DISTANCE);
	x = (int)(game->player->p_x);
	if (game->map[x][y] == '0')
		return (false);
	return (true);
}

int	wall_left_y(t_game *game, double len)
{
	int		x;
	int		y;

	if (game->player->dir_x > 0)
		y = (int)(game->player->p_y + WALL_DISTANCE);
	else
		y = (int)(game->player->p_y - WALL_DISTANCE);
	x = (int)(game->player->p_x + (game->player->dir_x) / len * SPEED);
	if (game->map[x][y] == '0')
		return (false);
	return (true);
}

int	wall_right_y(t_game *game, double len)
{
	int		x;
	int		y;

	if (game->player->dir_x > 0)
		y = (int)(game->player->p_y - WALL_DISTANCE);
	else
		y = (int)(game->player->p_y + WALL_DISTANCE);
	x = (int)(game->player->p_x + (game->player->dir_x) / len * SPEED);
	if (game->map[x][y] == '0')
		return (false);
	return (true);
}

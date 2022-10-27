/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_door.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:37:21 by snino             #+#    #+#             */
/*   Updated: 2022/10/27 13:13:07 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	close_vert_door(t_game *game)
{
	int	x;

	x = game->door->open_vert[0];
	if (x == -1)
		return (EXIT_SUCCESS);
	else
	{
		if (game->player->p_x <= (double)x - 0.3 || game->player->p_x >= (double)x + 1.3)
		{
			game->map[game->door->open_vert[0]][game->door->open_vert[1]] \
			= '2';
			game->door->open_vert[0] = -1;
			game->door->open_vert[1] = -1;
		}
	}
	return (EXIT_FAILURE);
}

int	open_vert_door(t_game *game)
{
	int	x;
	int	y;

	if (close_vert_door(game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (game->player->dir_x > 0)
		y = (int)((game->player->p_x + game->player->dir_x * SPEED) + WALL_DISTANCE);
	else
		y = (int)((game->player->p_x + game->player->dir_x * SPEED) - WALL_DISTANCE);
	x = (int)(game->player->p_y);
	if (game->map[y][x] == '2')
	{
		game->door->open_vert[0] = y;
		game->door->open_vert[1] = x;
		game->map[y][x] = '0';
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	close_horizone_door(t_game *game)
{
	int	y;

	y = game->door->open_hor[1];
	if (y == -1)
		return (EXIT_SUCCESS);
	else
	{
		if (game->player->p_y <= (double)y - 0.3 || game->player->p_y >= (double)y + 1.3)
		{
			game->map[game->door->open_hor[0]][game->door->open_hor[1]]
					= '2';
			game->door->open_hor[0] = -1;
			game->door->open_hor[1] = -1;
		}
	}
	return (EXIT_FAILURE);
}

int	open_horizone_door(t_game *game)
{
	int	x;
	int	y;

	if (close_horizone_door(game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (game->player->dir_y > 0)
		y = (int)((game->player->p_y + game->player->dir_y * SPEED) + WALL_DISTANCE);
	else
		y = (int)((game->player->p_y + game->player->dir_y * SPEED) - WALL_DISTANCE);
	x = (int)(game->player->p_x);
	if (game->map[x][y] == '2')
	{
		game->door->open_hor[0] = x;
		game->door->open_hor[1] = y;
		game->map[x][y] = '0';
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
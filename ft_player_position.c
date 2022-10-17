/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:04:22 by snino             #+#    #+#             */
/*   Updated: 2022/10/17 16:04:20 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_north(t_game *game, int x, int y)
{
	game->player->x = x;
	game->player->y = y;
	game->player->p_x = x + 0.5;
	game->player->p_y = y + 0.5;
	game->player->plane_x = 0;
	game->player->plane_y = FOV;
	game->player->dir_x = -1;
	game->player->dir_y = 0;
}

static void	ft_south(t_game *game, int x, int y)
{
	game->player->x = x;
	game->player->y = y;
	game->player->p_x = x + 0.5;
	game->player->p_y = y + 0.5;
	game->player->plane_x = 0;
	game->player->plane_y = -FOV;
	game->player->dir_x = 1;
	game->player->dir_y = 0;
}

static void	ft_west(t_game *game, int x, int y)
{
	game->player->x = x;
	game->player->y = y;
	game->player->p_x = x + 0.5;
	game->player->p_y = y + 0.5;
	game->player->plane_x = -FOV;
	game->player->plane_y = 0;
	game->player->dir_x = 0;
	game->player->dir_y = -1;
}

static void	ft_east(t_game *game, int x, int y)
{
	game->player->x = x;
	game->player->y = y;
	game->player->p_x = x + 0.5;
	game->player->p_y = y + 0.5;
	game->player->plane_x = FOV;
	game->player->plane_y = 0;
	game->player->dir_x = 0;
	game->player->dir_y = 1;
}

void	ft_player_position(t_game *game)
{
	int		x;
	int 	y;
	char	**tmp_map;

	x = 0;
	tmp_map = game->map;
	while(tmp_map[++x])
	{
		y = 0;
		while(tmp_map[x][++y])
		{
			if (tmp_map[x][y] == 'N' || tmp_map[x][y] == 'S' || \
				tmp_map[x][y] == 'W' || tmp_map[x][y] == 'E')
			{
				if (tmp_map[x][y] == 'N')
					ft_north(game, x, y);
				if (tmp_map[x][y] == 'S')
					ft_south(game, x, y);
				if (tmp_map[x][y] == 'W')
					ft_west(game, x, y);
				if (tmp_map[x][y] == 'E')
					ft_east(game, x, y);
			}
		}
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:21:36 by snino             #+#    #+#             */
/*   Updated: 2022/10/18 15:57:57 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void ft_set_direction(t_game *game)
{
	if (game->ray->dir_x < 0)
	{
		game->ray->step_x = -1;
		game->ray->side_dist_x = (game->player->p_x - (int)game->player->p_x) * game->ray->delta_x;
		game->wall->vertical = north;
	}
	else
	{
		game->ray->step_x = 1;
		game->ray->side_dist_x = ((int)game->player->p_x + 1.0 - game->player->p_x) * game->ray->delta_x;
		game->wall->vertical = south;
	}
	if (game->ray->dir_y < 0)
	{
		game->ray->step_y = -1;
		game->ray->side_dist_y = (game->player->p_y - (int)game->player->p_y) * game->ray->delta_y;
		game->wall->horizontal = west;
	}
	else
	{
		game->ray->step_y = 1;
		game->ray->side_dist_y = ((int)game->player->p_y + 1.0 - game->player->p_y) * game->ray->delta_y;
		game->wall->horizontal = east;
	}
}

void	ft_raycast(t_game *game, int x)
{
	game->ray->camera = 2 * x / (double)WIDTH - 1;
	game->ray->dir_x = game->player->dir_x + game->player->plane_x * game->ray->camera;
	game->ray->dir_y = game->player->dir_y + game->player->plane_y * game->ray->camera;
	if (game->ray->dir_x == 0)
		game->ray->delta_x = 1e30;
	else
		game->ray->delta_x = fabs(1 / game->ray->dir_x);
	if (game->ray->dir_y == 0)
		game->ray->delta_y = 1e30;
	else
		game->ray->delta_y = fabs(1 / game->ray->dir_y);
	ft_set_direction(game);
	ft_searching_wall(game);
	game->ray->perp_wall_dist = ft_get_perp_wall_dist(game);
}
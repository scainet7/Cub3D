/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:21:36 by snino             #+#    #+#             */
/*   Updated: 2022/10/29 14:43:54 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

double	ft_get_perp_wall_dist(t_game *game)
{
	t_ray	*ray;
	double	perp_wall_dist;

	ray = game->ray;
	if (ray->side == 0)
	{
		game->wall->direction = game->wall->vertical;
		perp_wall_dist = ray->side_dist_x - ray->delta_x;
	}
	else
	{
		game->wall->direction = game->wall->horizontal;
		perp_wall_dist = ray->side_dist_y - ray->delta_y;
	}
	if (perp_wall_dist == 0)
		perp_wall_dist += 0.01;
	return (perp_wall_dist);
}

static void	ft_dda(t_game *game)
{
	int	wall;
	int	map_x;
	int	map_y;

	map_x = (int)game->player->p_x;
	map_y = (int)game->player->p_y;
	wall = false;
	while (wall == false)
	{
		if (game->ray->side_dist_x < game->ray->side_dist_y)
		{
			game->ray->side_dist_x += game->ray->delta_x;
			map_x += game->ray->step_x;
			game->ray->side = 0;
		}
		else
		{
			game->ray->side_dist_y += game->ray->delta_y;
			map_y += game->ray->step_y;
			game->ray->side = 1;
		}
		if (game->map[map_x][map_y] != '0')
			wall = true;
	}
}

static void	ft_side_dist_y(t_game *game)
{
	if (game->ray->dir_y < 0)
	{
		game->ray->step_y = -1;
		game->ray->side_dist_y = (game->player->p_y
				- (int)game->player->p_y) * game->ray->delta_y;
		game->wall->horizontal = west;
	}
	else
	{
		game->ray->step_y = 1;
		game->ray->side_dist_y = ((int)game->player->p_y + 1.0
				- game->player->p_y) * game->ray->delta_y;
		game->wall->horizontal = east;
	}
}

static void	ft_side_dist_x(t_game *game)
{
	if (game->ray->dir_x < 0)
	{
		game->ray->step_x = -1;
		game->ray->side_dist_x = (game->player->p_x
				- (int)game->player->p_x) * game->ray->delta_x;
		game->wall->vertical = north;
	}
	else
	{
		game->ray->step_x = 1;
		game->ray->side_dist_x = ((int)game->player->p_x + 1.0
				- game->player->p_x) * game->ray->delta_x;
		game->wall->vertical = south;
	}
}

void	ft_raycast(t_game *game, int x)
{
	game->ray->camera = 2 * x / (double)WIDTH - 1;
	game->ray->dir_x = game->player->dir_x + game->player->plane_x
		* game->ray->camera;
	game->ray->dir_y = game->player->dir_y + game->player->plane_y
		* game->ray->camera;
	if (game->ray->dir_x == 0)
		game->ray->delta_x = 1e30;
	else
		game->ray->delta_x = fabs(1 / game->ray->dir_x);
	if (game->ray->dir_y == 0)
		game->ray->delta_y = 1e30;
	else
		game->ray->delta_y = fabs(1 / game->ray->dir_y);
	ft_side_dist_x(game);
	ft_side_dist_y(game);
	ft_dda(game);
	game->ray->perp_wall_dist = ft_get_perp_wall_dist(game);
}

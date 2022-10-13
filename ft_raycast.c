/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:48:32 by snino             #+#    #+#             */
/*   Updated: 2022/10/15 19:41:30 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void ft_dda_continuation(t_game *game)
{
	if (game->raycast->side == 0)
		game->raycast->perp_wall_dist = game->raycast->s_dist_x - game->raycast->delt_dist_x;
	else
		game->raycast->perp_wall_dist = game->raycast->s_dist_y - game->raycast->delt_dist_y;
	game->raycast->line_height = (int)(HEIGHT / game->raycast->perp_wall_dist);
	game->raycast->draw_start = -game->raycast->line_height / 2 + HEIGHT / 2;
	if (game->raycast->draw_start < 0)
		game->raycast->draw_start = 0;
	game->raycast->draw_end = game->raycast->line_height / 2 + HEIGHT / 2;
	if (game->raycast->draw_end >= HEIGHT)
		game->raycast->draw_end = HEIGHT - 1;
}

static void ft_dda(t_game *game)
{
	while (game->raycast->hit == 0)
	{
		if (game->raycast->s_dist_x < game->raycast->s_dist_y)
		{
			game->raycast->s_dist_x += game->raycast->delt_dist_x;
			game->raycast->map_x += game->raycast->step_x;
			game->raycast->side = 0;
		}
		else
		{
			game->raycast->s_dist_y += game->raycast->delt_dist_y;
			game->raycast->map_y += game->raycast->step_y;
			game->raycast->side = 1;
		}
		if (game->map[game->raycast->map_x][game->raycast->map_y] == '1')
			game->raycast->hit = 1;
		ft_dda_continuation(game);
	}
}

static void ft_raycast_continuation(t_game *game)
{
	t_ray	*ray;

	ray = game->raycast;

	ray->hit = 0;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->s_dist_x = (game->player->p_x - ray->map_x) * ray->delt_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->s_dist_x = (ray->map_x + 1.0 - game->player->p_x) * ray->delt_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->s_dist_y = (game->player->p_y - ray->map_y) * ray->delt_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->s_dist_y = (ray->map_y + 1.0 - game->player->p_y) * ray->delt_dist_y;
	}
	game->raycast = ray;
}

void ft_raycast(t_game *game)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		game->raycast->camera = 2 * x / (double)WIDTH - 1;
		game->raycast->ray_dir_x = game->player->dir_x + game->player->plane_x * game->raycast->camera;
		game->raycast->ray_dir_y = game->player->dir_y + game->player->plane_y * game->raycast->camera;
		game->raycast->map_x = (int)game->player->p_x;
		game->raycast->map_y = (int)game->player->p_y;
		if (game->raycast->ray_dir_x == 0)
			game->raycast->delt_dist_x = 1e30;
		else
			game->raycast->delt_dist_x = fabs(1 / game->raycast->ray_dir_x);
		if (game->raycast->ray_dir_y == 0)
			game->raycast->delt_dist_y = 1e30;
		else
			game->raycast->delt_dist_y = fabs(1 / game->raycast->ray_dir_y);
		ft_raycast_continuation(game);
		ft_dda(game);
		ft_draw_game(game, x);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:36:53 by snino             #+#    #+#             */
/*   Updated: 2022/10/23 10:41:00 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

double 	ft_get_perp_wall_dist(t_game *game)
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

void	ft_searching_wall(t_game *game)
{
	int	wall;
	int	x;
	int	y;

	x = (int)game->player->p_x;
	y = (int)game->player->p_y;
	wall = false;
	while (wall == false)
	{
		if (game->ray->side_dist_x < game->ray->side_dist_y)
		{
			game->ray->side_dist_x += game->ray->delta_x;
			x += game->ray->step_x;
			game->ray->side = 0;
		}
		else
		{
			game->ray->side_dist_y += game->ray->delta_y;
			y += game->ray->step_y;
			game->ray->side = 1;
		}
		if (game->map[x][y] != '0')
			wall = true;
	}
}

static 	int ft_get_pixel(t_wall *wall, t_img *img, int y)
{
	int	pixel;

	if (wall->direction == east)
		pixel = img->east_wall[wall->x][y];
	else if (wall->direction == north)
		pixel = img->north_wall[wall->x][y];
	else if (wall->direction == west)
		pixel = img->west_wall[wall->x][y];
	else
		pixel = img->south_wall[wall->x][y];
	return (pixel);
}

static void	ft_get_wall(t_game *game)
{
	int		line_height;
	double	wall_x;


	line_height = (int)(HEIGHT / game->ray->perp_wall_dist);
	game->wall->top = -line_height / 2 + HEIGHT / 2;
	if (game->wall->top < 0)
		game->wall->top = 0;
	game->wall->bottom = line_height / 2 + HEIGHT / 2;
	if (game->wall->bottom >= HEIGHT)
		game->wall->bottom = HEIGHT - 1;
	if (game->ray->side == 0)
		wall_x = game->player->p_y + game->ray->perp_wall_dist * game->ray->dir_y;
	else
		wall_x = game->player->p_x + game->ray->perp_wall_dist * game->ray->dir_x;
	wall_x -= floor((wall_x));
	game->wall->x = (int)(wall_x * (double)(IMG));
	if ((game->ray->side == 0 && game->ray->dir_x > 0)
		|| (game->ray->side == 1 && game->ray->dir_y < 0))
		game->wall->x = IMG - game->wall->x - 1;
	game->wall->step = 1.0 * IMG / line_height;
	game->wall->position
			= (game->wall->top - 0 - HEIGHT / 2 + line_height / 2) * game->wall->step;
}

void	ft_draw_walls(t_game *game, int x)
{
	int	wall_y;
	int	pixel;
	int	y;

	ft_get_wall(game);
	y = game->wall->top;
	while (y < game->wall->bottom)
	{
		wall_y = (int)game->wall->position & (IMG - 1);
		game->wall->position += game->wall->step;
		pixel = ft_get_pixel(game->wall, game->img, wall_y);
		my_mlx_pixel_put(game->img, x, y, pixel);
		y++;
	}
}
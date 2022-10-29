/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:36:53 by snino             #+#    #+#             */
/*   Updated: 2022/10/29 14:43:54 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static int	ft_get_pixel(t_wall *wall, t_img *img, int y)
{
	int	pixel;

	if (wall->direction == east)
		pixel = img->east_wall[wall->tex_x][y];
	else if (wall->direction == north)
		pixel = img->north_wall[wall->tex_x][y];
	else if (wall->direction == west)
		pixel = img->west_wall[wall->tex_x][y];
	else
		pixel = img->south_wall[wall->tex_x][y];
	return (pixel);
}

static void	ft_get_wall(t_game *game)
{
	int		line_height;
	double	wall_x;

	line_height = (int)(HEIGHT / game->ray->perp_wall_dist);
	game->wall->start = -line_height / 2 + HEIGHT / 2;
	if (game->wall->start < 0)
		game->wall->start = 0;
	game->wall->end = line_height / 2 + HEIGHT / 2;
	if (game->wall->end >= HEIGHT)
		game->wall->end = HEIGHT - 1;
	if (game->ray->side == 0)
		wall_x = game->player->p_y + game->ray->perp_wall_dist
			* game->ray->dir_y;
	else
		wall_x = game->player->p_x + game->ray->perp_wall_dist
			* game->ray->dir_x;
	wall_x -= floor((wall_x));
	game->wall->tex_x = (int)(wall_x * (double)(IMG));
	if ((game->ray->side == 0 && game->ray->dir_x > 0)
		|| (game->ray->side == 1 && game->ray->dir_y < 0))
		game->wall->tex_x = IMG - game->wall->tex_x - 1;
	game->wall->step = 1.0 * IMG / line_height;
	game->wall->position = (game->wall->start - 0 - HEIGHT
			/ 2 + line_height / 2) * game->wall->step;
}

void	ft_draw_walls(t_game *game, int x)
{
	int	wall_y;
	int	pixel;
	int	y;

	ft_get_wall(game);
	y = game->wall->start;
	while (y < game->wall->end)
	{
		wall_y = (int)game->wall->position & (IMG - 1);
		game->wall->position += game->wall->step;
		pixel = ft_get_pixel(game->wall, game->img, wall_y);
		my_mlx_pixel_put(game->img, x, y, pixel);
		y++;
	}
}

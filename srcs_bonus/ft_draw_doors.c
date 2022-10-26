/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_doors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:26:07 by snino             #+#    #+#             */
/*   Updated: 2022/10/26 18:04:31 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	set_door_data(t_game *game, int x)
{
	game->door->door = true;
	game->door->perp_wall_dist = ft_get_perp_wall_dist(game);
	game->door->x = x;
	game->door->side = game->ray->side;
	game->door->dir_x = game->ray->dir_x;
	game->door->dir_y = game->ray->dir_y;
}

bool	is_wall(t_game *game, int x, int y, int p_x)
{
	if (game->map[x][y] == '2')
		set_door_data(game, p_x);
	if (game->map[x][y] != '0')
		return (true);
	return (false);
}

static void	get_door_game(t_game *game)
{
	int		line_height;
	double	hit_point;

	line_height = (int)(HEIGHT / game->door->perp_wall_dist);
	game->wall->start = -line_height / 2 + HEIGHT / 2;
	if (game->wall->start < 0)
		game->wall->start = 0;
	game->wall->end = line_height / 2 + HEIGHT / 2;
	if (game->wall->end >= HEIGHT)
		game->wall->end = HEIGHT - 1;
	if (game->door->side == 0)
		hit_point = game->player->p_y + game->door->perp_wall_dist * game->door->dir_y;
	else
		hit_point = game->player->p_x + game->door->perp_wall_dist * game->door->dir_x;
	hit_point -= floor((hit_point));
	game->wall->tex_x = (int)(hit_point * (double)(IMG));
	if ((game->door->side == 0 && game->door->dir_x > 0)
		|| (game->door->side == 1 && game->door->dir_y < 0))
		game->wall->tex_x = IMG - game->wall->tex_x - 1;
	game->wall->step = (1.0 * IMG / line_height);
	game->wall->position = (game->wall->start - 0 - HEIGHT / 2
					  + line_height / 2) * game->wall->step;
}

void	ft_draw_doors(t_game *game, int x)
{
	int	wall_y;
	int	pixel;
	int	y;

	get_door_game(game);
	y = game->wall->start;
	while (y < game->wall->end)
	{
		wall_y = (int)game->wall->position & (IMG - 1);
		game->wall->position += game->wall->step;
		pixel = game->img->doors[game->wall->tex_x][wall_y];
		my_mlx_pixel_put(game->img, x, y, pixel);
		y++;
	}
}


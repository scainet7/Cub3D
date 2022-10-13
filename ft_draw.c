/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:01:40 by snino             #+#    #+#             */
/*   Updated: 2022/10/15 18:17:29 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_texture(t_game *game, t_win *tex, int x, int shade)
{
	int	y;

	y = game->raycast->draw_start;
	game->raycast->tex_x = (int)(game->raycast->wall * (double)(tex->x));
	if (game->raycast->side == 0 && game->raycast->ray_dir_x > 0)
		game->raycast->tex_x = tex->x - game->raycast->tex_x - 1;
	if (game->raycast->side == 1 && game->raycast->ray_dir_y < 0)
		game->raycast->tex_x = tex->x - game->raycast->tex_x - 1;
	game->raycast->step = 1.0 * tex->y / game->raycast->line_height;
	game->raycast->tex_pos = (game->raycast->draw_start - HEIGHT / 2 + \
			game->raycast->line_height / 2) * game->raycast->step;
	while (y < game->raycast->draw_end)
	{
		game->raycast->tex_y = (int)game->raycast->tex_pos & (tex->y - 1);
		game->raycast->tex_pos += game->raycast->step;
		game->raycast->color = get_tex_color_pixel(tex, \
			game->raycast->tex_x, game->raycast->tex_y);
		if (shade == 0)
			my_mlx_pixel_put(game->win->win, x, y, game->raycast->color);
		else
			my_mlx_pixel_put(game->win->win, x, y, add_shade(0.2, game->raycast->color));
		++y;
	}
}

static void ft_draw_floor(t_game *game, int x)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		if (y < game->raycast->draw_start)
		{
			my_mlx_pixel_put(game->win->win, x, y, create_rgb(game->img.ceiling[0], \
					game->img.ceiling[1], game->img.ceiling[2]));
		}
		else if (y >= game->raycast->draw_end)
		{
			my_mlx_pixel_put(game->win->win, x, y, create_rgb(game->img.floor[0], \
					game->img.floor[1], game->img.floor[2]));
		}
		++y;
	}
}

static void ft_draw_wall(t_game *game, int x)
{
	if (game->raycast->side == 1 && game->raycast->step_y < 0)
		draw_texture(game, game->n_tex, x, 1);
	else if (game->raycast->side == 1 && game->raycast->step_y > 0)
		draw_texture(game, game->s_tex, x, 0);
	else if (game->raycast->side == 0 && game->raycast->step_x < 0)
		draw_texture(game, game->e_tex, x, 1);
	else if (game->raycast->side == 0 && game->raycast->step_x > 0)
		draw_texture(game, game->w_tex, x, 0);
}

void	ft_draw_game(t_game *game, int x)
{
	if (game->raycast->side == 0)
	{
		game->raycast->wall = game->player->p_y + game->raycast->perp_wall_dist * \
				game->raycast->ray_dir_y;
	}
	else
	{
		game->raycast->wall = game->player->p_x + game->raycast->perp_wall_dist * \
				game->raycast->ray_dir_x;
	}
	game->raycast->wall -= floor((game->raycast->wall));
	ft_draw_wall(game, x);
	ft_draw_floor(game, x);
}

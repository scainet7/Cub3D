/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:35:23 by snino             #+#    #+#             */
/*   Updated: 2022/10/29 18:37:42 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

static void	ft_draw_floor_next_bonus(t_game *game, int x, int y)
{
	int	tx;
	int	ty;
	int	pixel;
	int	cell_x;
	int	cell_y;

	x = 0;
	while (x < WIDTH)
	{
		cell_x = (int)(game->floor->floor_x);
		cell_y = (int)(game->floor->floor_y);
		tx = (int)(IMG * (game->floor->floor_x - cell_x)) & (IMG - 1);
		ty = (int)(IMG * (game->floor->floor_y - cell_y)) & (IMG - 1);
		game->floor->floor_x += game->floor->floor_step_x;
		game->floor->floor_y += game->floor->floor_step_y;
		pixel = game->img->floor_img[5][IMG * ty + tx];
		my_mlx_pixel_put(game->img, x, y, pixel);
		pixel = game->img->ceiling_img[6][IMG * ty + tx];
		my_mlx_pixel_put(game->img, x, HEIGHT - y - 1, pixel);
		x++;
	}
}

void	ft_draw_bonus(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < HEIGHT)
	{
		game->floor->ray_dir_x0 = game->player->dir_x - game->player->plane_x;
		game->floor->ray_dir_y0 = game->player->dir_y - game->player->plane_y;
		game->floor->ray_dir_x1 = game->player->dir_x + game->player->plane_x;
		game->floor->ray_dir_y1 = game->player->dir_y + game->player->plane_y;
		game->floor->p = y - HEIGHT / 2;
		game->floor->pos_z = 0.5 * HEIGHT;
		game->floor->row_distance = game->floor->pos_z / game->floor->p;
		game->floor->floor_step_x = game->floor->row_distance \
				* (game->floor->ray_dir_x1 - game->floor->ray_dir_x0) / WIDTH;
		game->floor->floor_step_y = game->floor->row_distance \
				* (game->floor->ray_dir_y1 - game->floor->ray_dir_y0) / WIDTH;
		game->floor->floor_x = game->player->p_x + \
				game->floor->row_distance * game->floor->ray_dir_x0;
		game->floor->floor_y = game->player->p_y + \
				game->floor->row_distance * game->floor->ray_dir_y0;
		ft_draw_floor_next_bonus(game, x, y);
		y++;
	}
}

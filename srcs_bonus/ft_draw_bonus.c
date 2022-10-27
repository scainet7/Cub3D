/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:35:23 by snino             #+#    #+#             */
/*   Updated: 2022/10/27 19:52:15 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
static void	ft_draw_floor_next_bonus(t_game *game, int x, int y)
{

	int tx;
	int ty;
	int	pixel;
	int cellX;
	int cellY;

	cellX = (int)(game->floor->floorX);
	cellY = (int)(game->floor->floorY);
	tx = (int)(IMG * (game->floor->floorX - cellX)) & (IMG - 1);
	ty = (int)(IMG * (game->floor->floorY - cellY)) & (IMG - 1);
	game->floor->floorX += game->floor->floorStepX;
	game->floor->floorY += game->floor->floorStepY;
	pixel = game->img->floor_img[5][HEIGHT * ty + tx];
	my_mlx_pixel_put(game->img, x, y, pixel);
	pixel = game->img->ceiling_img[6][HEIGHT * ty + tx];
	my_mlx_pixel_put(game->img, x, HEIGHT - y - 1, pixel);
}

void	ft_draw_bonus(t_game *game)
{
	int 	x;
	int 	y;

	y = 0;
	while (y < HEIGHT)
	{
		game->floor->rayDirX0 = game->player->dir_x - game->player->plane_x;
		game->floor->rayDirY0 = game->player->dir_y - game->player->plane_y;
		game->floor->rayDirX1 = game->player->dir_x + game->player->plane_x;
		game->floor->rayDirY1 = game->player->dir_y + game->player->plane_y;
		game->floor->p = y - HEIGHT / 2;
		game->floor->posZ = 0.5 * HEIGHT;
		game->floor->rowDistance = game->floor->posZ / game->floor->p;
		game->floor->floorStepX = game->floor->rowDistance * (game->floor->rayDirX1 - game->floor->rayDirX0) / WIDTH;
		game->floor->floorStepY = game->floor->rowDistance * (game->floor->rayDirY1 - game->floor->rayDirY0) / WIDTH;
		game->floor->floorX = game->player->p_x + game->floor->rowDistance * game->floor->rayDirX0;
		game->floor->floorY = game->player->p_y + game->floor->rowDistance * game->floor->rayDirY0;
		x = 0;
		while (x < WIDTH)
		{
			ft_draw_floor_next_bonus(game, x, y);
			x++;
		}
		y++;
	}
}

//void	ft_draw_bonus(t_game *game)
//{
//		ft_draw_floor_bonus(game);
//		ft_draw_ceiling_bonus(game);
//}


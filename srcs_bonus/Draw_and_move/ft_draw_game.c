/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:05:17 by snino             #+#    #+#             */
/*   Updated: 2022/10/27 21:40:36 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

//static void	draw_ceiling(t_game *game, int x, int up_to)
//{
//	int	i;
//	int	red;
//	int	green;
//	int	blue;
//	int	color;
//
//	red = game->img->ceiling[0];
//	green = game->img->ceiling[1];
//	blue = game->img->ceiling[2];
//	color = create_rgb(red, green, blue);
//	i = 0;
//	while (i < up_to && i < HEIGHT)
//	{
//		my_mlx_pixel_put(game->img, x, i, color);
//		i++;
//	}
//}
//
//static void	draw_floor(t_game *game, int x, int from)
//{
//	int	i;
//	int	red;
//	int	green;
//	int	blue;
//	int	color;
//
//	red = game->img->floor[0];
//	green = game->img->floor[1];
//	blue = game->img->floor[2];
//	color = create_rgb(red, green, blue);
//	i = from;
//	while (i < HEIGHT)
//	{
//		my_mlx_pixel_put(game->img, x, i, color);
//		i++;
//	}
//}

int	ft_draw_game(t_game *game)
{
	int	x;

	x = 0;
	check_events(game);
	ft_draw_bonus(game);
	while (x < WIDTH)
	{
		ft_raycast(game, x);
		ft_draw_walls(game, x);
//		draw_ceiling(game, x, game->wall->start);
//		draw_floor(game, x, game->wall->end);
		if (game->door->door)
			ft_draw_doors(game, x);
		x++;
	}
	ft_draw_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img->ptr, 0, 0);
	return (EXIT_SUCCESS);
}

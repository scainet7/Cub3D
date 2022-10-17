/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:05:17 by snino             #+#    #+#             */
/*   Updated: 2022/10/17 21:10:46 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_draw_game(t_game *game)
{
	int	x;

	x = 0;
	usleep(5000);
	while (x < WIDTH)
	{
//		get_ray(data, x);
//		draw_walls(data, x);
//		draw_ceiling(data, x, data->wall.top);
//		draw_floor(data, x, data->wall.bottom);
//		if (data->door.door)
//			draw_doors(data, x);
		x++;
	}
//	draw_minimap(data);
	mlx_put_image_to_window(game->mlx, game->win,
							game->img->ptr, WIDTH, HEIGHT);
	return (EXIT_SUCCESS);
}
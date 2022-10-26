/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record_types_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:03:50 by snino             #+#    #+#             */
/*   Updated: 2022/10/26 19:47:25 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_get_wall_pixels_bonus(t_img *img,int type, int i, int j)
{
	if (type == door1)
		img->doors1[i][j] = my_mlx_pixel_get(img, i, j);
	else if (type == door2)
		img->doors2[i][j] = my_mlx_pixel_get(img, i, j);
	else if (type == door3)
		img->doors2[i][j] = my_mlx_pixel_get(img, i, j);
	else if (type == door4)
		img->doors2[i][j] = my_mlx_pixel_get(img, i, j);
	else if (type == door5)
		img->doors2[i][j] = my_mlx_pixel_get(img, i, j);
	else if (type == door6)
		img->doors2[i][j] = my_mlx_pixel_get(img, i, j);
	else if (type == door7)
		img->doors2[i][j] = my_mlx_pixel_get(img, i, j);
}

void	ft_init_textures_next_bonus(t_game *game, int i)
{
	if (i == door1)
		game->img->addr = mlx_get_data_addr(game->img->door1,
						&game->img->bits_per_pixel, &game->img->line_length,
											&game->img->endian);
	else if (i == door2)
		game->img->addr = mlx_get_data_addr(game->img->door2,
											&game->img->bits_per_pixel, &game->img->line_length,
											&game->img->endian);
	else if (i == door3)
		game->img->addr = mlx_get_data_addr(game->img->door3,
											&game->img->bits_per_pixel, &game->img->line_length,
											&game->img->endian);
	else if (i == door4)
		game->img->addr = mlx_get_data_addr(game->img->door4,
											&game->img->bits_per_pixel, &game->img->line_length,
											&game->img->endian);
	else if (i == door5)
		game->img->addr = mlx_get_data_addr(game->img->door5,
											&game->img->bits_per_pixel, &game->img->line_length,
											&game->img->endian);
	else if (i == door6)
		game->img->addr = mlx_get_data_addr(game->img->door6,
											&game->img->bits_per_pixel, &game->img->line_length,
											&game->img->endian);
	else if (i == door7)
		game->img->addr = mlx_get_data_addr(game->img->door7,
											&game->img->bits_per_pixel, &game->img->line_length,
											&game->img->endian);
}

void	ft_record_types_bonus(t_game *game, int x, int y)
{
	game->img->door = mlx_xpm_file_to_image(game->mlx,
			"textures/star_wall1.xpm", &x, &y);
	game->img->door1 = mlx_xpm_file_to_image(game->mlx,
			"textures/door/star_wall1-8.xpm", &x, &y);
	game->img->door2 = mlx_xpm_file_to_image(game->mlx,
			"textures/door/star_wall1-7.xpm", &x, &y);
	game->img->door3 = mlx_xpm_file_to_image(game->mlx,
			"textures/door/star_wall1-6.xpm", &x, &y);
	game->img->door4 = mlx_xpm_file_to_image(game->mlx,
			"textures/door/star_wall1-5.xpm", &x, &y);
	game->img->door5 = mlx_xpm_file_to_image(game->mlx,
			"textures/door/star_wall1-4.xpm", &x, &y);
	game->img->door6 = mlx_xpm_file_to_image(game->mlx,
			"textures/door/star_wall1-3.xpm", &x, &y);
	game->img->door7 = mlx_xpm_file_to_image(game->mlx,
			"textures/door/star_wall1-2.xpm", &x, &y);
	game->img->floors = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &x, &y);
	game->img->ceilings = mlx_xpm_file_to_image(game->mlx,
			"textures/ceiling.xpm", &x, &y);
}


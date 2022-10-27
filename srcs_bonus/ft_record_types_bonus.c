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

void	ft_init_textures_next_bonus(t_game *game, int i)
{
	if (i == door)
		game->img->addr = mlx_get_data_addr(game->img->door,
						&game->img->bits_per_pixel, &game->img->line_length,
						&game->img->endian);
	if (i == floors)
		game->img->addr = mlx_get_data_addr(game->img->floors,
						&game->img->bits_per_pixel, &game->img->line_length,
						&game->img->endian);
	if (i == ceilings)
		game->img->addr = mlx_get_data_addr(game->img->ceilings,
						&game->img->bits_per_pixel, &game->img->line_length,
						&game->img->endian);
}

void	ft_get_wall_pixels_bonus(t_img *img, int type, int i, int j)
{
	if (type == door)
		img->doors[i][j] = my_mlx_pixel_get(img, i, j);
	else if (type == floors)
		img->floor_img[i][j] = my_mlx_pixel_get(img, i, j);
	else if (type == ceilings)
		img->ceiling_img[i][j] = my_mlx_pixel_get(img, i, j);
}

void	ft_record_types_bonus(t_game *game, int x, int y)
{
	game->img->door = mlx_xpm_file_to_image(game->mlx,
			"textures/star_wall1.xpm", &x, &y);
	game->img->floors = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &x, &y);
	game->img->ceilings = mlx_xpm_file_to_image(game->mlx,
			"textures/ceiling.xpm", &x, &y);

}


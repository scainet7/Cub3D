/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:40:18 by snino             #+#    #+#             */
/*   Updated: 2022/10/17 19:40:18 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	my_mlx_pixel_get(t_img *img, int x, int y)
{
	int		color;
	char	*dst;

	dst = img->addr + (y * img->line_length + x* (img->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	ft_get_wall_pixels(t_img *img, int type)
{
	int	i;
	int	j;

	i = 0;
	while (i < IMG)
	{
		j = 0;
		while (j < IMG)
		{
			if (type == 0)
				img->north_wall[i][j] = my_mlx_pixel_get(img, i, j);
			else if (type == 1)
				img->south_wall[i][j] = my_mlx_pixel_get(img, i, j);
			else if (type == 2)
				img->east_wall[i][j] = my_mlx_pixel_get(img, i, j);
			else if (type == 3)
				img->west_wall[i][j] = my_mlx_pixel_get(img, i, j);
			j++;
		}
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:34:13 by snino             #+#    #+#             */
/*   Updated: 2022/10/23 19:53:10 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	draw_25(t_img *img, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			my_mlx_pixel_put(img, (x * 5) + i, (y * 5) + j, color);
			j++;
		}
		i++;
	}
}

static void	draw_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = -1;
		while (j < 5)
		{
			my_mlx_pixel_put(game->img, (game->player->p_y * 5) + i,
							 (game->player->p_x * 5) + j, 0xDC1430);
			j++;
		}
		i++;
	}
}

static void	ft_max_height_width(t_game *game)
{
	int 	y;
	int 	max_x;

	y = 0;
	max_x = 0;
	while(game->map[y])
	{
		if (y == 0)
			max_x = ft_strlen(game->map[y]);
		if (y != 0 && (max_x < ft_strlen(game->map[y])))
			max_x = ft_strlen(game->map[y]);
		y++;
	}
	game->width = max_x;
	game->height = y;
}

int	ft_draw_minimap(t_game *game)
{
	int	i;
	int	j;
	int	color;

	ft_max_height_width(game);
	i = 0;
	while (i < game->width)
	{
		j = 0;
		while (j < game->height)
		{
			color = get_color(game->map[j][i]);
			if (color)
				draw_25(game->img, i, j, color);
			j++;
		}
		i++;
	}
	draw_player(game);
	return (0);
}
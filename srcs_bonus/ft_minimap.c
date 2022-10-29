/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:51:02 by snino             #+#    #+#             */
/*   Updated: 2022/10/29 14:43:54 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

static void	ft_draw_minimap_player(t_game *game, int i, float j)
{
	float	x1;
	float	y1;
	float	x;
	float	y;

	j = -1;
	y = game->player->p_x * MIMG;
	x = game->player->p_y * MIMG;
	while (++j <= 4)
	{
		i = -1;
		while (++i < 360)
		{
			x1 = j * cos(i * PI / 180);
			y1 = j * sin(i * PI / 180);
			my_mlx_pixel_put(game->img, x + x1 + WIDTH \
				- game->width * MIMG * 1.5, y + y1 + HEIGHT \
				- game->height * MIMG * 1.5, 0x656ec2);
		}
	}
}

static void	ft_draw_mapi(t_game *game, float x, float y, int colour)
{
	int		count;
	int		row_size;
	float	start_x;

	count = 0;
	while (count < MIMG)
	{
		start_x = x;
		row_size = 0;
		while (row_size < MIMG)
		{
			my_mlx_pixel_put(game->img, start_x + WIDTH \
			- game->width * MIMG * 1.5, y + count + HEIGHT \
			- game->height * MIMG * 1.5, colour);
			start_x++;
			row_size++;
		}
		count++;
	}
}

static void	ft_max_height_width(t_game *game)
{
	int	y;
	int	max_x;

	y = 0;
	max_x = 0;
	while (game->map[y])
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

void	ft_draw_minimap(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	ft_max_height_width(game);
	while (++i < game->width)
	{
		j = -1;
		while (++j < game->height)
		{
			if ((game->map[j][i]) == '1')
				ft_draw_mapi(game, i * MIMG, \
				j * MIMG, 0x6b6b6b);
			if ((game->map[j][i]) == '2')
				ft_draw_mapi(game, i * MIMG, \
				j * MIMG, 0xa82323);
		}
	}
	ft_draw_minimap_player(game, i, (float)j);
}

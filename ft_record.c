/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:55:26 by snino             #+#    #+#             */
/*   Updated: 2022/10/18 18:46:35 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_record_color(t_game *game)
{
	t_map 	*color;
	char	**tmp_color;

	color = game->colors;
	tmp_color = NULL;
	while (color)
	{
		tmp_color = color->maps_line;
		if (!ft_strncmp(tmp_color[0], "F", 1))
		{
			game->img->floor[0] = ft_atoi(tmp_color[1]);
			game->img->floor[1] = ft_atoi(tmp_color[2]);
			game->img->floor[2] = ft_atoi(tmp_color[3]);
		}
		if (!ft_strncmp(tmp_color[0], "C", 1))
		{
			game->img->ceiling[0] = ft_atoi(tmp_color[1]);
			game->img->ceiling[1] = ft_atoi(tmp_color[2]);
			game->img->ceiling[2] = ft_atoi(tmp_color[3]);
		}
		color = color->next;
	}
}

static void ft_init_textures(t_game *game)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (i == 0)
			game->img->addr = mlx_get_data_addr(game->img->wall_no,
			&game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
		else if (i == 1)
			game->img->addr = mlx_get_data_addr(game->img->wall_so,
			&game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
		else if (i == 2)
			game->img->addr = mlx_get_data_addr(game->img->wall_we,
			&game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
		else if (i == 3)
			game->img->addr = mlx_get_data_addr(game->img->wall_ea,
			&game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
		else if (game->img->addr == NULL)
			ft_error_handler(game, "Error\nMALLOC_STRUCKT_PLAYER_POSITION", mlx);
		ft_get_wall_pixels(game->img, i);
		free(game->img->addr);
		game->img->addr = NULL;
		i++;
	}
}

static void	ft_record_types(t_game *game)
{
	int 	x;
	int 	y;
	char	**types_line;
	t_map 	*types;

	types = game->types;
	types_line = NULL;
	while (types)
	{
		types_line = types->maps_line;
		if (!ft_strncmp(types_line[0], "NO", 2))
			game->img->wall_no = mlx_xpm_file_to_image(
					game->mlx, &types_line[1][2], &x, &y);
		else if (!ft_strncmp(types_line[0], "SO", 2))
			game->img->wall_so = mlx_xpm_file_to_image(
					game->mlx, &types_line[1][2], &x, &y);
		else if (!ft_strncmp(types_line[0], "WE", 2))
			game->img->wall_we = mlx_xpm_file_to_image(
					game->mlx, &types_line[1][2], &x, &y);
		else if (!ft_strncmp(types_line[0], "EA", 2))
			game->img->wall_ea = mlx_xpm_file_to_image(
					game->mlx, &types_line[1][2], &x, &y);
		types = types->next;
	}
}

void	ft_record(t_game *game)
{
	ft_record_types(game);
	ft_init_textures(game);
	ft_record_color(game);
}

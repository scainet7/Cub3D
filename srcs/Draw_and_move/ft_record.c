/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:55:26 by snino             #+#    #+#             */
/*   Updated: 2022/10/27 19:59:46 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	ft_record_color(t_game *game)
{
	t_map	*color;
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

static void	ft_init_textures_next(t_game *game, int i)
{
	if (i == north)
		game->img->addr = mlx_get_data_addr(game->img->wall_no,
				&game->img->bits_per_pixel, &game->img->line_length,
				&game->img->endian);
	else if (i == south)
		game->img->addr = mlx_get_data_addr(game->img->wall_so,
				&game->img->bits_per_pixel, &game->img->line_length,
				&game->img->endian);
	else if (i == west)
		game->img->addr = mlx_get_data_addr(game->img->wall_we,
				&game->img->bits_per_pixel, &game->img->line_length,
				&game->img->endian);
	else if (i == east)
		game->img->addr = mlx_get_data_addr(game->img->wall_ea,
				&game->img->bits_per_pixel, &game->img->line_length,
				&game->img->endian);
	if (game->flag)
		ft_init_textures_next_bonus(game, i);
}

static void	ft_init_textures(t_game *game)
{
	int		i;
	int 	num;

	i = 0;
	num = 4;
	if (game->flag)
		num = 7;
	while (i < num)
	{
		ft_init_textures_next(game, i);
		if (game->img->addr == NULL)
			ft_exit_game(game, "Error\nMALLOC_STRUCKT_ADDR_TEXTURE",
				EXIT_FAILURE);
		ft_get_wall_pixels(game->img, i);
		free(game->img->addr);
		game->img->addr = NULL;
		i++;
	}
}

static void	ft_record_types(t_game *game)
{
	int		x;
	int		y;
	t_map	*types;

	types = game->types;
	while (types)
	{
		if (!ft_strncmp(types->maps_line[0], "NO", 2))
			game->img->wall_no = mlx_xpm_file_to_image(
					game->mlx, &types->maps_line[1][2], &x, &y);
		else if (!ft_strncmp(types->maps_line[0], "SO", 2))
			game->img->wall_so = mlx_xpm_file_to_image(
					game->mlx, &types->maps_line[1][2], &x, &y);
		else if (!ft_strncmp(types->maps_line[0], "WE", 2))
			game->img->wall_we = mlx_xpm_file_to_image(
					game->mlx, &types->maps_line[1][2], &x, &y);
		else if (!ft_strncmp(types->maps_line[0], "EA", 2))
			game->img->wall_ea = mlx_xpm_file_to_image(
					game->mlx, &types->maps_line[1][2], &x, &y);
		types = types->next;
	}
	if (game->flag)
		ft_record_types_bonus(game, x, y);
}

void	ft_record(t_game *game)
{
	ft_record_types(game);
	ft_init_textures(game);
	ft_record_color(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:55:26 by snino             #+#    #+#             */
/*   Updated: 2022/09/25 20:52:44 by snino            ###   ########.fr       */
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
			game->img.floor[0] = ft_atoi(tmp_color[1]);
			game->img.floor[1] = ft_atoi(tmp_color[2]);
			game->img.floor[2] = ft_atoi(tmp_color[3]);
		}
		if (!ft_strncmp(tmp_color[0], "C", 1))
		{
			game->img.ceiling[0] = ft_atoi(tmp_color[1]);
			game->img.ceiling[1] = ft_atoi(tmp_color[2]);
			game->img.ceiling[2] = ft_atoi(tmp_color[3]);
		}
		color = color->next;
	}
}

static void	ft_record_types(t_game *game)
{
	int		y;
	int		x;
	t_map 	*types;
	char	**tmp_types;

	types = game->types;;
	tmp_types = NULL;
	while (types)
	{
		tmp_types = types->maps_line;
		if (!ft_strncmp(tmp_types[0], "NO", 2))
		{
//			tmp_types[1] = tmp_types[1] + 2;
			game->img.wall_no = mlx_xpm_file_to_image(game->mlx, &tmp_types[1][1], &x, &y);
		}
		if (!ft_strncmp(tmp_types[0], "SO", 2))
			game->img.wall_so = mlx_xpm_file_to_image(
					game->mlx, &tmp_types[1][1], &x, &y);
		if (!ft_strncmp(tmp_types[0], "WE", 2))
			game->img.wall_we = mlx_xpm_file_to_image(
					game->mlx, &tmp_types[1][1], &x, &y);
		if (!ft_strncmp(tmp_types[0], "EA", 2))
			game->img.wall_ea = mlx_xpm_file_to_image(
					game->mlx, &tmp_types[1][1], &x, &y);
		types = types->next;
	}
}

void	ft_record(t_game *game)
{
	ft_record_types(game);
	ft_record_color(game);
}

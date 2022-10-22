/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 21:28:55 by snino             #+#    #+#             */
/*   Updated: 2022/10/22 21:28:55 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static	void ft_free_mass(t_map *line)
{
	t_map	*temp;

	while (line)
	{
		temp = line->next;
		free(line->maps_line);
		free(line);
		line = temp;
	}
}

int	ft_exit_game(t_game *game, char *str, int exit_state)
{
	printf(RED"%s\n"END, str);
	if (exit_state >= EXIT_FAILURE)
		exit(EXIT_FAILURE);
	mlx_destroy_image(game->mlx, game->img->ptr);
	mlx_destroy_window(game->mlx, game->win);
	free(game->player);
	free(game->img);
	free(game->ray);
	free(game->wall);
	ft_freelst(game->type_list);
	ft_freelst(game->color_list);
	ft_freelst(game->map_list);
	ft_free_mass(game->types);
	ft_free_mass(game->colors);
	free(game->map);
	exit(EXIT_SUCCESS);
}

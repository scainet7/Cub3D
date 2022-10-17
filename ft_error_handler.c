/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:45:21 by snino             #+#    #+#             */
/*   Updated: 2022/10/17 18:43:07 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_error_handler(t_game *game, char *str, int sweep)
{
	(void)game;

	if (sweep == clean)
	{
		printf(RED"%s\n"END, str);
//		ft_free_game(game);
		exit(EXIT_FAILURE);
	}
	else if (sweep == mlx)
	{
		printf(RED"%s\n"END, str);
		exit(EXIT_FAILURE);
	}
	else if (sweep == map)
	{
		printf(RED"%s\n"END, str);
//		ft_free_map_game(game);
		exit(EXIT_FAILURE);
	}
	printf(RED"%s\n"END, str);
	exit(EXIT_FAILURE);
}

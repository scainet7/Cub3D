/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_map_mass2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:35:30 by snino             #+#    #+#             */
/*   Updated: 2022/10/23 12:13:40 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	ft_check_map_mass_angle(t_game *game, int n)
{
	int		i;
	int		j;
	char	**mass_map;

	i = 0;
	mass_map = game->map;
	while (++i < n)
	{
		j = 0;
		while (mass_map[i][j])
		{
			if (mass_map[i][j] == '1' && (mass_map[i][j + 1] == '0' || \
				mass_map[i][j + 1] == 'N' || mass_map[i][j + 1] == 'S' || \
				mass_map[i][j + 1] == 'W' || mass_map[i][j + 1] == 'E'))
				if (mass_map[i - 1][j] == ' ' || mass_map[i + 1][j] == ' ')
					ft_exit_game(game, "Error\nINVALID_MAP", EXIT_FAILURE);
			if ((mass_map[i][j] == '0' || mass_map[i][j] == 'N' || \
				mass_map[i][j] == 'S' || mass_map[i][j] == 'W' || \
				mass_map[i][j] == 'E') && mass_map[i][j + 1] == '1')
				if (mass_map[i - 1][j + 1] == ' ' || mass_map[i + 1][j + 1] == \
					' ' || !mass_map[i - 1][j + 1] || !mass_map[i + 1][j + 1])
					ft_exit_game(game, "Error\nINVALID_MAP", EXIT_FAILURE);
			j++;
		}
	}
}

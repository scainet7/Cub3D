/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_map_mass2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:52:26 by snino             #+#    #+#             */
/*   Updated: 2022/10/29 14:43:54 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

static int	ft_utils_check(t_game *game, int i, int j)
{
	char	**mass_map;

	mass_map = game->map;
	if (mass_map[i][j] != 'N' && mass_map[i][j] != 'S' \
		&& mass_map[i][j] != 'W' && mass_map[i][j] != 'E' \
		&& mass_map[i][j] != '1' && mass_map[i][j] != '0' \
		&& mass_map[i][j] != ' ' && mass_map[i][j] != '\0' \
		&& mass_map[i][j] != '2')
		return (1);
	return (0);
}

void	ft_check_map_mass_symb_bonus(t_game *game)
{
	int		i;
	int		j;
	int		n;
	char	**mass_map;

	i = -1;
	n = 0;
	mass_map = game->map;
	while (mass_map[++i])
	{
		j = -1;
		while (mass_map[i][++j])
		{
			if (mass_map[i][j] == 'N' || mass_map[i][j] == 'S' \
				|| mass_map[i][j] == 'W' || mass_map[i][j] == 'E')
				n++;
			else if (ft_utils_check(game, i, j))
				ft_exit_game(game, "Error\nINVALID_MAP_SYMBOL", EXIT_FAILURE);
		}
	}
	if (n != 1)
		ft_exit_game(game, "Error\nINVALID_MAP_DOUBLE", EXIT_FAILURE);
}

static int	ft_utils_check2(t_game *game, int i, int j)
{
	char	**mass_map;

	mass_map = game->map;
	if ((mass_map[i][j] == '0' || mass_map[i][j] == 'N' || \
		mass_map[i][j] == 'S' || mass_map[i][j] == 'W' || \
		mass_map[i][j] == 'E' || mass_map[i][j] == '2') \
		&& mass_map[i][j + 1] == '1')
		return (1);
	return (0);
}

static int	ft_utils_check1(t_game *game, int i, int j)
{
	char	**mass_map;

	mass_map = game->map;
	if (mass_map[i][j] == '1' && (mass_map[i][j + 1] == '0' || \
		mass_map[i][j + 1] == 'N' || mass_map[i][j + 1] == 'S' || \
		mass_map[i][j + 1] == 'W' || mass_map[i][j + 1] == 'E' || \
		mass_map[i][j + 1] == '2'))
		return (1);
	return (0);
}

void	ft_check_map_mass_angle_bonus(t_game *game, int n)
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
			if (ft_utils_check1(game, i, j))
				if (mass_map[i - 1][j] == ' ' || mass_map[i + 1][j] == ' ')
					ft_exit_game(game, "Error\nINVALID_MAP", EXIT_FAILURE);
			if (ft_utils_check2(game, i, j))
				if (mass_map[i - 1][j + 1] == ' ' || mass_map[i + 1][j + 1] == \
					' ' || !mass_map[i - 1][j + 1] || !mass_map[i + 1][j + 1])
					ft_exit_game(game, "Error\nINVALID_MAP", EXIT_FAILURE);
			j++;
		}
	}
}

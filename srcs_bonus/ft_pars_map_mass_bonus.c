/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_map_mass_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:48:21 by snino             #+#    #+#             */
/*   Updated: 2022/10/29 14:43:54 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

static void	ft_check_map_mass_space2_bonus(t_game *game, int n)
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
			if (mass_map[i][j] == ' ')
				if (mass_map[i + 1][j] != ' ' && mass_map[i + 1][j] != '1')
					ft_exit_game(game, "Error\nINVALID_MAP", EXIT_FAILURE);
			j++;
		}
	}
}

static void	ft_check_map_mass_space_bonus(t_game *game)
{
	int		i;
	int		j;
	char	**mass_map;

	i = -1;
	mass_map = game->map;
	while (mass_map[++i])
	{
		j = 0;
		while (mass_map[i][j] == ' ')
			j++;
		if (mass_map[i][j] != '1')
			ft_exit_game(game, "Error\nINVALID_MAP", EXIT_FAILURE);
		while (mass_map[i][j])
		{
			if (mass_map[i][j] == ' ' && mass_map[i][j + 1] != ' ')
				if (mass_map[i][j - 1] != '1' && mass_map[i][j + 1] != '1')
					ft_exit_game(game, "Error\nINVALID_MAP", EXIT_FAILURE);
			j++;
		}
		j--;
		if (mass_map[i][j] != '1')
			ft_exit_game(game, "Error\nINVALID_MAP", EXIT_FAILURE);
	}
}

void	ft_check_map_mass_bonus(t_game *game)
{
	char	**mass_map;
	int		i;
	int		j;

	i = -1;
	mass_map = game->map;
	while (mass_map[++i])
		;
	i--;
	j = 0;
	while (mass_map[0][j] == ' ' || mass_map[0][j] == '1')
		j++;
	if (mass_map[0][j] != '1' && mass_map[0][j] != ' ' && mass_map[0][j])
		ft_exit_game(game, "Error\nINVALID_MAP", EXIT_FAILURE);
	j = 0;
	while (mass_map[i][j] == ' ' || mass_map[i][j] == '1')
		j++;
	if (mass_map[i][j] != '1' && mass_map[i][j] != ' ' && mass_map[i][j])
		ft_exit_game(game, "Error\nINVALID_MAP", EXIT_FAILURE);
	ft_check_map_mass_symb_bonus(game);
	ft_check_map_mass_space_bonus(game);
	ft_check_map_mass_space2_bonus(game, i);
	ft_check_map_mass_angle_bonus(game, i);
}

void	ft_pars_map_mass_bonus(t_game *game)
{
	t_list	*tmp_list;
	char	**maps;
	int		i;

	tmp_list = game->map_list;
	maps = NULL;
	maps = (char **) malloc(sizeof (char *) * ft_memory_num1(tmp_list));
	i = 0;
	while (tmp_list)
	{
		maps[i] = tmp_list->content;
		maps[++i] = NULL;
		tmp_list = tmp_list->next;
	}
	game->map = maps;
}

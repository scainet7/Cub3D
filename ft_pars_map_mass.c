/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_map_mass.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:41:54 by snino             #+#    #+#             */
/*   Updated: 2022/09/20 21:06:05 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void ft_check_map_mass_symb(t_game *game)
{
	int 	i;
	int 	j;
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
			else if (mass_map[i][j] != 'N' && mass_map[i][j] != 'S' \
				&& mass_map[i][j] != 'W' && mass_map[i][j] != 'E' \
				&& mass_map[i][j] != '1' && mass_map[i][j] != '0' \
				&& mass_map[i][j] != ' ' && mass_map[i][j] != '\0'  )
				ft_error_handler(game, "Error\nINVALID_MAP", leave);
		}
	}
	if (n != 1)
		ft_error_handler(game, "Error\nINVALID_MAP", leave);
}

void ft_check_map_mass(t_game *game)
{
	char	**mass_map;
	int		i;
	int 	j;

	i = -1;
	mass_map = game->map;
	while(mass_map[++i])
		;
	i--;
	j = 0;
	while(mass_map[0][j] == ' ' || mass_map[0][j] == '1')
		j++;
	if (mass_map[0][j] != '1' && mass_map[0][j] != ' ' && mass_map[0][j])
		ft_error_handler(game, "Error\nINVALID_MAP", leave);
	j = 0;
	while(mass_map[i][j] == ' ' || mass_map[i][j] == '1')
		j++;
	if (mass_map[i][j] != '1' && mass_map[i][j] != ' ' && mass_map[i][j])
		ft_error_handler(game, "Error\nINVALID_MAP", leave);
	ft_check_map_mass_symb(game);
}

static int	ft_memory_num1(t_list *list)
{
	t_list	*tmp;
	int		count;

	tmp = list;
	count = 1;
	while (tmp)
	{
		if (!ft_memcmp(tmp->content, "\0", 2))
			break ;
		++count;
		tmp = tmp->next;
	}
	return (count);
}

void  ft_pars_map_mass(t_game *game)
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

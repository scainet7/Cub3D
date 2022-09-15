/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:03:21 by snino             #+#    #+#             */
/*   Updated: 2022/09/15 20:29:19 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ft_check_type_mass(t_game *game)
{
	t_map	*mass_type;
	int 	i;

	mass_type = game->types;
	while(mass_type)
	{
		i = -1;
		while (mass_type->maps_line[++i])
			;
		if (i == 2)
			;
		else
			ft_error_handler(game, "Error\nINVALID_TYPE_SPACE", leave);
		mass_type = mass_type->next;
	}
}

void	ft_pars_type_mass(t_game *game)
{
	t_list	*tmp_list;
	t_map 	*tmp_type;
	char	**type;
	int		i;

	tmp_list = game->type_list;
	tmp_type = NULL;
	while (tmp_list)
	{
		type = (char **) malloc(sizeof (char *) * ft_memory_num(tmp_list));
		i = -1;
		while (tmp_list && tmp_list->flag == 0)
		{
			type[++i] = tmp_list->content;
			tmp_list = tmp_list->next;
		}
		while (tmp_list && tmp_list->flag == 1)
		{
			type[++i] = tmp_list->content;
			tmp_list = tmp_list->next;
		}
		type[++i] = NULL;
		ft_lineadd_back(&tmp_type, ft_line_new(type));
	}
	game->types = tmp_type;
}

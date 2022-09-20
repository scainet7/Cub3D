/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:03:21 by snino             #+#    #+#             */
/*   Updated: 2022/09/20 14:58:20 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_check_types_file(t_game *game)
{
	t_map	*mass_type;
	int		fd;

	mass_type = game->types;
	while (mass_type)
	{
		fd = open(mass_type->maps_line[1], O_RDONLY);
		if (fd < 0)
			ft_error_handler(game, "Error\nNO_TEXTURE_FILE", leave);
		close(fd);
		mass_type = mass_type->next;
	}
}

static void	ft_check_double_types(t_game *game)
{
	t_map	*mass_type;
	int		n;
	int		s;
	int		w;
	int		e;

	n = 0;
	s = 0;
	w = 0;
	e = 0;
	mass_type = game->types;
	while (mass_type)
	{
		if (ft_strnstr(mass_type->maps_line[0], "NO", 3))
			n++;
		else if (ft_strnstr(mass_type->maps_line[0], "SO", 3))
			s++;
		else if (ft_strnstr(mass_type->maps_line[0], "WE", 3))
			w++;
		else if (ft_strnstr(mass_type->maps_line[0], "EA", 3))
			e++;
		mass_type = mass_type->next;
	}
	if (n != 1 || s != 1 || w != 1 || e != 1)
		ft_error_handler(game, "Error\nERROR_DUBLE_PLACE_TYPES", leave);
}

void	ft_check_type_mass(t_game *game)
{
	t_map	*mass_type;
	int		i;

	mass_type = game->types;
	while (mass_type)
	{
		i = -1;
		while (mass_type->maps_line[++i])
			;
		if (i != 2)
			ft_error_handler(game, "Error\nINVALID_TYPE_ARGUMENT", leave);
		mass_type = mass_type->next;
	}
	ft_check_double_types(game);
	ft_check_types_file(game);
}

void	ft_pars_type_mass(t_game *game)
{
	t_list	*tmp_list;
	t_map	*tmp_type;
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

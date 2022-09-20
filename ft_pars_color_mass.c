/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_color_mass.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:31:24 by snino             #+#    #+#             */
/*   Updated: 2022/09/20 15:38:52 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_check_color_num(t_game *game)
{
	t_map	*mass_color;
	int		i;
	int		j;
	int		num;

	mass_color = game->colors;
	while (mass_color)
	{
		i = -1;
		while (mass_color->maps_line[++i])
			;
		while (--i > 0)
		{
			j = -1;
			while (mass_color->maps_line[i][++j])
				if (!ft_isdigit(mass_color->maps_line[i][j]))
					ft_error_handler(game, "Error\nERROR_COLOR_RGB_NUM", leave);
			num = ft_atoi(mass_color->maps_line[i]);
			if (num < 0 || num > 255)
				ft_error_handler(game, "Error\nERROR_COLOR_RGB_NUM", leave);
		}
		mass_color = mass_color->next;
	}
}

static void	ft_check_double_color(t_game *game)
{
	t_map	*mass_color;
	int		f;
	int		c;

	f = 0;
	c = 0;
	mass_color = game->colors;
	while (mass_color)
	{
		if (ft_strnstr(mass_color->maps_line[0], "F", 2))
			f++;
		else if (ft_strnstr(mass_color->maps_line[0], "C", 2))
			c++;
		mass_color = mass_color->next;
	}
	if (f != 1 || c != 1)
		ft_error_handler(game, "Error\nERROR_DUBLE_PLACE_COLOR", leave);
}

void	ft_check_color_mass(t_game *game)
{
	t_map	*mass_color;
	int		i;

	mass_color = game->colors;
	while (mass_color)
	{
		i = -1;
		while (mass_color->maps_line[++i])
			;
		if (i != 4)
			ft_error_handler(game, "Error\nINVALID_COLOR_ARGUMENT", leave);
		mass_color = mass_color->next;
	}
	ft_check_double_color(game);
	ft_check_color_num(game);
}

void	ft_pars_color_mass(t_game *game)
{
	t_list	*tmp_list;
	t_map	*tmp_color;
	char	**color;
	int		i;

	tmp_list = game->color_list;
	tmp_color = NULL;
	while (tmp_list)
	{
		color = (char **) malloc(sizeof (char *) * ft_memory_num(tmp_list));
		i = -1;
		while (tmp_list && tmp_list->flag == 0)
		{
			color[++i] = tmp_list->content;
			tmp_list = tmp_list->next;
		}
		while (tmp_list && tmp_list->flag == 1)
		{
			color[++i] = tmp_list->content;
			tmp_list = tmp_list->next;
		}
		color[++i] = NULL;
		ft_lineadd_back(&tmp_color, ft_line_new(color));
	}
	game->colors = tmp_color;
}

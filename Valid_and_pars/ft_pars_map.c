/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:45:32 by snino             #+#    #+#             */
/*   Updated: 2022/09/25 12:49:30 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	ft_pars_line_color(t_game *game, char *line)
{
	while (line && *line)
	{
		if (ft_strchr(line, ' '))
		{
			ft_lstadd_back(&game->color_list, ft_lstnew(ft_strcdup(line, ' ')));
			line = ft_strchr(line, ' ');
			while (*line == ' ')
				line++;
		}
		else if (!ft_strchr(line, ' ') && ft_strchr(line, ','))
		{
			ft_lstadd_back(&game->color_list, ft_lstnew(ft_strcdup(line, ',')));
			line = ft_strchr(line, ',');
			while (*line == ',')
				line++;
		}
		else
		{
			ft_lstadd_back(&game->color_list, \
						ft_lstnew(ft_strcdup(line, '\n')));
			ft_lstlast(game->color_list)->flag = 1;
			line = NULL;
		}
	}
}

static void	ft_pars_color(t_game *game, char *line)
{
	if (*line == '\n' && game->color == 0)
		;
	else if (ft_strnstr(line, "F ", 2) || ft_strnstr(line, "C ", 2))
	{
		ft_pars_line_color(game, line);
		game->color++;
	}
	else if (game->color < 2)
		ft_exit_game(game, "Error\nINVALID_COLOR_IDENTIFIER", EXIT_FAILURE);
}

static void	ft_pars_line_type(t_game *game, char *line)
{
	while (line && *line)
	{
		if (ft_strchr(line, ' '))
		{
			ft_lstadd_back(&game->type_list, ft_lstnew(ft_strcdup(line, ' ')));
			line = ft_strchr(line, ' ');
			while (*line == ' ')
				line++;
		}
		else
		{
			ft_lstadd_back(&game->type_list, ft_lstnew(ft_strcdup(line, '\n')));
			ft_lstlast(game->type_list)->flag = 1;
			line = NULL;
		}
	}
}

static void	ft_pars_type(t_game *game, char *line)
{
	if (*line == '\n' && game->type == 0)
		;
	else if (ft_strnstr(line, "NO ", 3) || ft_strnstr(line, "SO ", 3) \
		|| ft_strnstr(line, "WE ", 3) || ft_strnstr(line, "EA ", 3))
	{
		ft_pars_line_type(game, line);
		game->type++;
	}
	else if (game->type < 4)
		ft_exit_game(game, "Error\nINVALID_TYPE_IDENTIFIER", EXIT_FAILURE);
}

void	ft_pars_map(t_game *game, char *line)
{
	if (line && *line && game->type < 4)
		ft_pars_type(game, line);
	else if (line && *line && game->type == 4 && game->color < 2)
		ft_pars_color(game, line);
	else if (line && *line && game->type == 4 && game->color == 2)
		ft_pars_map_list(game, line);
	else
		ft_exit_game(game, "Error\nINVALID_MAP_FILE", EXIT_FAILURE);
}

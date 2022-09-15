/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pars_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:20:26 by snino             #+#    #+#             */
/*   Updated: 2022/09/15 16:46:29 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_pars(t_game *game, char *line)
{
	int	sp;

	sp = 0;
	while (line && *line)
	{
		if (ft_strchr(line, ' '))
		{
			ft_lstadd_back(&game->map_list, ft_lstnew(ft_strcdup(line, ' ')));
			line = ft_strchr(line, ' ');
			while (*line == ' ')
			{
				sp++;
				line++;
			}
			ft_lstlast(game->map_list)->space = sp;
		}
		else
		{
			ft_lstadd_back(&game->map_list, ft_lstnew(ft_strcdup(line, '\n')));
			ft_lstlast(game->map_list)->flag = 1;
			line = NULL;
		}
	}
}

void	ft_pars_map_list(t_game *game, char *line)
{
	if (*line == '\n' && game->enter == 0)
		;
	else if (*line == '\n' && game->enter != 0)
		ft_error_handler(game, "Error\nINVALID_MAP", leave);
	else
	{
		ft_pars(game, line);
		game->enter++;
	}
}

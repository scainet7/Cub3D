/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:45:32 by snino             #+#    #+#             */
/*   Updated: 2022/09/13 21:23:56 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_pars_map(t_game *game, char *line)
{
	char	*buff;
	int		len;

	game->map_list = NULL;
	buff = NULL;
	while (line && *line)
	{
		if (ft_strchr(line, ' '))
		{
			buff = ft_getword_mod(line, ' ');
			ft_lstadd_back(&game->map_list, ft_lstnew(ft_strdup(buff)));
			len = ft_strlen(buff) + 2;
			line = &line[len];
			free(buff);
		}
		else if (!ft_strchr(line, ' '))
		{
			buff = ft_getword_mod(line, '\n');
			ft_lstadd_back(&game->map_list, ft_lstnew(ft_strdup(buff)));
			free(buff);
			ft_lstlast(game->map_list)->flag = 1;
			line = NULL;
		}
	}
}

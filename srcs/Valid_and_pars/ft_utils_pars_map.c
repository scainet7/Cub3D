/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pars_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:20:26 by snino             #+#    #+#             */
/*   Updated: 2022/10/29 14:43:54 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

t_map	*ft_line_new(void *line)
{
	t_map	*new_map;

	new_map = (t_map *)malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->maps_line = line;
	new_map->next = NULL;
	return (new_map);
}

void	ft_lineadd_back(t_map **mass, t_map *new)
{
	t_map	*last;

	if (!mass || !new)
		return ;
	last = *mass;
	if (!last)
		*mass = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

int	ft_memory_num(t_list *list)
{
	t_list	*tmp;
	int		count;

	tmp = list;
	count = 1;
	while (tmp)
	{
		if (tmp->flag == 1)
			break ;
		++count;
		tmp = tmp->next;
	}
	count++;
	return (count);
}

void	ft_pars_map_list(t_game *game, char *line)
{
	if (*line == '\n' && game->enter == 0)
		;
	else if (*line == '\n' && game->enter != 0)
		ft_exit_game(game, "Error\nINVALID_MAP", EXIT_FAILURE);
	else
	{
		ft_lstadd_back(&game->map_list, ft_lstnew(ft_strcdup(line, '\n')));
		ft_lstlast(game->map_list)->flag = 1;
		game->enter++;
	}
}

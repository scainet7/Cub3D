/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_show.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:37:15 by snino             #+#    #+#             */
/*   Updated: 2022/09/15 14:34:20 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	show(t_list *list, char *str)
{
	char	*tmp;
	int		i;
	int		fl;
	int		sp;

	i = 0;
	printf(YEL"%s\n"END, str);
	while (list)
	{
		tmp = list->content;
		fl = list->flag;
		sp = list->space;
		printf("%d ", i);
		printf(BLU"%s "END RED"space %d "RED"flag %d "END RED"len %d \n"END, \
				tmp, sp, fl, ft_strlen(tmp));
		list = list->next;
		i++;
	}
}

void	show1(t_map *maps, char *place)
{
	t_map	*temp;
	int		i;

	temp = maps;
	printf("%s\n", place);
	while (temp)
	{
		i = -1;
		printf("SHOW:%d-> ", i + 2);
		while (temp->maps_line[++i])
			printf("'%s':%zu ", temp->maps_line[i], \
				(size_t)ft_strlen(temp->maps_line[i]));
		printf("\n");
		temp = temp->next;
	}
}

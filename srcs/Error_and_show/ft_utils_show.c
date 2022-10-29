/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_show.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:37:15 by snino             #+#    #+#             */
/*   Updated: 2022/10/29 14:43:54 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	show(t_list *list, char *str)
{
	char	*tmp;
	int		i;
	int		fl;

	i = 0;
	printf(YEL"%s\n"END, str);
	while (list)
	{
		tmp = list->content;
		fl = list->flag;
		printf("%d ", i);
		printf(BLU"%s "END RED"flag %d "END RED"len %d \n"END, \
				tmp, fl, ft_strlen(tmp));
		list = list->next;
		i++;
	}
}

void	show1(t_map *maps, char *place)
{
	t_map	*temp;
	int		i;

	temp = maps;
	printf(YEL"%s\n"END, place);
	while (temp)
	{
		i = -1;
		while (temp->maps_line[++i])
		{
			printf(" %d "BLU"%s"END, i, temp->maps_line[i]);
		}
		temp = temp->next;
	}
	printf("\n");
}

void	show2(char **maps, char *place)
{
	char	**temp;
	int		i;
	int		j;

	temp = maps;
	printf(YEL"%s\n"END, place);
	i = -1;
	j = 0;
	while (temp[++i])
	{
		printf("%d "BLU"%s\n"END, j, temp[i]);
		j++;
	}
	printf("\n");
}

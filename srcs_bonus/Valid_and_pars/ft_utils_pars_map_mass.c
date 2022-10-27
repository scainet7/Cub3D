/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pars_map_mass.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:55:45 by snino             #+#    #+#             */
/*   Updated: 2022/10/23 12:13:40 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

int	ft_memory_num1(t_list *list)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_show2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:17:03 by snino             #+#    #+#             */
/*   Updated: 2022/10/17 16:26:45 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	show_struct_game(t_game *game)
{
	printf(GRE"%d\n"END, game->type);
	printf(GRE"%d\n"END, game->color);
	printf(GRE"%d\n"END, game->enter);
	printf(GRE"%s\n"END, game->map_name);
}

//void	show_struct_pp(t_pp *player)
//{
//
//}
//
//void	show_struct_img(t_img *img)
//{
//
//}
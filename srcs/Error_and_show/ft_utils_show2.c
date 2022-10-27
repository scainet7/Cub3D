/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_show2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:17:03 by snino             #+#    #+#             */
/*   Updated: 2022/10/23 17:23:49 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	show_struct_game(t_game *game)
{
	printf(GRE"game_struckt\n"END);
	printf(GRE"%d\n"END, game->type);
	printf(GRE"%d\n"END, game->color);
	printf(GRE"%d\n"END, game->enter);
	printf(GRE"%s\n"END, game->map_name);
	printf("\n");
}

void	show_struct_pp(t_pp *player)
{
	printf(YEL"player_position_struct\n"END);
	printf(YEL"%d\n"END, player->x);
	printf(YEL"%d\n"END, player->y);
	printf(YEL"%f\n"END, player->p_x);
	printf(YEL"%f\n"END, player->p_y);
	printf(YEL"%f\n"END, player->plane_x);
	printf(YEL"%f\n"END, player->plane_y);
	printf(YEL"%f\n"END, player->dir_x);
	printf(YEL"%f\n"END, player->dir_y);
	printf("\n");
}

void	show_struct_img(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	printf(BLU"img_struct\n"END);
	printf(BLU"%d\n"END, img->endian);
	printf(BLU"%d\n"END, img->line_length);
	printf(BLU"%d\n"END, img->bits_per_pixel);
	printf(BLU"floor[%d, %d, %d]\n"END,
		img->floor[0], img->floor[1], img->floor[2]);
	printf(BLU"ceiling[%d, %d, %d]\n"END,
		img->ceiling[0], img->ceiling[1], img->ceiling[2]);
	while (i < IMG)
	{
		j = 0;
		while (j < IMG)
		{
			printf(BLU"%d\n"END, img->east_wall[i][j]);
			printf(BLU"%d\n"END, img->west_wall[i][j]);
			printf(BLU"%d\n"END, img->north_wall[i][j]);
			printf(BLU"%d\n"END, img->south_wall[i][j]);
			j++;
		}
		i++;
	}
}

void	show_struct_wall(t_wall *wall)
{
	printf(MAG"wall_struct\n"END);
	printf(MAG"%d\n"END, wall->end);
	printf(MAG"%d\n"END, wall->start);
}

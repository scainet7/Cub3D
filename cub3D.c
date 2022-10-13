/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:54:57 by snino             #+#    #+#             */
/*   Updated: 2022/10/15 21:22:51 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_data_for_textures_and_speed(t_game *game)
{
	game->s_tex = malloc(sizeof(t_win));
	game->w_tex = malloc(sizeof(t_win));
	game->e_tex = malloc(sizeof(t_win));
	game->n_tex = malloc(sizeof(t_win));
	img_to_xpm_data_my(game->win, game->img.tex_no, game->s_tex);
	img_to_xpm_data_my(game->win, game->img.tex_so, game->n_tex);
	img_to_xpm_data_my(game->win, game->img.tex_we, game->e_tex);
	img_to_xpm_data_my(game->win, game->img.tex_ea, game->w_tex);
	game->player->move_speed = MOVESPEED;
	game->player->rot_speed = ROTSPEED;
}

void ft_free_map(t_game *game)
{
	ft_freelst(game->type_list);
	ft_freelst(game->color_list);
	ft_freelst(game->map_list);
	ft_free_mass(game->types);
	ft_free_mass(game->colors);
	free(game->map);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_pp	*player;
	t_win 	*win;

	player = malloc(sizeof(t_pp));
	win = malloc(sizeof(t_win));
	game.win = win;
	game.player = player;
	ft_check_map(&game, argc, argv);
	ft_init_game(&game);
	ft_free_map(&game);
//	show(game.color_list, "color_list");
//	show(game.map_list, "map_list");
//	show1(game.types, "TUPE");
//	show1(game.colors, "COLOR");
//	show2(game.map, "MAP");
	return (0);
}

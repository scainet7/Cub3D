/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:36:51 by snino             #+#    #+#             */
/*   Updated: 2022/10/22 21:40:52 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	moving_straight(int keycode, t_game *game, double len)
{
	if (keycode == MOVE_UP)
	{
		if (wall_in_front_x(game, len) == false)
			game->player->p_x += (game->player->dir_x) / len * SPEED;
		if (wall_in_front_y(game, len) == false)
			game->player->p_y += (game->player->dir_y) / len * SPEED;
	}
	if (keycode == MOVE_DOWN)
	{
		if (wall_behind_x(game, len) == false)
			game->player->p_x += (-game->player->dir_x) / len * SPEED;
		if (wall_behind_y(game, len) == false)
			game->player->p_y += (-game->player->dir_y) / len * SPEED;
	}
}

static void	rotation_left(int keycode, t_game *game, double len)
{
	double	old_dir;
	double	old_plane;

	if (keycode == ROTATE_LEFT)
	{
		old_dir = game->player->dir_x;
		game->player->dir_x = cos(-ROTATE_SPEED) * game->player->dir_x
					  - sin(-ROTATE_SPEED) * game->player->dir_y;
		game->player->dir_y = sin(-ROTATE_SPEED) * old_dir
					  + cos(-ROTATE_SPEED) * game->player->dir_y;
		old_plane = game->player->plane_x;
		game->player->plane_x = cos(-ROTATE_SPEED) * game->player->plane_x
						- sin(-ROTATE_SPEED) * game->player->plane_y;
		game->player->plane_y = sin(-ROTATE_SPEED) * old_plane
						+ cos(-ROTATE_SPEED) * game->player->plane_y;
		game->player->dir_x /= len;
		game->player->dir_y /= len;
	}
}

static void	rotation(int keycode, t_game *game, double len)
{
	double	old_dir;
	double	old_plane;

	if (keycode == ROTATE_RIGHT)
	{
		old_dir = game->player->dir_x;
		game->player->dir_x = cos(ROTATE_SPEED) * game->player->dir_x
					  - sin(ROTATE_SPEED) * game->player->dir_y;
		game->player->dir_y = sin(ROTATE_SPEED) * old_dir
					  + cos(ROTATE_SPEED) * game->player->dir_y;
		old_plane = game->player->plane_x;
		game->player->plane_x = cos(ROTATE_SPEED) * game->player->plane_x
						- sin(ROTATE_SPEED) * game->player->plane_y;
		game->player->plane_y = sin(ROTATE_SPEED) * old_plane
						+ cos(ROTATE_SPEED) * game->player->plane_y;
		game->player->dir_x /= len;
		game->player->dir_y /= len;
	}
	rotation_left(keycode, game, len);
}

void	redrawing(t_game *game, int keycode)
{
	double	len;

	len = sqrt(game->player->dir_x * game->player->dir_x + game->player->dir_y * game->player->dir_y);
	if (keycode == ESCAPE)
		ft_exit_game(game, GRE"GOOD\n"END,EXIT_SUCCESS);
	if (keycode == MOVE_RIGHT)
	{
		if (wall_right_x(game, len) == false)
			game->player->p_x += (game->player->dir_y) / len * SPEED;
		if (wall_right_y(game, len) == false)
			game->player->p_y += (-game->player->dir_x) / len * SPEED;
	}
	if (keycode == MOVE_LEFT)
	{
		if (wall_left_x(game, len) == false)
			game->player->p_x += (-game->player->dir_y) / len * SPEED;
		if (wall_left_y(game, len) == false)
			game->player->p_y += (game->player->dir_x) / len * SPEED;
	}
	moving_straight(keycode, game, len);
	rotation(keycode, game, len);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:12:37 by snino             #+#    #+#             */
/*   Updated: 2022/10/29 14:43:54 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	key_release(int key, t_game *game)
{
	if (key == MOVE_UP)
		game->controls.up = -1;
	else if (key == MOVE_DOWN)
		game->controls.down = -1;
	else if (key == MOVE_LEFT)
		game->controls.left = -1;
	else if (key == MOVE_RIGHT)
		game->controls.right = -1;
	else if (key == ROTATE_LEFT)
		game->controls.rotate_left = -1;
	else if (key == ROTATE_RIGHT)
		game->controls.rotate_right = -1;
	else if (key == ESCAPE)
		game->controls.escape = -1;
	return (EXIT_SUCCESS);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == MOVE_UP)
		game->controls.up = MOVE_UP;
	else if (keycode == MOVE_DOWN)
		game->controls.down = MOVE_DOWN;
	else if (keycode == MOVE_LEFT)
		game->controls.left = MOVE_LEFT;
	else if (keycode == MOVE_RIGHT)
		game->controls.right = MOVE_RIGHT;
	else if (keycode == ROTATE_LEFT)
		game->controls.rotate_left = ROTATE_LEFT;
	else if (keycode == ROTATE_RIGHT)
		game->controls.rotate_right = ROTATE_RIGHT;
	else if (keycode == ESCAPE)
		game->controls.escape = ESCAPE;
	return (EXIT_SUCCESS);
}

void	check_events(t_game *game)
{
	int	*ptr;
	int	i;

	ptr = (int *)&game->controls;
	i = 0;
	while (i < 7)
	{
		if (*(ptr + i) > -1)
			redrawing(game, *(ptr + i));
		i++;
	}
}

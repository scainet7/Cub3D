/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:08:13 by snino             #+#    #+#             */
/*   Updated: 2022/10/15 19:55:50 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	img_to_xpm_data_my(t_win *win, char *path, t_win *data)
{
	data->img = mlx_xpm_file_to_image(win->mlx, path, &data->x, &data->y);
//	check_malloc_err(data->img, "couldn't alloc texture img", 21);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, \
			&data->l_len, &data->end);
//	check_malloc_err(data->addr, "couldn't alloc texture addr", 22);
}

void	my_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->l_len + x * (win->bpp / 8));
	*(unsigned int *) dst = color;
}

unsigned int	get_tex_color_pixel(t_win *img, int x, int y)
{
	int	*dst;
	int	color;

	dst = (void *)img->addr + (y * img->l_len + x * (img->bpp / 8));
	color = *(int *)dst;
	return (color);
}


void	move_player_right_left(t_game *game, int key_code, double move_speed)
{
	if (key_code == A_LEFT)
	{
		if ((game->map[(int)game->player->p_y][(int)(game->player->p_x - \
					game->player->plane_x * move_speed)]) == '0')
			game->player->p_x -= game->player->plane_x * move_speed;
		if (game->map[(int)(game->player->p_y - game->player->plane_y * \
					move_speed)][(int)game->player->p_x] == '0')
			game->player->p_y -= game->player->plane_y * move_speed;
	}
	if (key_code == D_RIGHT)
	{
		if ((game->map[(int)game->player->p_y][(int)(game->player->p_x + \
					game->player->plane_x * move_speed)]) == '0')
			game->player->p_x += game->player->plane_x * move_speed;
		if (game->map[(int)(game->player->p_y + game->player->plane_y * \
					move_speed)][(int)game->player->p_x] == '0')
			game->player->p_y += game->player->plane_y * move_speed;
	}
}

void	move_player_up_down(t_game *game, int key_code, double move_speed)
{
	if (key_code == W_UP || key_code == UP)
	{
		if (game->map[(int)game->player->p_y][(int)(game->player->p_x + \
					game->player->dir_x * move_speed)] == '0')
			game->player->p_x += game->player->dir_x * move_speed;
		if (game->map[(int)(game->player->p_y + game->player->dir_y * \
					move_speed)][(int)game->player->p_x] == '0')
			game->player->p_y += game->player->dir_y * move_speed;
	}
	if (key_code == S_DOWN || key_code == DOWN)
	{
		if (game->map[(int)game->player->p_y][(int)(game->player->p_x - \
				game->player->dir_x * move_speed)] == '0')
			game->player->p_x -= game->player->dir_x * move_speed;
		if (game->map[(int)(game->player->p_y - game->player->dir_y * \
				move_speed)][(int)game->player->p_x] == '0')
			game->player->p_y -= game->player->dir_y * move_speed;
	}
}

void	rotate_player_view(t_game *game, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player->dir_x;
	game->player->dir_x = game->player->dir_x * cos(rot_speed)
						 - game->player->dir_y * sin(rot_speed);
	game->player->dir_y = old_dir_x * sin(rot_speed)
						 + game->player->dir_y * cos(rot_speed);
	old_plane_x = game->player->plane_x;
	game->player->plane_x = game->player->plane_x * cos(rot_speed)
						  - game->player->plane_y * sin(rot_speed);
	game->player->plane_y = old_plane_x * sin(rot_speed)
						  + game->player->plane_y * cos(rot_speed);
}

int	close_win(t_game *game)
{
//	free_memory(game);
	mlx_destroy_image(game->win->mlx, game->win->img);
	mlx_destroy_window(game->win->mlx, game->win->win);
	free(game->win->win);
	printf("Game finished!\n");
	exit(0);
}

int	key_hook(int key_code, t_game *game)
{
	if (key_code == ESC)
		close_win(game);
	if (key_code == W_UP || key_code == S_DOWN
		|| key_code == UP || key_code == DOWN)
		move_player_up_down(game, key_code, game->player->move_speed);
	if (key_code == A_LEFT || key_code == D_RIGHT)
		move_player_right_left(game, key_code, game->player->move_speed);
	if (key_code == RIGHT)
		rotate_player_view(game, -game->player->rot_speed);
	if (key_code == LEFT)
		rotate_player_view(game, game->player->rot_speed);
	ft_raycast(game);
	mlx_put_image_to_window(game->win->mlx, game->win->win, game->win->img, 0, 0);
	return (0);
}
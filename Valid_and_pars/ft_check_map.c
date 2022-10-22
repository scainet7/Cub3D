/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:16:28 by snino             #+#    #+#             */
/*   Updated: 2022/09/24 20:18:30 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	ft_read_map(t_game *game)
{
	char	*line_map;
	int		fd;

	fd = open(game->map_name, O_RDONLY);
	if (fd < 0)
		ft_exit_game(game, "Error\nNO_MAP_FILE", EXIT_FAILURE);
	game->map_list = NULL;
	game->type_list = NULL;
	game->color_list = NULL;
	line_map = NULL;
	game->type = 0;
	game->color = 0;
	game->enter = 0;
	while (1)
	{
		line_map = get_next_line(fd);
		if (!line_map)
		{
			free(line_map);
			break ;
		}
		ft_pars_map(game, line_map);
		free(line_map);
	}
	close(fd);
}

static void	ft_check_name_map(t_game *game, int argc, char **argv)
{
	size_t res;
	char *serch;

	serch = ".cub";
	if (argc == 2)
	{
		res = ft_strlen(ft_strchr(argv[1], serch[0]));
		if (!ft_strstr(argv[1], serch))
			ft_exit_game(game, "Error\nINVALID_NUM_ARGUMENTS", EXIT_FAILURE);
		if (res != 4)
			ft_exit_game(game, "Error\nINVALID_MAP_EXTENSION", EXIT_FAILURE);
		else
			game->map_name = argv[1];
	}
	else if (argc < 2)
		ft_exit_game(game, "Error\nNO_MAP", EXIT_FAILURE);
}

void	ft_check_map(t_game *game, int argc, char **argv)
{
	ft_check_name_map(game, argc, argv);
	ft_read_map(game);
	ft_pars_type_mass(game);
	ft_check_type_mass(game);
	ft_pars_color_mass(game);
	ft_check_color_mass(game);
	ft_pars_map_mass(game);
	ft_check_map_mass(game);
}

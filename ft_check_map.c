/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:16:28 by snino             #+#    #+#             */
/*   Updated: 2022/09/15 16:42:28 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_read_map(t_game *game)
{
	char	*line_map;
	int		fd;

	fd = open(game->map_name, O_RDONLY);
	if (fd < 0)
		ft_error_handler(game, "Error\nNO_MAP_FILE", mlx);
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

static int	ft_name_map(char *argv)
{
	size_t	res;
	char	*serch;

	serch = ".cub";
	res = ft_strlen(ft_strchr(argv, serch[0]));
	if (!ft_strstr(argv, serch) || res != 4)
		return (1);
	else
		return (0);
}

static void	ft_check_name_map(t_game *game, int argc, char **argv)
{
	if (argc == 2 && !(ft_name_map(argv[1])))
		game->map_name = argv[1];
	else if (argc < 2)
		ft_error_handler(game, "Error\nNO_MAP", leave);
	else
	{
		if (ft_name_map(argv[1]))
			ft_error_handler(game, "Error\nINVALID_MAP_EXTENSION", leave);
		else
			ft_error_handler(game, "Error\nINVALID_NUM_ARGUMENTS", leave);
	}
}

void	ft_check_map(t_game *game, int argc, char **argv)
{
	ft_check_name_map(game, argc, argv);
	ft_read_map(game);
	printf(GRE"GOOD\n"END);
}

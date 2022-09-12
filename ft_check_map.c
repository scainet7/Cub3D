/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:16:28 by snino             #+#    #+#             */
/*   Updated: 2022/09/12 18:03:59 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_refactor_map(t_game *game, int len)
{
	int		i;
	t_list	*tmp;

	tmp = game->map_list;
	i = -1;
	game->map = (char **)malloc(sizeof (char *) * len);
	if (!game->map)
		ft_error_handler(game, "Error\nMALLOC", leave);
	while (tmp)
	{
		game->map[++i] = tmp->content;
		tmp = tmp->next;
	}
}

static void	ft_read_map(t_game *game)
{
	char	*line_map;
	int		fd;

	fd = open(game->map_name, O_RDONLY);
	if (fd < 0)
		ft_error_handler(game, "Error\nNO_MAP_IN_FILE", mlx);
	line_map = NULL;
	game->map_list= NULL;
	while(1)
	{
		line_map = get_next_line(fd);
		if (!line_map)
		{
			free(line_map);
			break ;
		}
		ft_lstadd_back(&game->map_list, ft_lstnew(ft_strdup(line_map)));
		free(line_map);
	}
	close(fd);
	ft_refactor_map(game, ft_lstsize(game->map_list));
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

void	ft_SHOW_map(t_game *game)
{
	int i;

	i = -1;
	while (game->map[++i])
		ft_putstr_fd(game->map[i], 1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:16:28 by snino             #+#    #+#             */
/*   Updated: 2022/09/04 17:57:59 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

static void	ft_check_name(t_game *game, int argc, char **argv)
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
	ft_check_name(game, argc, argv);
	printf(GRE"GOOD\n"END);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:27:45 by snino             #+#    #+#             */
/*   Updated: 2022/10/15 18:27:45 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	add_shade(double distance, int color)
{
	int		transparency;
	int		red;
	int		green;
	int		blue;

	transparency = color & 0xFF000000;
	red = color & 0x00FF0000;
	green = color & 0x0000FF00;
	blue = color & 0x000000FF;
	red = (red >> 16) * (1 - distance);
	green = (green >> 8) * (1 - distance);
	blue = blue * (1 - distance);
	red = red << 16;
	green = green << 8;
	return (transparency | red | green | blue);
}

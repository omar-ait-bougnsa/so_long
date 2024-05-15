/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imags_in_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:23:30 by oait-bou          #+#    #+#             */
/*   Updated: 2024/03/26 11:23:33 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	position_of_imag(t_imag *imag, int y, int x)
{
	if (imag->av[y][x] == '1')
		mlx_put_image_to_window(imag->mlx, imag->win, imag->wall, x * 50, y
			* 50);
	else
		mlx_put_image_to_window(imag->mlx, imag->win, imag->floor, x * 50, y
			* 50);
	if (imag->av[y][x] == 'C')
		mlx_put_image_to_window(imag->mlx, imag->win, imag->collectible, x * 50,
			y * 50);
	else if (imag->av[y][x] == 'E')
		mlx_put_image_to_window(imag->mlx, imag->win, imag->door, x * 50, y
			* 50);
	else if (imag->av[y][x] == 'P')
		mlx_put_image_to_window(imag->mlx, imag->win, imag->player, x * 50, y
			* 50);
	else if (imag->av[y][x] == 'X')
		mlx_put_image_to_window(imag->mlx, imag->win, imag->animation, x * 50, y
			* 50);
}

void	put_imags_in_window(t_imag *imag)
{
	int	y;
	int	x;

	y = 0;
	draw_map(imag);
	while (imag->av[y])
	{
		x = 0;
		while (imag->av[y][x])
		{
			position_of_imag(imag, y, x);
			x++;
		}
		y++;
	}
}

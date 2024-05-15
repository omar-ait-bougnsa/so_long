/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:09:47 by oait-bou          #+#    #+#             */
/*   Updated: 2024/03/26 11:09:49 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_right(t_imag *imag)
{
	imag->y = 0;
	while (imag->av[imag->y])
	{
		imag->x = 0;
		while (imag->av[imag->y][imag->x + 1])
		{
			if (imag->av[imag->y][imag->x] == 'P' && imag->av[imag->y][imag->x
				+ 1] == 'E' && imag->exit == 1)
				destroy_window(imag);
			if (imag->av[imag->y][imag->x] == 'P' && imag->av[imag->y][imag->x
				+ 1] == 'X')
				destroy_window(imag);
			if (imag->av[imag->y][imag->x] == 'P' && imag->av[imag->y][imag->x
				+ 1] != '1' && imag->av[imag->y][imag->x + 1] != 'E')
			{
				imag->mov++;
				imag->av[imag->y][imag->x] = '0';
				imag->av[imag->y][imag->x + 1] = 'P';
				return ;
			}
			imag->x++;
		}
		imag->y++;
	}
}

void	ft_left(t_imag *imag)
{
	imag->y = 0;
	while (imag->av[imag->y])
	{
		imag->x = 0;
		while (imag->av[imag->y][imag->x])
		{
			if (imag->av[imag->y][imag->x] == 'P' && imag->av[imag->y][imag->x
				- 1] == 'E' && imag->exit == 1)
				destroy_window(imag);
			if (imag->av[imag->y][imag->x] == 'P' && imag->av[imag->y][imag->x
				- 1] == 'X')
				destroy_window(imag);
			if (imag->av[imag->y][imag->x] == 'P' && imag->av[imag->y][imag->x
				- 1] != '1' && imag->av[imag->y][imag->x - 1] != 'E')
			{
				imag->mov++;
				imag->av[imag->y][imag->x] = '0';
				imag->av[imag->y][imag->x - 1] = 'P';
				return ;
			}
			imag->x++;
		}
		imag->y++;
	}
}

void	ft_up(t_imag *imag)
{
	imag->y = 1;
	while (imag->av[imag->y])
	{
		imag->x = 0;
		while (imag->av[imag->y][imag->x])
		{
			if (imag->av[imag->y][imag->x] == 'P' && imag->av[imag->y
				- 1][imag->x] == 'E' && imag->exit == 1)
				destroy_window(imag);
			if (imag->av[imag->y][imag->x] == 'P' && imag->av[imag->y
				- 1][imag->x] == 'X')
				destroy_window(imag);
			if (imag->av[imag->y][imag->x] == 'P' && imag->av[imag->y
				- 1][imag->x] != '1' && imag->av[imag->y - 1][imag->x] != 'E')
			{
				imag->mov++;
				imag->av[imag->y][imag->x] = '0';
				imag->av[imag->y - 1][imag->x] = 'P';
				return ;
			}
			imag->x++;
		}
		imag->y++;
	}
}

void	ft_down(t_imag *imag)
{
	imag->y = 0;
	while (imag->av[imag->y])
	{
		imag->x = 0;
		while (imag->av[imag->y][imag->x])
		{
			if (imag->av[imag->y][imag->x] == 'P' && imag->av[imag->y
				+ 1][imag->x] == 'E' && imag->exit == 1)
				destroy_window(imag);
			if (imag->av[imag->y][imag->x] == 'P' && imag->av[imag->y
				+ 1][imag->x] == 'X')
				destroy_window(imag);
			if (imag->av[imag->y][imag->x] == 'P' && imag->av[imag->y
				+ 1][imag->x] != '1' && imag->av[imag->y + 1][imag->x] != 'E')
			{
				imag->mov++;
				imag->av[imag->y][imag->x] = '0';
				imag->av[imag->y + 1][imag->x] = 'P';
				return ;
			}
			imag->x++;
		}
		imag->y++;
	}
}

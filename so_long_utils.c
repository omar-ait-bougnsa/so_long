/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:08:55 by oait-bou          #+#    #+#             */
/*   Updated: 2024/03/26 11:08:57 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_len_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

void	check_exit(t_imag *imag)
{
	int	i;
	int	j;

	i = 0;
	while (imag->av[i])
	{
		j = 0;
		while (imag->av[i][j])
		{
			if (imag->av[i][j] == 'C')
			{
				imag->exit = 0;
				return ;
			}
			j++;
		}
		i++;
	}
	imag->exit = 1;
}

void	destroy_window(t_imag *imag)
{
	int	i;

	i = 0;
	while (imag->av[i])
	{
		free(imag->av[i]);
		i++;
	}
	free(imag->av);
	mlx_destroy_window(imag->mlx, imag->win);
	exit(0);
}

void	ft_print_mov(t_imag *imag)
{
	char	*str;

	ft_putstr("\nmovement = ");
	str = ft_itoa(imag->mov);
	ft_putstr(str);
	free(str);
}

int	check_wehere_move(int key, t_imag *imag)
{
	if (key == 2)
	{
		imag->left_and_right = 0;
		imag->mov_player++;
		ft_right(imag);
	}
	else if (key == 0)
	{
		imag->left_and_right = 1;
		ft_left(imag);
		imag->mov_player++;
	}
	else if (key == 13)
		ft_up(imag);
	else if (key == 1)
		ft_down(imag);
	else if (key == 53)
		destroy_window(imag);
	ft_print_mov(imag);
	if (imag->mov_player == 3)
		imag->mov_player = 0;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:24:27 by oait-bou          #+#    #+#             */
/*   Updated: 2024/03/26 11:24:30 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	run(t_imag *imag)
{
	char	*str;

	mlx_clear_window(imag->mlx, imag->win);
	put_imags_in_window(imag);
	str = ft_itoa(imag->mov);
	mlx_string_put(imag->mlx, imag->win, 30, 10, 0xFF0000, "movement = ");
	mlx_string_put(imag->mlx, imag->win, 140, 10, 0xFF0000, str);
	free(str);
	imag->mov_collectible++;
	imag->mov_animation++;
	if (imag->mov_animation == 240)
		imag->mov_animation = 0;
	if (imag->mov_collectible == 50)
		imag->mov_collectible = 0;
	return (0);
}

int	ft_close(t_imag *imag)
{
	destroy_window(imag);
	return (0);
}

int	main(int ac, char **av)
{
	t_var	map;
	t_imag	imag;

	ft_memset(&imag, 0, sizeof(imag));
	if (ac != 2)
	{
		ft_putstr("Error number of parameters is not 2\n");
		return (0);
	}
	map.b = ft_strlen(av[1]) - 4;
	if (ft_memcmp(".ber", &av[1][map.b], 5) != 0)
	{
		ft_putstr("Error map with .ber\n");
		return (0);
	}
	check_map(av);
	imag.av = read_map(&map, av);
	imag.mlx = mlx_init();
	check_imag(imag);
	imag.win = mlx_new_window(imag.mlx, map.x * 50, map.y * 50, "./so_long");
	put_imags_in_window(&imag);
	mlx_hook(imag.win, 2, 0, check_wehere_move, &imag);
	mlx_hook(imag.win, 17, 0, ft_close, &imag);
	mlx_loop_hook(imag.mlx, run, &imag);
	mlx_loop(imag.mlx);
}

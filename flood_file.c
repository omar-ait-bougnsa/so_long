/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:07:56 by oait-bou          #+#    #+#             */
/*   Updated: 2024/03/26 11:07:58 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_position_player(t_var *lenth, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				lenth->x = j;
				lenth->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	check_map_is_closed(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				ft_putstr("Error\nthe path is invalide");
				free_av_exit(map);
			}
			j++;
		}
		i++;
	}
}

void	flood(t_var lenth, int x, int y, char **map)
{
	if (x < 0 || y < 0 || x >= lenth.b || y >= lenth.a || (map[y][x] != 'P'
		&& map[y][x] != '0' && map[y][x] != 'C'))
		return ;
	map[y][x] = 'A';
	flood(lenth, x - 1, y, map);
	flood(lenth, x + 1, y, map);
	flood(lenth, x, y - 1, map);
	flood(lenth, x, y + 1, map);
}

void	flood1(t_var lenth, int x, int y, char **map)
{
	if (x < 0 || y < 0 || x >= lenth.b || y >= lenth.b || (map[y][x] != 'A'
		&& map[y][x] != 'E'))
		return ;
	map[y][x] = 'f';
	flood1(lenth, x - 1, y, map);
	flood1(lenth, x + 1, y, map);
	flood1(lenth, x, y - 1, map);
	flood1(lenth, x, y + 1, map);
}

void	flood_file(char **map)
{
	t_var	lenth;

	lenth.a = ft_len_av(map);
	lenth.b = ft_strlen(map[0]);
	ft_position_player(&lenth, map);
	flood(lenth, lenth.x, lenth.y, map);
	flood1(lenth, lenth.x, lenth.y, map);
	check_map_is_closed(map);
}

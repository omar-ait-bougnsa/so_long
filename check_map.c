/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:07:36 by oait-bou          #+#    #+#             */
/*   Updated: 2024/03/26 11:07:39 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_char(char **map, char *str)
{
	int	i;
	int	b;

	i = 0;
	while (str[i])
	{
		b = 0;
		if (str[i] == '1' || str[i] == '0' || str[i] == 'P')
			b = 1;
		else if (str[i] == 'X' || str[i] == 'C' || str[i] == 'E')
			b = 1;
		else if (str[i] == '\n' && str[i + 1] != '\n')
			b = 1;
		if (b == 0)
		{
			ft_putstr("Error\nbroblem characters");
			free(str);
			free_av_exit(map);
		}
		i++;
	}
	free(str);
}

int	check_p_e_c(char **map, t_var len)
{
	ft_memset(&len, 0, sizeof(t_var));
	while (map[len.i])
	{
		len.j = 0;
		while (map[len.i][len.j])
		{
			if (map[len.i][len.j] == 'E')
				len.a += 1;
			else if (map[len.i][len.j] == 'P')
				len.b += 1;
			else if (map[len.i][len.j] == 'C')
				len.c += 1;
			len.j++;
		}
		len.i++;
	}
	if (len.a != 1 || len.b != 1 || len.c == 0)
	{
		ft_putstr("Error\nproblem player/exit or collectible");
		free_av_exit(map);
	}
	return (0);
}

int	check_wall(char **map, t_var var)
{
	var.x = ft_strlen(map[0]) - 1;
	var.y = ft_len_av(map) - 1;
	var.i = 0;
	while (map[0][var.i])
	{
		if (map[0][var.i] != '1')
			return (1);
		var.i++;
	}
	var.i = 0;
	while (var.i < var.y)
	{
		if (map[var.i][0] != '1' || map[var.i][var.x] != '1')
			return (1);
		var.i++;
	}
	var.i = 0;
	while (map[var.y][var.i])
	{
		if (map[var.y][var.i] != '1')
			return (1);
		var.i++;
	}
	return (0);
}

void	check_valid(char **map, char *str)
{
	t_var	var;

	var.len = ft_strlen(map[0]);
	var.i = 0;
	while (map[var.i])
	{
		if (ft_strlen(map[var.i]) != var.len)
		{
			ft_putstr("Error\nmap not rectangular");
			free_av_exit(map);
		}
		var.i++;
	}
	check_char(map, str);
	check_p_e_c(map, var);
	if (check_wall(map, var) == 1)
	{
		ft_putstr("Error\nmap not closed by walls");
		free_av_exit(map);
	}
	flood_file(map);
	free_av(map);
}

void	check_map(char **av)
{
	char	*str;
	int		fd;
	char	*p;
	char	**map;

	str = NULL;
	fd = open(av[1], O_RDWR);
	p = get_next_line(fd);
	if (p == NULL)
	{
		ft_putstr("Error\nmap is empty");
		exit(1);
	}
	while (p)
	{
		str = ft_strjoin(str, p);
		free(p);
		p = get_next_line(fd);
	}
	map = ft_split(str, '\n');
	check_valid(map, str);
}

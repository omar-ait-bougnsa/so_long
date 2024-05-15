/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:10:03 by oait-bou          #+#    #+#             */
/*   Updated: 2024/03/26 11:10:06 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(t_var *map, char **av)
{
	char	*str;
	int		fd;
	char	*p;

	str = NULL;
	fd = open(av[1], O_RDWR);
	p = get_next_line(fd);
	while (p)
	{
		str = ft_strjoin(str, p);
		free(p);
		p = get_next_line(fd);
	}
	av = ft_split(str, '\n');
	free(str);
	map->y = ft_len_av(av);
	map->x = ft_strlen(av[0]);
	return (av);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:08:18 by oait-bou          #+#    #+#             */
/*   Updated: 2024/03/26 11:08:20 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;

	j = 0;
	i = 0;
	if (s1 == NULL)
	{
		p = malloc(ft_strlen(s2) + 1);
		ft_strcpy(p, s2);
		return (p);
	}
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (p == NULL)
		return (0);
	while (s1[j])
		p[i++] = s1[j++];
	j = 0;
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	free(s1);
	return (p);
}

static int	ft_len(long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	else if (nb == 0)
		i++;
	while (nb >= 1)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	int		i;
	char	*p;
	long	b;

	b = nb;
	i = ft_len(b);
	p = malloc(i + 1);
	if (p == NULL)
		return (0);
	p[i] = '\0';
	if (b < 0)
	{
		p[0] = '-';
		b *= (-1);
	}
	if (b == 0)
		p[i - 1] = 48;
	while (b > 0)
	{
		p[i - 1] = (b % 10) + '0';
		i--;
		b /= 10;
	}
	return (p);
}

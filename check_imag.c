/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_imag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:39:13 by oait-bou          #+#    #+#             */
/*   Updated: 2024/03/30 17:39:17 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	call_file_to_imag(t_imag imag, char *imag1)
{
	imag.imag = mlx_xpm_file_to_image(imag.mlx, imag1, &imag.witdh,
			&imag.height);
	if (imag.imag == NULL)
		return (0);
	return (1);
}

void	check_animation(t_imag imag, int *i)
{
	if (!(call_file_to_imag(imag, "image/animation.xpm")))
		*i = 1;
	if (!(call_file_to_imag(imag, "image/animation1.xpm")))
		*i = 1;
	if (!(call_file_to_imag(imag, "image/animation2.xpm")))
		*i = 1;
	if (!(call_file_to_imag(imag, "image/animation3.xpm")))
		*i = 1;
	if (!(call_file_to_imag(imag, "image/animation22.xpm")))
		*i = 1;
	if (!(call_file_to_imag(imag, "image/animation44.xpm")))
		*i = 1;
	if (!(call_file_to_imag(imag, "image/animation55.xpm")))
		*i = 1;
	if (!(call_file_to_imag(imag, "image/animation66.xpm")))
		*i = 1;
}

void	check_playr(t_imag imag, int *i)
{
	if (!call_file_to_imag(imag, "./image/player1.xpm"))
		*i = 1;
	if (!call_file_to_imag(imag, "./image/player0.xpm"))
		*i = 1;
	if (!call_file_to_imag(imag, "./image/player2.xpm"))
		*i = 1;
	if (!call_file_to_imag(imag, "./image/player11.xpm"))
		*i = 1;
	if (!call_file_to_imag(imag, "./image/player00.xpm"))
		*i = 1;
	if (!call_file_to_imag(imag, "./image/player2_1.xpm"))
		*i = 1;
}

void	check_collectible(t_imag imag, int *i)
{
	if (!(call_file_to_imag(imag, "./image/Idle_6.xpm")))
		*i = 1;
	if (!(call_file_to_imag(imag, "./image/Idle_5.xpm")))
		*i = 1;
	if (!(call_file_to_imag(imag, "./image/Idle_4.xpm")))
		*i = 1;
	if (!(call_file_to_imag(imag, "./image/Idle_3.xpm")))
		*i = 1;
	if (!(call_file_to_imag(imag, "./image/Idle_2.xpm")))
		*i = 1;
	if (!(call_file_to_imag(imag, "./image/player2_1.xpm")))
		*i = 1;
}

void	check_imag(t_imag imag)
{
	int	i;

	i = 0;
	check_playr(imag, &i);
	check_animation(imag, &i);
	if (!(call_file_to_imag(imag, "./image/door1.xpm")))
		i = 1;
	if (!(call_file_to_imag(imag, "./image/door2.xpm")))
		i = 1;
	if (!(call_file_to_imag(imag, "./image/door3.xpm")))
		i = 1;
	if (!(call_file_to_imag(imag, "./image/door.xpm")))
		i = 1;
	if (!(call_file_to_imag(imag, "./image/imag1.xpm")))
		i = 1;
	if (!(call_file_to_imag(imag, "./image/image.xpm")))
		i = 1;
	if (i == 1)
	{
		ft_putstr("Error in image\n");
		free_av(imag.av);
		exit(1);
	}
}

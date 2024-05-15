/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:09:12 by oait-bou          #+#    #+#             */
/*   Updated: 2024/03/26 11:09:14 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player(t_imag *imag)
{
	if (imag->left_and_right == 0)
	{
		imag->path = "./image/player1.xpm";
		if (imag->mov_player == 1)
			imag->path = "./image/player0.xpm";
		else if (imag->mov_player == 2)
			imag->path = "./image/player2.xpm";
	}
	else if (imag->left_and_right == 1)
	{
		imag->path = "./image/player11.xpm";
		if (imag->mov_player == 1)
			imag->path = "./image/player00.xpm";
		else if (imag->mov_player == 2)
			imag->path = "./image/player2_1.xpm";
	}
	imag->player = mlx_xpm_file_to_image(imag->mlx, imag->path, &(imag->witdh),
			&(imag->height));
}

void	animation(t_imag *imag)
{
	imag->path = "image/animation.xpm";
	if (imag->mov_animation <= 40)
		imag->path = "image/animation1.xpm";
	else if (imag->mov_animation <= 80)
		imag->path = "image/animation2.xpm";
	else if (imag->mov_animation <= 120)
		imag->path = "image/animation3.xpm";
	else if (imag->mov_animation <= 160)
		imag->path = "image/animation22.xpm";
	else if (imag->mov_animation <= 200)
		imag->path = "image/animation44.xpm";
	else if (imag->mov_animation <= 240)
		imag->path = "image/animation55.xpm";
	else if (imag->mov_animation <= 280)
		imag->path = "image/animation66.xpm";
	imag->animation = mlx_xpm_file_to_image(imag->mlx, imag->path,
			&(imag->witdh), &(imag->height));
}

void	door(t_imag *imag)
{
	check_exit(imag);
	if (imag->exit == 1)
	{
		imag->mov_door++;
		if (imag->mov_door <= 10)
			imag->path = "./image/door1.xpm";
		else if (imag->mov_door <= 20)
			imag->path = "./image/door2.xpm";
		else
			imag->path = "./image/door3.xpm";
	}
	else
		imag->path = "./image/door.xpm";
	imag->door = mlx_xpm_file_to_image(imag->mlx, imag->path, &(imag->witdh),
			&(imag->height));
}

void	collectible(t_imag *imag)
{
	if (imag->mov_collectible <= 10)
		imag->path = "./image/Idle_6.xpm";
	else if (imag->mov_collectible <= 20)
		imag->path = "./image/Idle_5.xpm";
	else if (imag->mov_collectible <= 30)
		imag->path = "./image/Idle_4.xpm";
	else if (imag->mov_collectible <= 40)
		imag->path = "./image/Idle_3.xpm";
	else if (imag->mov_collectible <= 50)
		imag->path = "./image/Idle_2.xpm";
	imag->collectible = mlx_xpm_file_to_image(imag->mlx, imag->path,
			&(imag->witdh), &(imag->height));
}

void	draw_map(t_imag *imag)
{
	collectible(imag);
	door(imag);
	player(imag);
	animation(imag);
	imag->wall = mlx_xpm_file_to_image(imag->mlx, "./image/imag1.xpm",
			&(imag->height), &(imag->witdh));
	imag->floor = mlx_xpm_file_to_image(imag->mlx, "./image/image.xpm",
			&(imag->height), &(imag->witdh));
}

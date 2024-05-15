/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:39:29 by oait-bou          #+#    #+#             */
/*   Updated: 2024/03/26 11:39:33 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct t_var
{
	int		a;
	int		b;
	int		c;
	int		d;
	int		x;
	int		y;
	int		i;
	int		j;
	int		len;

}			t_var;

typedef struct t_imag
{
	void	*wall;
	void	*player;
	void	*collectible;
	void	*floor;
	void	*door;
	void	*imag;
	void	*animation;
	char	*path;
	char	*path_door;
	int		mov_door;
	void	*mlx;
	void	*win;
	int		exit;
	int		mov;
	char	**av;
	int		left_and_right;
	int		height;
	int		witdh;
	int		mov_collectible;
	int		mov_exit;
	int		mov_animation;
	int		left_animation;
	int		mov_player;
	int		y;
	int		x;
}			t_imag;
char		*ft_itoa(int nb);
void		check_exit(t_imag *imag);
int			ft_strlen(const char *str);
char		*get_next_line(int fd);
int			check_line(char *str);
char		*ft_line(char *str);
char		*ft_strjoin1(char *s1, char *s2);
char		*ft_strjoin(char *s1, char *s2);
void		*ft_memcpy(void *dest, const void *src, size_t size);
char		**ft_split(char const *s, char c);
void		flood_file(char **map);
int			ft_len_av(char **map);
void		put_imags_in_window(t_imag *imag);
char		**read_map(t_var *map, char **av);
void		ft_position_player(t_var *lenth, char **map);
void		check_map(char **map);
void		check_imag(t_imag imag);
void		ft_right(t_imag *imag);
void		ft_left(t_imag *imag);
void		ft_up(t_imag *imag);
void		ft_down(t_imag *imag);
void		ft_putstr(char *s);
void		*ft_memset(void *ptr, int c, size_t s);
void		free_av_exit(char **av);
void		animation(t_imag *imag);
void		destroy_window(t_imag *imag);
void		free_av(char **av);
void		*ft_memcpy(void *dest, const void *src, size_t size);
int			check_wehere_move(int key, t_imag *imag);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		draw_map(t_imag *imag);
#endif

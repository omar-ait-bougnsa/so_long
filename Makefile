name = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
mlx = -lmlx -framework OpenGL -framework AppKit 
CRS = so_long.c flood_file.c get_next_line.c get_next_line_utils.c ft_split.c read_map.c move.c check_map.c put_imags_in_window.c libift.c so_long_utils.c ft_strjoin.c draw.c check_imag.c
OBG = $(CRS:.c=.o)
all: $(name)
$(name): $(OBG)
	$(CC)   $(OBG) $(mlx) -o $(name)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBG)
fclean: clean
	rm -f $(name)
re: fclean all

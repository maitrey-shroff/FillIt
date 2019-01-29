#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_tetris
{
	t_point		***points;
	char 		**grid;
	int			t_count;
	int 		grid_size;
}				t_tetris;

//main.c
int				fillit(char *buffer);
int				shape_to_points(char *tetrimino_shape, t_tetris *tetris, int p_i);
char			*read_input_file(int fd);
int				check_input_file(char *buffer);
void			split_buffer(char *buffer, int i, char *tetrimino_shape);
t_tetris		*read_shapes(char *buffer);
int				fail(void);
int				usage(void);
int				check_shape(t_point ***points, t_tetris *t);
int				s_c(t_point ***points, int x, int y, int s_i);

#endif

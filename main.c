#include "fillit.h"


int			main(int ac, char **av)
{
	int		fd;
	char	*buffer;

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		buffer = (fd > 0 ? read_input_file(fd) : "\0");
		if (check_input_file(buffer))
			return (fillit(buffer));
		else
			return (fail());
		close(fd);
	}
	else
		return (usage());
	return (1);
}

int				fillit(char *buffer)
{
	t_tetris	*tetris;

	tetris = read_shapes(buffer);
	if (tetris == NULL)
		return (fail());
	if (check_shape(tetris->points, tetris) == -1)
		return (fail());
	return (1);
}

int			fail(void)
{
	ft_putstr("\nfail\n");
	return (-1);
}

int			usage(void)
{
	ft_putstr("usage: ./fillit input_file\n");
	return (-1);
}

t_tetris		*read_shapes(char *buffer)
{
	t_tetris	*tetris;
	char		*tetrimino_shape;
	int			i;
	int			p_i;

	p_i = 0;
	tetrimino_shape = ft_strnew(16);
	tetris = malloc(sizeof(t_tetris));
	i = 0;
	tetris->t_count = (int)((ft_strlen(buffer) + 1) / 21);
	if (tetris->t_count < 1 && tetris->t_count > 26)
		return (NULL);
	tetris->points = (t_point ***)malloc(sizeof(t_point**) * tetris->t_count);
	while (((unsigned long)i < ft_strlen(buffer)) && p_i < tetris->t_count)
	{
		tetris->points[p_i] = (t_point **)malloc(sizeof(t_point*) * 4);
		split_buffer(buffer, i, tetrimino_shape);
		if (shape_to_points(tetrimino_shape, tetris, p_i) == -1)
			return (NULL);
		i = i + 21;
		p_i++;
	}
	return (tetris);
}

int		shape_to_points(char *tetrimino_shape, t_tetris *tetris, int p_i)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (y++ < 4 && *tetrimino_shape != '\0')
	{
		x = 0;
		while (x++ < 4 && *tetrimino_shape != '\0')
		{
			if (*tetrimino_shape == '#')
			{
				tetris->points[p_i][i] = (t_point *)malloc(sizeof(t_point));
				tetris->points[p_i][i]->x = x;
				tetris->points[p_i][i]->y = y;
				i++;
			}
			tetrimino_shape++;
		}
	}
	if (i == 4)
		return (1);
	return (-1);
}

char		*read_input_file(int fd)
{
	int		r;
	char	buff[2];
	char	*temp_buffer;
	char	*buffer;

	buffer = ft_strnew(1);
	while ((r = read(fd, buff, 1)) > 0)
	{
		buff[r] = '\0';
		temp_buffer = ft_strjoin(buffer, buff);
		free(buffer);
		buffer = temp_buffer;
	}
	return (buffer);
}

int		check_input_file(char *buffer)
{
	int	nl_c;
	int	c_c;
	int	i;

	i = 0;
	nl_c = 0;
	c_c = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			nl_c++;
			if ((c_c != 4 && nl_c != 5) || (nl_c == 5 && c_c != 0) ||
			(nl_c == 5 && buffer[i + 1] == '\0'))
				return (-1);
			nl_c = (nl_c == 5 ? 0 : nl_c);
			c_c = 0;
		}
		else
			c_c++;
		i++;
	}
	return (1);
}

void		split_buffer(char *buffer, int i, char *tetrimino_shape)
{
	int		nl_c;

	nl_c = 0;
	while (buffer[i] != '\0' && nl_c != 4)
	{
		if (buffer[i] == '\n')
		{
			i++;
			nl_c++;
		}
		else
			*tetrimino_shape++ = buffer[i++];
	}
	i++;
}

int		check_shape(t_point ***p, t_tetris *t)
{
	int	s_i;
	int	c_x;
	int	c_y;
	int	connections;

	connections = 0;
	s_i = -1;
	while (++s_i < t->t_count)
	{
		connections = 0;
		c_y = -1;
		while (c_y++ <= 1)
		{
			c_x = -1;
			while (c_x++ <= 1)
			{
				if (c_x != c_y && (c_x + c_y) != 0)
					if (s_c(p, (p[s_i][i]->x) + c_x, (p[s_i][i]->y) + c_y, s_i))
						connections++;
			}
		}
		printf("%d\n", connections);
		if (connections < 6)
			return (-1);
	}
	return (1);
}

int s_c(t_point ***points, int x, int y, int s_i)
{
	int i;

	i = -1;
	while (++i <= 3)
	{
		if (points[s_i][i]->x == x && points[s_i][i]->y == y)
			return (1);
	}
	return (-1);
}

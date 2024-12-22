#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif 

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef	struct s_get
{
	char	*line;
	char	*save;
	char	*buffer;
	int	bit;
}	t_get;

char	*get_next_line(int fd);
int     ft_strlen(char *str);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strchr(char *str, int c);

#endif

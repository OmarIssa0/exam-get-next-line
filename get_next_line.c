#include "get_next_line.h"
#include <string.h>
static char *ft_line(char *save)
{
	int i = 0;
	char *str;
	while (save[i] && save[i] != '\n')
		i++;
	str = malloc(i + 2);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return str;
}

static char *ft_save(char *save)
{
	int i = 0;
	int j = 0;
	char *str;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return NULL;
	}
	str = malloc(ft_strlen(save) - i + 1);
	i++;
	while (save[i] != '\0')
		str[j++] = save[i++];
	str[j] = '\0';
	free(save);
	return str;
}

static char *ft_read_save(int fd, t_get *get)
{
	get->buffer = malloc(BUFFER_SIZE + 1);
	get->bit = 1;
	while (!ft_strchr(get->save, '\n') && get->bit != 0)
	{
		get->bit = read(fd, get->buffer, BUFFER_SIZE);
		if (get->bit == -1)
		{
			free(get->buffer);
			free(get->save);
			return NULL;
		}
		get->buffer[get->bit] = '\0';
		get->save = ft_strjoin(get->save, get->buffer);
	}
	free(get->buffer);
	return (get->save);
}

char *get_next_line(int fd)
{
	static t_get get;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// if (get.save == NULL)
	// 	get.save = strdup("");
	get.save = ft_read_save(fd, &get);
	if (!get.save)
		return (NULL);
	get.line = ft_line(get.save);
	get.save = ft_save(get.save);
	if (!get.line[0])
	{
		free(get.line);
		return NULL;
	}
	// free(get.save);
	return get.line;
}
int main ()
{
	int fd = open("txt", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)))
	{

	printf("%s", line);
	free(line);
	}
	close(fd);
}

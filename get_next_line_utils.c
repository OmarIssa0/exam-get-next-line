#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	if (!s1)
// 	{
// 		s1 = (char *)malloc(1);
// 		s1[0] = '\0';
// 	}
// 	if (!s1 || !s2)
// 		return (NULL);
// 	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!str)
// 		return (NULL);
// 	i = -1;
// 	j = 0;
// 	if (s1)
// 		while (s1[++i] != '\0')
// 			str[i] = s1[i];
// 	while (s2[j] != '\0')
// 		str[i++] = s2[j++];
// 	str[i] = '\0';
// 	free(s1);
// 	return (str);
// }
char	*ft_strjoin(char *s1, char *s2)
{
	if (s1 == NULL)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}

	if (!s1 || !s2)
		return (NULL);
	char *res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return NULL;
	int i = 0;
	int j = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while(s2[j] != '\0')
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(s1);
	return res;
}

char	*ft_strchr(char *str, int c)
{
	int i = 0;
	if (!str)
		return NULL;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str);
		i++;
	}
	return NULL;
}



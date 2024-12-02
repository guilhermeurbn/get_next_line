/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:25:13 by guisanto          #+#    #+#             */
/*   Updated: 2024/12/02 16:55:06 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	dest = ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	cc;

	cc = (char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == cc)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == '\0' && cc == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
static check_buffer(char *buffer)
{
}
char	*get_next_line(int fd)
{
	int i;

	
}


/* int main(void)
{
	int    fd;
	char  *next_line;
	int  count;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	next_line = get_next_line(fd);
	count++;
	printf("[%d]:%s\n", count, next_line); //count is to show you the line numbers
	next_line = NULL;

	close(fd);
	return (0);
} */
/* int main()
{
	int fd;
	char *line;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("error ao abrir o arquivo");
		return (1);
	}
	while((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:25:13 by guisanto          #+#    #+#             */
/*   Updated: 2024/11/29 16:01:56 by guisanto         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char		*temp;
	char		*buf;
	char		*line;
	static char	*backup;
	int			bytes_read;
	char		*new_line;
	int			len;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len = 0;
	bytes_read = 1;
	backup = NULL;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buf), NULL);
		buf[bytes_read] = '\0';
		if (backup)
		{
			temp = ft_strjoin(backup, buf);
			free(backup);
			backup = temp;
		}
		else
			backup = ft_strdup("");
		new_line = ft_strchr(backup, '\n');
		if (new_line)
		{
			len = new_line - backup + 1;
			line = ft_substr(backup, 0, len);
			temp = ft_strdup(new_line + 1);
			free(backup);
			backup = temp;
			break;
		}
		if (bytes_read == 0)
		{
			if (backup)
			{
				line = ft_strdup(backup);
				free(backup);
				backup = NULL;
			}
			break;
		}
	}
	free(buf);
	return (line);
}

int main()
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
}

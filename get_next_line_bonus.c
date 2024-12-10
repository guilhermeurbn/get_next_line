/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:20:49 by guisanto          #+#    #+#             */
/*   Updated: 2024/12/10 13:26:31 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
//This function joins two strings buffer and buf
//creates a new string with the combined content
//and frees the memory of the original buffer
//then returns the new string.
char	*ft_join_free(char *s1, char *s2)
{
	char	*s3;

	s3 = ft_strjoin(s1, s2);
	if (!s3)
		return (NULL);
	free(s1);
	return (s3);
}

// Reads from file descriptor and appends to buffer
// Returns NULL on error or if nothing was read
char	*read_file(int fd, char *buffer)
{
	char	*temp_buffer;
	int		byte_read;

	if (!buffer)
	{
		buffer = ft_calloc(1, 1);
		if (!buffer)
			return (NULL);
	}
	temp_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp_buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(buffer), free(temp_buffer), NULL);
		temp_buffer[byte_read] = '\0';
		buffer = ft_join_free(buffer, temp_buffer);
		if (!buffer || ft_strchr(temp_buffer, '\n'))
			break ;
	}
	free(temp_buffer);
	return (buffer);
}

// Extracts the current line from buffer
char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i] || !buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

// Prepares buffer for the next line
char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	next = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!next)
		return (free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i])
		next[j++] = buffer[i++];
	free(buffer);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX || read(fd, 0, 0) < 0)
	{
		if (fd >= 0 && fd < FOPEN_MAX)
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
		return (NULL);
	}
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	return (line);
}
/* int main()
{
	int fd1, fd2;
	char *line;

	fd1 = open("text1.txt", O_RDONLY);

	if (fd1 == -1)
	{
		perror("Error opening file");
		return 1;
	}
	while ((line = get_next_line(fd1)) != NULL) {
		printf("%s", line);
		free(line);
	}
	close(fd1);

	// Abrir dois arquivos para testar
	fd2 = open("text2.txt", O_RDONLY);

	if (fd2 == -1)
	{
		perror("Error opening file");
		return 1;
	}
	while ((line = get_next_line(fd2)) != NULL) {
		printf("%s", line);
		free(line);
	}
	close(fd2);
	return 0;
} */

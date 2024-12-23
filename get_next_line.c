/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:34:58 by guisanto          #+#    #+#             */
/*   Updated: 2024/12/12 13:16:55 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*next_line;
	int			bytes_read;

	next_line = NULL;
	bytes_read = 1;
	while ((fd >= 0 && BUFFER_SIZE > 0) && bytes_read > 0)
	{
		if (buffer[0])
		{
			next_line = ft_strjoin(next_line, buffer);
			if (!next_line)
				return (NULL);
			if (next_line[ft_strlen(next_line) - 1] == '\n')
				break ;
		}
		else
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read < 0)
				return (free(next_line), NULL);
			buffer[bytes_read] = '\0';
		}
	}
	return (next_line);
}
/* int main()
{
	int fd;
	char *next_line;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		perror ("error");
	while((next_line = get_next_line(fd)) != NULL )
	{
		printf("%s", next_line);
		free(next_line);
	}
	close(fd);
	return (0);
} */

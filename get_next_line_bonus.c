/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:55:59 by guisanto          #+#    #+#             */
/*   Updated: 2024/12/12 13:16:19 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*next_line;
	int			bytes_read;

	next_line = NULL;
	bytes_read = 1;
	while ((fd >= 0 && fd < FOPEN_MAX && BUFFER_SIZE > 0) && bytes_read > 0)
	{
		if (buffer[fd][0])
		{
			next_line = ft_strjoin(next_line, buffer[fd]);
			if (!next_line)
				return (NULL);
			if (next_line[ft_strlen(next_line) - 1] == '\n')
				break ;
		}
		else
		{
			bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
			if (bytes_read < 0)
				return (free(next_line), NULL);
			buffer[fd][bytes_read] = '\0';
		}
	}
	return (next_line);
}
/* int main()
{
	int fd, fd1;
	char	*next_line;
	fd = open("text.txt", O_RDONLY);
	fd1 = open("text2.txt", O_RDONLY);

	while ((next_line = get_next_line(fd)) != NULL)
	{
		printf("%s", next_line);
		free(next_line);
	}
	close (fd);
	while((next_line = get_next_line(fd1)) != NULL)
	{
		printf("%s", next_line);
		free(next_line);
	}
	close(fd1);
	return (0);
} */

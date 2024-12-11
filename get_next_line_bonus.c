/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:55:59 by guisanto          #+#    #+#             */
/*   Updated: 2024/12/11 16:33:04 by guisanto         ###   ########.fr       */
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
	while (fd >= 0 && fd < FOPEN_MAX && BUFFER_SIZE > 0 && bytes_read > 0)
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
	int fd, fd2, fd3;
	fd = open("text.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	fd3 = open("text3.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd));
} */

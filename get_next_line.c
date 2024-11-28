/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:25:13 by guisanto          #+#    #+#             */
/*   Updated: 2024/11/28 18:53:18 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static char *ft_substr(char const *s, unsigned int start, size_t len)
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
static char *ft_strchr(const char *str, int c)
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
static char function_name(int fd, char *buf, char *backup)
{
    int     read_line;
    char    *char_temp;
    
    read_line = 1;
    while(read_line)
    {
        read_line = read(fd, buf, BUFFER_SIZE);
        if (read_line == -1)
            return (0);    
        else if (read_line == 0)
            break;
        buf[read_line] == '\0';
        if(!backup)
            backup = ft_strdup("");
        char_temp = backup;
        backup = ft_strjoin(char_temp, buf);
        free(char_temp);
        char_temp == NULL;
        if (ft_strchr(buf, '\n'));
            break;
    }
    return (backup);
}
static char extract(char *line)
{
    size_t  i;
    char    *backup;

    i = 0;
    while(line[i] != '\n' || line[i])
        i++;
    if (line[i] == '\0' || line[1] == '\0')
        return (0);
    backup = ft_substr(line, i + 1, ft_strlen(line) - i);
    if (*backup == '\0')
    {
        free(backup);
        backup = NULL;
    }   
    line[i + 1] = '\0';
    return (backup)
}

char    get_next_line(int fd)
{
    char    *line;
    char    *buf;
    static char    *backup;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    if (!buf)
        return (0);
    line = function_name(fd, buf, backup);
    free(buf);
    buf == NULL;
    if (!line)
        return (NULL);
    backup = extract(line);
    return (line);   
}






/* int main()
{
    int     fd;
    char    buf[256];
    int     chars_read;
    int     i;
    
    fd = open("text.txt", O_RDONLY );
    while((chars_read = read(fd, buf, 1)))
    {
        buf[chars_read] = '\0';
        printf("%s", buf);
    }
} */

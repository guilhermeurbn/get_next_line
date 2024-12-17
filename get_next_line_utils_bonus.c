/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:18:42 by guisanto          #+#    #+#             */
/*   Updated: 2024/12/17 15:32:30 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *next_line, char *buffer)
{
	char	*dest;
	int		s1;
	int		s2;
	int		i;

	s1 = ft_strlen(next_line);
	s2 = ft_strlen(buffer);
	dest = malloc(s1 + s2 + 1);
	if (!dest)
		return (free(next_line), NULL);
	dest[s1 + s2] = '\0';
	i = -1;
	while (++i < s1)
		dest[i] = next_line[i];
	free(next_line);
	i = -1;
	while (++i < s2)
		dest[s1 + i] = buffer[i];
	i = -1;
	while (buffer[s2 + ++i])
		buffer[i] = buffer[s2 + i];
	buffer[i] = '\0';
	return (dest);
}

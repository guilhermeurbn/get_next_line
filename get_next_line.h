/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:28:44 by guisanto          #+#    #+#             */
/*   Updated: 2024/12/03 18:31:50 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     GET_NEXT_LINE_H
# define    GET_NEXT_LINE_H

# ifndef     BUFFER_SIZE
# define     BUFFER_SIZE 2
#endif
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char    *ft_join_free(char *buffer, char *buf);
char    *ft_next(char *buffer);
char    *ft_line(char *buffer);
char    *read_file(int fd, char *res);
void	*ft_calloc(size_t num_elements, size_t element_size);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int c);

#endif


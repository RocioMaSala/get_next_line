/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:48:59 by romarti2          #+#    #+#             */
/*   Updated: 2026/02/13 14:53:32 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define SEPARATOR '\n'

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <fcntl.h> // Para read
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* static */ char *rest (char *acum, int i);
char *extract_line (char *acum);
char *get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
int	ft_strlen(char const *str);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif

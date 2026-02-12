/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:43:54 by romarti2          #+#    #+#             */
/*   Updated: 2026/02/12 17:26:35 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
//#include "get_next_line.c"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*new_s;

	new_s = (unsigned char *)s;
	i = 0;
	while (new_s[i])
	{
		if (new_s[i] == (unsigned char)c)
			return ((char *)&new_s[i]);
		else
			i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&new_s[i]);
	return (NULL);
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s2)
		return (NULL);
	while (s[i] != '\0')
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char *get_next_line(int fd)
{
    char buf[10];
    ssize_t nbytes;
    static char acum[11];
    char *line;

    nbytes = read(fd, buf, 10);
    while (nbytes != 0)
    {
        nbytes --;
        acum[nbytes] = buf[nbytes];
    }
    printf("El numero de char es %d, contenido de acum: %s \n", (int)nbytes, acum);
    //  nbytes = read (fd, buf, 10);
    line = ft_strdup(acum);
    printf("Line es igual a: %s \n", line);
    if (ft_strchr(line, '\n') != NULL)
        buf[10] = ft_strchr(line, '\n');
    printf("Contenido de buf: %s \n", buf);
    close(fd);
    return (line);
}
/*
int open (const char* pathname, int flags) // esto va en el main
{
    int fd;

    if(!fd)
        return (-1);
    return(fd);
}*/

int main (void)
{
    int fd;
    const char *pathname;
    
    pathname = "/home/romarti2/Curso42/Git Hub/get_next_line/fichero";
    fd = open(pathname, O_RDONLY);
    if (fd == -1)
    {
        printf("Error al abrir el archivo \n");
    }
    else
    {
       get_next_line (fd);
    }
    return (0); 
}
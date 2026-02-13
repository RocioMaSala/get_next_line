/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:43:54 by romarti2          #+#    #+#             */
/*   Updated: 2026/02/13 14:58:04 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

/*static */ char *rest (char *acum, int i)
{
    char *tmp;
    
    if (!acum[i]) 
    {
        free(acum);
        return NULL;
    }
    tmp = ft_strdup(acum + i); 
    free(acum);
    return (tmp);
}
    
char *extract_line (char *acum)
{
    int i;
    char *line;

    i = 0;
    if (!acum[i])
        return NULL;
    while (acum[i] && acum[i] != '\n')
        i++;
    if (acum[i] == '\n')
        i++;
    line = ft_substr(acum, 0, i);
    acum = rest(acum, i);
    return (line);   
}

char *get_next_line(int fd)
{
    char buf[BUFFER_SIZE + 1];
    ssize_t nbytes;
    static char *acum;
    char *line;
    char *tmp;

    if (!acum)
        acum = ft_strdup("");
    while (!ft_strchr (acum, '\n') && (nbytes = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[nbytes] = '\0';
        tmp = ft_strjoin(acum, buf);
        free(acum);
        acum = tmp;
    }       
    if (nbytes < 0 || !acum)
        return (NULL);
    line = extract_line (acum);
    return (line);
}

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
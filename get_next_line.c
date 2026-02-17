/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:43:54 by romarti2          #+#    #+#             */
/*   Updated: 2026/02/17 15:54:10 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rest(char *acum)
{
	int		i;
	char	*res;

	if (!acum)
		return(NULL);
	if (!*acum)
		return (free(acum), NULL);
	i = 0;
	while (acum[i] && acum[i] != '\n')
		i++;
	if (!acum[i])
		return (free(acum), NULL);
	i++;
	res = ft_strdup(&acum[i]);
	free (acum);
	return (res);
}

char	*extract_line(char *acum)
{
	int		i;
	char	*line;

	i = 0;
	if (!acum || !*acum)
		return (NULL);
	while (acum[i] && acum[i] != '\n')
		i++;
	if (acum[i] == '\n')
		i++;
	line = ft_substr(acum, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

static char	*read_and_join(int fd, char *acum)
{
	char	*buf;
	char	*tmp;
	ssize_t	nbytes;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (free(acum), NULL);
	nbytes = 1;
	while ((!acum || !ft_strchr(acum, '\n')) && nbytes > 0)
	{
		nbytes = read(fd, buf, BUFFER_SIZE);
		if (nbytes < 0)
			break ;
		buf[nbytes] = '\0';
		if (!acum)
			acum = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(acum, buf);
			if (!tmp)
				return (free(buf), free(acum), NULL);
			free(acum);
			acum = tmp;
		}
		if (!acum)
			return (free(buf), NULL);
	}
	free(buf);
	if (nbytes < 0)
		return (free(acum), NULL);
	if (!acum || !*acum)
		return (free(acum), NULL);
	return (acum);
}

char			*get_next_line(int fd)
{
	static char	*acum;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	acum = read_and_join(fd, acum);
	if (!acum)
		return (NULL);
	line = extract_line(acum);
	if (!line)
		return (free(acum), acum = NULL, NULL);
	acum = rest(acum);
	return (line);
}

/*
char	*rest(char *acum)
{
	int		i;
	char	*res;

	if (!acum)
		return (NULL);
	i = 0;
	while (acum[i] && acum[i] != '\n')
		i++;
	if (!acum[i]) // En caso de llegar al final sin \n
	{
		free(acum);
		return (NULL);
	}
	res = ft_strdup(&acum[i + 1]); // copiar lo que hay dsps de \n
	free(acum);
	return (res);
}

char	*extract_line(char *acum)
{
	int		i;
	char	*line;

	i = 0;
	if (!acum || !*acum)
		return (NULL);
	while (acum[i] && acum[i] != '\n')
		i++;
	if (acum[i] == '\n')
		i++;
	line = ft_substr(acum, 0, i);
	return (line);

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	ssize_t		nbytes;
	static char	*acum;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nbytes = 1;
	while (!(acum && ft_strchr(acum, '\n')) && (nbytes = read(fd, buf,
				BUFFER_SIZE)) > 0)
	{
		buf[nbytes] = '\0';
		if (!acum)
		{
			acum = ft_strdup("");
			if (!acum)
				return (NULL);
		}
		tmp = ft_strjoin(acum, buf);
		if (!tmp)
			return (free(acum), NULL);
		free(acum);
		acum = tmp;
	}
	if (nbytes < 0)
	{
		free(acum);
		return (acum = NULL);
	}
	line = extract_line(acum);
	return (acum = rest(acum),line);
}
   int	main(void)
{
	int		fd;
	char	*pathname;

	char *curr; // Puntero auxiliar para recorrer
	pathname = "/home/romarti2/Curso42/Git Hub/get_next_line/fichero";
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir el archivo");
		return (1);
	}
	curr = get_next_line(fd);
	// txt = get_txt(fd);
	// curr = txt;
	while (curr)
	{
		printf("%s", curr);
		// curr = curr->next;
		curr = get_next_line(fd);
	}
	close(fd);
	return (0);
}*/

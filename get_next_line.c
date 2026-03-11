/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:43:54 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/11 11:44:46 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rest(char *acum)
{
	int		i;
	char	*rest;

	if (!acum)
		return (NULL);
	if (!*acum)
		return (free(acum), NULL);
	i = 0;
	while (acum[i] && acum[i] != '\n')
		i++;
	if (!acum[i])
		return (free(acum), NULL);
	i++;
	rest = ft_strdup(&acum[i]);
	free(acum);
	return (rest);
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

static char	*join_and_free(char *acum, char *buf)
{
	char	*tmp;

	if (!acum)
		return (ft_strdup(buf));
	tmp = ft_strjoin(acum, buf);
	free(acum);
	return (tmp);
}

static char	*read_and_join(int fd, char *acum)
{
	char	*buf;
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
		acum = join_and_free(acum, buf);
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

char	*get_next_line(int fd)
{
	static char		*acum;
	char			*line;

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

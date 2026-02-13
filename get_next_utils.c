/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:49:24 by romarti2          #+#    #+#             */
/*   Updated: 2026/02/13 14:33:40 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subcadena;
	size_t	i;
	size_t	subc_len;

	if (!s)
		return (NULL);
	subc_len = ft_strlen(s);
	if (start >= subc_len)
		return (ft_strdup(""));
	if ((subc_len - start) < len)
		len = subc_len - start;
	subcadena = malloc(sizeof(char) * (len + 1));
	if (!subcadena)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subcadena[i] = s[start + i];
		i++;
	}
	subcadena[i] = '\0';
	return (subcadena);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:48:59 by romarti2          #+#    #+#             */
/*   Updated: 2026/02/12 15:07:38 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define SEPARATOR '\n'

#ifndef BUFFER_SIZE
# define BUFFER_SIZE = 42
#endif

# include <fcntl.h> // Para read
# include <unistd.h>

int	ft_hexa(unsigned long num);
int	ft_hexamay(unsigned long num);
int	ft_printchar(int c);
int	ft_printf(char const *s, ...);
int	ft_printpunt(void *ptr);
int	ft_printstring(char *s);
int	ft_putnbr(int n);
int	ft_uint(unsigned int n);

#endif

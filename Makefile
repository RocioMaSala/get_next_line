# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 11:54:06 by romarti2          #+#    #+#              #
#    Updated: 2026/02/16 12:04:28 by romarti2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = get_next_line.c  \
      get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

INCLUDE = get_next_line.h

all: ${NAME}

${NAME}: ${OBJ}
	@ar rcs ${NAME} ${OBJ}

%.o: %.c Makefile get_next_line.h
	@echo "Compiling: $<"
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -f ${OBJ}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re 

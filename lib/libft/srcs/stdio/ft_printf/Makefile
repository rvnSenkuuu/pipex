# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 01:49:25 by tkara2            #+#    #+#              #
#    Updated: 2024/05/29 18:04:01 by tkara2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		=	libftprintf.a
CC		=	cc
CFLAGS		=	-Wall -Werror -Wextra
AR		=	ar rcs
RM		=	rm -rf
SRC_PATH	=	./src/
FILES		=	ft_printf.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_putnbr_uint.c \
			ft_putnbr_hex.c \
			ft_putaddr.c \
			ft_strlen.c \

SRC		=	$(addprefix $(SRC_PATH), $(FILES))
OBJ 		=	 $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHOMY: all clean fclean re

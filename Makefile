# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 11:36:41 by tkara2            #+#    #+#              #
#    Updated: 2024/08/15 11:47:25 by tkara2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
NAMEB		=	pipex_bonus

SRCS_FILES	=	main.c \
				exec.c \
				children.c \
				utils.c \

SRCSB_FILES =	main_bonus.c \
				utils_bonus.c \
				exec_bonus.c \
				process_bonus.c \
				here_doc_bonus.c \

INC_FILE	=	pipex.h pipex_bonus.h

SRCS_PATH	=	srcs/
SRCSB_PATH	=	srcs_bonus/
OBJS_PATH	=	.objs/
INC_PATH	=	include/

LIBFT_PATH	=	./lib/libft/
LIBFT_LIB	=	$(LIBFT_PATH)libft.a

SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_FILES))
SRCSB		=	$(addprefix $(SRCSB_PATH), $(SRCSB_FILES))
OBJS		=	$(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
OBJSB		=	$(addprefix $(OBJS_PATH), $(SRCSB:.c=.o))
INC			=	$(addprefix $(INC_PATH), $(INC_FILE))

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -g3 -I$(INC_PATH) -I$(LIBFT_PATH)
LFLAGS		=	-L$(LIBFT_PATH) -lft
RM			=	rm -rf

NORM_FLAG	=	-R CheckForbiddenSourceHeader -R CheckDefine

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

$(NAMEB):	$(OBJSB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJSB) $(LFLAGS) -o $(NAMEB)

$(OBJS_PATH)%.o:	%.c
	mkdir -p ${@D}
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH) --silent

norm:
	@norminette $(NORM_FLAG) $(SRCS) $(SRCSB) $(INC)

lftnorm:
	@make norm -C $(LIBFT_PATH)

bonus:	$(NAMEB)

clean:
	$(RM) $(OBJS_PATH)
	@make clean -C $(LIBFT_PATH)
	@echo "[DONE] Objects files deletion..."

fclean:	clean
	$(RM) $(NAME) $(NAMEB)
	@make fclean -C $(LIBFT_PATH)
	@echo "[DONE] pipex deletion..."

re:	fclean all
	@echo "[DONE] pipex recompiled..."

.PHONY:	all clean fclean re bonus
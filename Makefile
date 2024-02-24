# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfranco <thfranco@student.42.rio>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 16:54:23 by thfranco         #+#    #+#              #
#    Updated: 2024/02/24 20:48:47 by thfranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = 	pipex.c \
		ft_utils.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -f

AR = ar rcs

INF				= infile

OUTF			= outfile

CC_FLAGS = -Wall -Wextra -Werror -g

LEAK = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s

all:			$(NAME)

$(NAME):		

				@echo "---------- Compiling libft ----------\n"
				@make -C libft
				@$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME)

clean:
				@make clean -C libft/
				@ $(RM) $(OBJS)

fclean:			clean

				@echo "---------- Deleting Everything ----------\n"
				@make fclean -C libft/
				$(RM) $(NAME) $(INF) $(OUTF)
norma:	
				norminette $(SRCS) pipex.h ./libft

leak:
				$(LEAK) ./pipex infile "cat" "wc -l" outfile

re:				fclean all 

.PHONY:			all clean fclean re leak 

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thafranco <thfranco@student.42.rio>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 16:54:23 by thafranco         #+#    #+#              #
#    Updated: 2024/01/31 17:57:30 by thafranco        ###   ########.fr        #
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
				$(RM) $(NAME) 

re:				fclean all 

.PHONY:			all clean fclean re 

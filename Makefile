NAME = pipex

LIBFT_PATH = libft/

LIB = $(LIBFT_PATH)libft.a

SRCS = 	pipex.c \
	ft_utils.c \
	process.c \


OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -f

AR = ar rcs

FILE = output

CC_FLAGS = -Wall -Wextra -Werror

all: subsystem $(NAME)

subsystem: 
	make -C $(LIBFT_PATH) all

$(NAME): $(OBJS)
		$(CC) $(CC_FLAGS) $(OBJS) $(LIB) -o $(NAME)

clean:
		make -C $(LIBFT_PATH) clean
		$(RM) $(OBJS)

fclean: clean 
		make -C $(LIBFT_PATH) fclean
		$(RM) $(NAME)

re:	fclean all 

call: all clean
		make -C $(LIB_PATH) fclean
		[[ -f $(FILE) ]] && rm $(FILE) || true

.PHONY: all clean fclean re call subsystem

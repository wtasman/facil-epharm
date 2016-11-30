CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = pillsbury

SRCS = ./*.c \
		./libft/*.c

HDRS = ./*.h \
		./libft/libft.h

OBJS = ./*.o \

$(NAME): 
	@$(CC) $(CFLAGS) -c $(SRCS) -I $(HDRS)
	@$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

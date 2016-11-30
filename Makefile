CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = pillsbury

SRCS = ./*.c \
		./libft/*.c

HDRS = ./*.h \
		./libft/libft.h

OBJS = ./*.o \

GSHS = ./*.gch \
		./libft/*.gch

$(NAME): 
	@$(CC) $(CFLAGS) -c $(SRCS)
	@$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	@/bin/rm -f $(OBJS)
	@/bin/rm -f $(GSHS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

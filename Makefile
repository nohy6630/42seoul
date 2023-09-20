CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJS = pipex.o utils1.o utils2.o
NAME = pipex

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re : fclean all
CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJS = ft_printf.o utils_1.o utils_2.o utils_3.o
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re : fclean all
CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJS = ft_printf.o utils_1.o utils_2.o utils_3.o
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C ./libft
	cp ./libft/libft.a $(NAME)
	ar rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -f $(OBJS)
	make fclean -C ./libft

fclean :
	rm -f $(OBJS) $(NAME)
	make fclean -C ./libft

re : fclean all

.PHONY: all clean fclean re
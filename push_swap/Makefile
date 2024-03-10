CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJS = main.o stack.o stack_utils.o \
		utils.o utils2.o parsing.o \
		init.o op1.o op2.o op3.o \
		sort_5_or_less_1.o sort_5_or_less_2.o \
		sort.o optimize.o ft_long_atoi.o
NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C ./ft_printf
	$(CC) $(CFLAGS) $^ -o $@ -L ./ft_printf -lftprintf

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -f $(OBJS)
	make fclean -C ./ft_printf

fclean :
	rm -f $(OBJS) $(NAME)
	make fclean -C ./ft_printf

re : fclean all

.PHONY: all clean fclean re
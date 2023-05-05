#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    long num;

    num = n;
    if (num < 0)
    {
        write(fd, '-', 1);
        ft_putnbr_fd(-num, fd);
    }
    if (num < 10)
        write(fd, num + '0', 1);
    else
    {
        ft_putnbr_fd(n / 10, fd);
        ft_putnbr_fd(n % 10, fd);
    }
}
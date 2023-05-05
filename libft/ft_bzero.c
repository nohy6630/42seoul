#include "libft.h"

void ft_bzero(void *b, size_t len)
{
    int i;
    char *p;

    i = 0;
    p = b;
    while (i < len)
    {
        p[i] = 0;
        i++;
    }
}
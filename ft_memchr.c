#include "libft.h"

void *ft_memchr(const void *b, int c, size_t len)
{
    int i;
    char *str;

    i = 0;
    str = b;
    while (i < len)
    {
        if (str[i] == c)
            break;
        i++;
    }
    if (i >= len)
        return (NULL);
    else
        return (str + i);
}
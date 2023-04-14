#include "libft.h"

void *ft_memchr(const void *s, int c, int n)
{
    int i;
    char *str;

    i = 0;
    str = s;
    while (i < n)
    {
        if(str[i] == c)
            break;
        i++;
    }
    if (i >= n)
        return NULL;
    else
        return (str + i);
}
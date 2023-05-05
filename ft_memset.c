#include "libft.h"

void *ft_memset(void *dest, int c, size_t len)
{
    char *p;
    int i;

    p = dest;
    i = 0;
    while (i < len)
    {
        p[i] = c;
        i++;
    }
    return (dest);
}
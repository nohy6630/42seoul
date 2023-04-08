#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    int i;

    i = ft_strlen(s) - 1;
    while (i >= 0)
    {
        if (s[i] == c)
            return (s + i);
    }
    return NULL;
}
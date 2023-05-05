#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    int i;

    i = ft_strlen(s);//맨 뒤 널문자도 포함해서 탐색해야 함
    while (i >= 0)
    {
        if (s[i] == c)
            return (s + i);
        i--;
    }
    return (NULL);
}
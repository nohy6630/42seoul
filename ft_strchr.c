#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(s);
    while (i <= len) // 맨 뒤 널문자도 포함해서 탐색해야 함
    {
        if (s[i] == c)
            return (s + i);
        i++;
    }
    return (NULL);
}
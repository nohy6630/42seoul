#include "libft.h"

char *ft_strnstr(const char *s1, const char *s2, int n)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(s2);
    if (len == 0)
        return NULL;
    while (s1[i] && i <= n - len)
    {
        if (ft_strlen(s1 + i) >= len && !ft_memcmp(s1 + i, s2, len))
            return (s1 + i);
        i++;
    }
    return NULL;
}
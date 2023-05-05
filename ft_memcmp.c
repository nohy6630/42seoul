#include "libft.h"

int ft_memcmp(const void *b1, const void *b2, size_t len)
{
    int i;
    char *str1;
    char *str2;

    i = 0;
    str1 = b1;
    str2 = b2;
    while (str1[i] == str2[i] && i < len)
        i++;
    if (i >= len)
        return (0);
    else
        return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
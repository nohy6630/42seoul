#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, int n)
{
    int i;
    char *str1;
    char *str2;

    i = 0;
    str1 = s1;
    str2 = s2;
    while (str1[i] == str2[i] && i < n)
        i++;
    if (i >= n)
        return 0;
    else
        return (str1[i] - str2[i]);
}
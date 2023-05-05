#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t len)
{
    char *dp;
    char *sp;
    int i;

    dp = dst;
    sp = src;
    while (i < len)
    {
        dp[i] = sp[i];
        i++;
    }
    return (dst);
}
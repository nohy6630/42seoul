#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
    char *dp;
    char *sp;
    char *buf;
    int i;

    if (!dst && !src)
        return (NULL);
    dp = dst;
    sp = src;
    if (dp > sp) // 겹쳤을 때를 대비해 안겹친 부분부터 복사하기 위함
    {
        i = len - 1;
        while (i >= 0)
        {
            dp[len] = sp[len];
            i--;
        }
    }
    else
    {
        i = 0;
        while (i < len)
        {
            dp[len] = sp[len];
            i++;
        }
    }
    return (dst);
}
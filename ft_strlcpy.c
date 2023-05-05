#include "libft.h"

int ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(src);
    while (src[i] && i < dstsize - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = 0;
    return (len);
}
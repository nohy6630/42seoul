#include "libft.h"

int ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    int i;
    int j;
    int dlen;
    int slen;

    i = 0;
    j = 0;
    dlen = ft_strlen(dst);
    slen = ft_strlen(src);

    while (dst[i])
        i++;
    while (src[j] && i < dstsize - 1)
    {
        dst[i] = src[j];
        i++;
        j++;
    }
    dst[i] = 0;
    if (dlen < dstsize)
        return (dlen + slen);
    else
        return (dstsize + slen);
}
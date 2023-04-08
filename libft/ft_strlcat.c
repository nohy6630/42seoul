#include "libft.h"

int ft_strlcat(char *dst, const char *src, int size)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (ft_strlen(dst) < size - 1)
        return ft_strlen(dst) + ft_strlen(src);
    while (dst[i])
        i++;
    while (src[j] && i < size - 1)
    {
        dst[i] = src[j];
        i++;
        j++;
    }
    dst[i] = 0;
    return ft_strlen(dst) + ft_strlen(src);
}
#include "libft.h"

int ft_strlcpy(char *dst, const char *src, int size)
{
    int i;

    i = 0;
    while (src[i] && i < size - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = 0;
    return ft_strlen(src);
}
#include "libft.h"

void *ft_calloc(size_t number, size_t size)
{
    void *ret;

    ret = malloc(number * size);
    if (!ret)
        return (NULL);
    ft_memset(ret, 0, number * size);
    return (ret);
}
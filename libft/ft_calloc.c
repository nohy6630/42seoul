#include "libft.h"

void *ft_calloc(int n, int size)
{
    void *ret;
    
    ret = malloc(size * n);
    return (ret);
}
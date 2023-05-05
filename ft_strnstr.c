#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    int i;
    int j;
    int llen;

    i = 0;
    llen = ft_strlen(little);
    if (!llen)
        return (big);
    while (big[i] && i + llen <= len)
    {
        j = 0;
        while (big[i + j] && little[j])
        {
            if (big[i + j] != little[j])
                break;
            j++;
        }
        if (j == llen)
            return (big + i);
        i++;
    }
    return (NULL);
}
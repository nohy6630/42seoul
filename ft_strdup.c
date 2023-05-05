#include "libft.h"

char *ft_strdup(const char *str)
{
    char *ret;
    int i;
    int len;

    len = ft_strlen(str);
    ret = malloc(len + 1);
    while (str[i])
    {
        ret[i] = str[i];
        i++;
    }
    ret[i] = 0;
    return (ret);
}
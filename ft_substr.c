#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    int i;
    char *ret;

    if (s == NULL)
        return (NULL);
    if (start >= ft_strlen(s))
        return (ft_strdup(""));
    if (len > ft_strlen(s + start))
        len = ft_strlen(s + start);
    ret = malloc(len + 1);
    if (!ret)
        return (NULL);
    i = 0;
    while (s[i] && i < len)
    {
        ret[i] = s[start];
        i++;
        start++;
    }
    ret[i] = 0;
    return (ret);
}
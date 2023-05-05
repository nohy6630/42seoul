#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *ret;
    int i;
    int j;

    if (s1 == NULL || s2 == NULL)
        return (NULL);
    ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!ret)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        ret[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        ret[i] = s2[j];
        i++;
        j++;
    }
    ret[i] = 0;
    return (ret);
}
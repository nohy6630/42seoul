void *ft_memset(void *ptr, int value, int num)
{
    char *p = ptr;
    int i;

    p = ptr;
    i = 0;
    while (i < num)
    {
        p[i] = value;
        i++;
    }
    return ptr;
}
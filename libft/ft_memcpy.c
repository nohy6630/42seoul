void *ft_memcpy(void *dest, const void *src, int n)
{
    char *dp;
    char *sp;
    int i;

    dp = dest;
    sp = src;
    while (i < n)
    {
        dp[i] = sp[i];
        i++;
    }
    return dest;
}
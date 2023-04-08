#include "libft.h"

void *ft_memmove(void *dest, const void *src, int n)
{
    char *dp;
    char *sp;
    char *buf;
    int i;

    dp = dest;
    sp = src;
    buf = malloc(sizeof(char) * n);
    i = 0;
    while (i < n)
    {
        buf[i] = sp[i];
        i++;
    }
    i = 0;
    while (i < n)
    {
        dp[i] = buf[i];
        i++;
    }
    free(buf);
    return dest;
}
// memmove는 복사할 내용을 임시공간에 저장했다 dest에 넣는것이 memcpy와의 차이점?
// https://blog.naver.com/PostView.nhn?isHttpsRedirect=true&blogId=sharonichoya&logNo=220510332768
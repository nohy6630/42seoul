#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

char func1(unsigned int n, char c)
{
    return c+n;
}

void func2(unsigned int n, char *s)
{
    *s+=n;
}

int main()
{
    printf("%d = 1\n", ft_isalpha('c'));
    printf("%d = 1\n", ft_isdigit('5'));
    printf("%d = 1\n", ft_isascii('!'));
    printf("%d = 1\n", ft_isprint('e'));
    printf("%d = 5\n", ft_strlen("apple"));

    int arr[5] = {1, 2, 3, 4, 5};
    ft_memset(arr, -1, sizeof(arr));
    printf("%d = -1\n", arr[2]);

    ft_bzero(arr, sizeof(arr));
    printf("%d = 0\n", arr[2]);

    char dst[] = "asdfasdf";
    char src[] = "abc";
    ft_memcpy(dst, src, sizeof(src));
    printf("%s = abc\n", dst);

    char overlap[] = "abcdefg";
    ft_memmove(overlap, overlap + 2, 6);
    printf("%s = cdefg\n", overlap);

    char dst2[] = "asdfasdf";
    char src2[] = "abc";
    ft_strlcpy(dst2, src2, 3);
    printf("%s = abc\n", dst2);

    char dst3[100] = "gggg";
    char src3[] = "abc";
    ft_strlcat(dst3, src3, 3);
    printf("%s = ggggabc\n", dst3);

    printf("%c = A\n", ft_toupper('a'));
    printf("%c = a\n", ft_tolower('A'));

    char str[] = "ab!cde!fg";
    printf("%s = !cde!fg\n", ft_strchr(str, '!'));
    printf("%s = !fg\n", ft_strrchr(str, '!'));

    printf("%d = 0\n", ft_strncmp("abc", "abcde", 3));
    printf("%s = !cde!fg\n", ft_memchr(str, '!', ft_strlen(str)));
    printf("%d = 0\n", ft_memcmp("abc", "abcde", 3));
    printf("%s = hi!??\n", ft_strnstr("hello hi hi!??", "hi!", ft_strlen("hello hi hi!??")));
    printf("%d = -424240\n",ft_atoi("  -424240"));

    char *ret=(char *)ft_calloc(5,4);
    printf("%d = 0\n",ret[19]);

    printf("%s = abcde\n",ft_strdup("abcde"));
    printf("%s = bcd\n",ft_substr("abcde",1,3));
    printf("%s = abcABC\n",ft_strjoin("abc","ABC"));
    printf("%s = GOOD\n",ft_strtrim("adbcGOODbcdc","abcd"));

    char **words=ft_split("s!asdf!sdafsd!!asdfasdf",'!');
    int i=0;
    while(words[i])
    {
        printf("%s\n",words[i]);
        i++;
    }
    printf("=\n");
    printf("s\n");
    printf("asdf\n");
    printf("sdafsd\n");
    printf("asdfasdf\n");

    printf("%s = -424240\n",ft_itoa(-424240));
    printf("%s = abc\n",ft_strmapi("aaa",func1));

    char str2[4]={'c','c','c',0};
    ft_striteri(str2,func2);
    printf("%s = cde\n",str2);

    int fd=open("test.txt",O_WRONLY|O_CREAT|O_TRUNC,0666);
    ft_putchar_fd('x',fd);
    ft_putstr_fd("hello",fd);
    ft_putendl_fd("nice to meet you!",fd);
    ft_putnbr_fd(-42040,fd);
    close(fd);
    return 0;
}
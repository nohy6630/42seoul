#ifndef LIBFT_H
#define LIBFT_H
#include <unistd.h>
#include <stdlib.h>

int ft_isalpha(int);
int ft_isdigit(int);
int ft_isascii(int);
int ft_isprint(int);
int ft_strlen(const char *);
void *ft_memset(void *, int, int);
void ft_bzero(void *, int);
void *ft_memcpy(void *, const void *, int);
void *ft_memmove(void *, const void *, int);
int ft_strlcpy(char *, const char *, int);
int ft_strlcat(char *, char *, int);
int ft_toupper(int);
int ft_tolower(int);
char *ft_strchr(const char *, int);
int ft_ strncmp(const char *, const char *, int);
//----여기부터 작성해애ㅑ됨--
void *memchr(const void *, int, int);
int memcmp(const void *, const void *, int);
char *strnstr(const char *, const char *, int);
int atoi(const char *);
#endif
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
int ft_strncmp(const char *, const char *, int);
void *ft_memchr(const void *, int, int);
int ft_memcmp(const void *, const void *, int);
char *ft_strnstr(const char *, const char *, int);
int ft_atoi(const char *);
void *ft_calloc(int, int);
char *ft_strdup(const char *);
#endif
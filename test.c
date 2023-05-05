#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	printf("%p",strdup(NULL));
}

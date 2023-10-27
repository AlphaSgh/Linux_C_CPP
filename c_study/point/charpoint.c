#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mystrcpy(char* dest, const char* src)
{
    char* res = dest;
    printf("res = %p\ndest = %p\n", res, dest);
    if (dest != NULL && src != NULL)
    {
        while ((*dest++ = *src++) != '\0')
        {
            ;
        }
    }
    printf("res = %p\ndest = %p\n", res, dest);
    return res;
}
char* mystrcpyn(char* dest, const char* src, size_t n)
{
    char* res = dest;
    size_t i = 0;
    while (i < n && (*(src + i) != '\0'))
    {
        *(dest + i) = *(src + i);
        i++;
    }
    while (i < n)
    {
        *(dest + i) = '\0';
    }
    return res;
}
int main(void)
{
    char str1[] = "hello world";
    char str2[128];
    char str3[128];
    mystrcpy(str2, str1);
    printf("%s\n", str2);
    mystrcpyn(str3, str1, 5);
    printf("%s\n", str3);

    #if 0
    char str1[] = "hello";
    // str1 = "world"; //error
    strcpy(str1, "world");
    puts(str1);
    
    char* str2 = "hello";
    // strcpy(str2, "world"); // error
    str2 = "world";
    #endif
    // puts(str2);
}
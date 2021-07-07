#include <stdio.h>

#define CHARS_LEN 128
#define TRUE 1
#define FALSE 0

void squeeze(char [], char []);

int main()
{
    char s1[] = "acdbef";
    char s2[] = "bdf";
    squeeze(s1, s2);
    printf("%s\n", s1);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j;
    char chars[CHARS_LEN];

    for (i = 0; i < CHARS_LEN; ++i)
        chars[i] = FALSE;
    
    for(i = 0; s2[i] != '\0'; ++i)
        chars[s2[i]] = TRUE;
    
    for (i = j = 0; s1[i] != '\0'; ++i)
        if (chars[s1[i]] == FALSE)
            s1[j++] = s1[i];
    s1[j] = '\0';
}
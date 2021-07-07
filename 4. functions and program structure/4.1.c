#include <stdio.h>

int strindex(char [], char []);

int main()
{
    char str[] = "just do it!";
    char substr[] = "do";
    
    int i = strindex(str, substr);  
    printf("first index of substr: %d", i);

    return 0;
}

int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; ++i) {
        for (j = i, k = 0; t[k] != '\0'; ++j, ++k) {
                if (s[j] != t[k])
                    break;
        }
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
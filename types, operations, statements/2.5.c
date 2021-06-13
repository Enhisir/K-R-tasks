#include <stdio.h>

#define CHARS_LEN 128
#define TRUE 1
#define FALSE 0

int any(char [], char []);

int main() {
    char s1[] = "abcdef";
    char s2[] = "def";
    printf("%d\n", any(s1, s2));

    return 0;
}

int any(char s1[], char s2[]) {
    int i;

    char chars[CHARS_LEN];
    for (i = 0; i < CHARS_LEN; ++i)
        chars[i] = FALSE;
    for(i = 0; s2[i] != '\0'; ++i)
        chars[s2[i]] = TRUE;
    
    for (i = 0; s1[i] != '\0'; ++i) {
        if (chars[s1[i]])
            return i;
    }

    return -1;
}

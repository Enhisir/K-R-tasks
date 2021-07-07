#include <stdio.h>

#define N 1000

int getline(char [], int);

int main()
{
    char line[N];
    int len;
    while ((len = getline(line, N)) != 0) {
        if (len > 80) {
            printf("%s", line);
        }
    }
    return 0;
}

int getline(char line[], int len)
{
    int c, i;
    for (i = 0; i < len - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}
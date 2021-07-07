#include <stdio.h>

#define N 1000

int _getline(char [], int);
void copy(char [], char []);

int main()
{
    int len, max, local;
    char line[N], longest[N];

    max = 0;
    while ((len = _getline(line, N)) > 0) {
        if (line[len - 1] != '\n') {
            local = _getline(line, N);
            while (local != 0 && line[local - 1] != '\n') {
                if (local == 0)
                    break;
                len += local - 1;
                local = _getline(line, N);
            }
            len += local - 1;
        }
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
        printf("Its length is %d\n", max);
    return 0;
}

int _getline(char line[], int maxline)
{
    int i;
    char c;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
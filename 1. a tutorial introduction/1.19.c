#include <stdio.h>

#define N 1000

int getline(char [], int);
void reverse(char [], int);

int main()
{
    char line[N];
    int len;
    printf("******************************\n");
    while ((len = getline(line, N)) != 0) {
        reverse(line, len);
        printf("%s", line);
        printf("******************************\n");
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

void reverse(char line[], int len)
{
    char c;
    int i = 0, j = len - 1;
    if (line[j] == '\n' || line[j] == '\t')
        --j;
    for (i = 0; i < j; ++i, --j) {
        c = line[i];
        line[i] = line[j];
        line[j] = c;
    }
}
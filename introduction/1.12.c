#include <stdio.h>

int main() {
    char c;
    int count;

    count = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t')
            c = '\n';
        if (c == '\n')
            ++count;
        else
            count = 0;
        if (count <= 1)
            putchar(c);
    }
    return 0;
}

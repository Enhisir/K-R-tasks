#include <stdio.h>

#define TAB 4

int main() {
    int i, c;
    while ((c = getchar()) != EOF) {
        if (c == '\t')
            for (i = 0; i < TAB; ++i)
                putchar(' ');
        else
            putchar(c); // //rlgrokoer
    }
    return 0;
}
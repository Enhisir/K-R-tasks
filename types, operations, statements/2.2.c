#include <stdio.h>

#define MAX_LEN 1000

int main() {
    int i, lim, c;
    char s[MAX_LEN];
    lim = MAX_LEN;
    for (i = 0; i < lim - 1; ++i) {
        if ((c = getchar()) == EOF) {
            lim = 0;
        } else if (c == '\n') {
            lim = 0;
        } else {
            s[i] = c;
        }
    }
}
#include <stdio.h>

#define N 31

int main() {
    char c;
    int i, j, max, count;
    int len[N];

    count = 0;

    for (i = 0; i < N; ++i) {
        len[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (count > 0 && (c == ' ' || c == '\n' || c == '\t')) {
            ++len[count];
            count = 0;
        }
        else
            ++count;
    }

    max = 0;

    for(j = 1; j < N; ++j) {
        if (len[j]) {
            printf(" %2d", j);
            if (len[j] > max)
                max = len[j];
        }
    }
    printf("\n");

    for (i = 1; i <= max; ++i) {
        for(j = 1; j < N; ++j) {
            if (len[j]) {
                if (len[j] >= i)
                    printf(" ##");
                else
                    printf("   ");
            }    
        }
        printf("\n");
    }

    return 0;
}
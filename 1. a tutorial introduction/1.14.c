#include <stdio.h>

#define N 128

int main()
{
    char c;
    int i, j;
    int abc[N];

    for (i = 0; i < N; ++i) {
        abc[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        ++abc[c];
    }

    for (i = 0; i < N; ++i) {
        if (abc[i] != 0) {
            if (i == '\n')
                printf("\\n: ");
            else if (i == '\t')
                printf("\\t: ");
            else
                printf("%c: ", (char)i);
            for (j = 0; j < abc[i]; ++j)
                printf("#");
            printf("\n");
        }
    }
    return 0;
}
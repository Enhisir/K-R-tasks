#include <stdio.h>

int main() {
    int spaces, tabs, eos;
    char c;

    spaces = 0;
    tabs = 0;
    eos = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ')
            ++spaces;
        else if (c == '\t')
            ++tabs;
        else if (c == '\n')
            ++eos;
    }
    printf("spaces: %d\ntabs: %d\n\\n: %d\ntotal: %d\n", 
    spaces, tabs, eos, spaces + tabs + eos);
    return 0;
}
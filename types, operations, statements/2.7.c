#include <stdio.h>

void printfbit(unsigned int);
unsigned int invert(unsigned int x, unsigned int p, unsigned int n);

int main() {
    unsigned c = 'f';

    printfbit(c);
    printfbit(invert(c, 5, 3));

    return 0;
}

void printfbit(unsigned int n) {
    int i;
    for(i = 31; i >= 0; --i) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

unsigned int invert(unsigned int x, unsigned int p, unsigned int n) {
    int mask1 = (~0 << ++p) | ~(~0 << (p - n));;
    int mask2 = ~0 << (p - n) & ~mask1;
    return (x & mask1) | (~x & mask2);
}
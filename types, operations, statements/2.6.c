#include <stdio.h>

void printfbit(unsigned int);
unsigned int setbits(unsigned int, unsigned int, unsigned int, unsigned int);

int main() {
    unsigned int c1 = 'f', c2 = 'z';

    // printfbit(4294967295);
    // printfbit(2147483648);
    // printf("\n");

    printfbit(c1);
    printfbit(c2);
    printfbit(setbits(c1, 5, 3, c2));

    return 0;
}

void printfbit(unsigned int n) {
    int i;
    for(i = 31; i >= 0; --i) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

unsigned int setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y) {
    ++p;
    int mask1 = (~0 << p) | ~(~0 << (p - n));
    int mask2 = ~(~0 << n);
    return (x & mask1) | ((y & mask2) << (p - n));
}

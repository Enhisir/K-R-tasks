#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
    int fahr;
    printf("Таблица температур\n");
    printf("%6s\t%6s\n", "F", "C");
    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
        printf("%6d\t%6.1f\n", fahr, 5.0 / 9.0 * (fahr - 32));
    }
    return 0;
}
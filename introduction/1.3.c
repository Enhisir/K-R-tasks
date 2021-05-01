#include <stdio.h>

int main() {
    int begin, end, step;

    begin = 0;
    end = 300;
    step = 20;
    
    printf("Таблица температур\n");
    printf("%6s\t%6s\n", "F", "C");
    while (begin <= end) {
        printf("%6d\t%6.1f\n", begin, 5.0 / 9.0 * (begin - 32));
        begin += step;
    }
    return 0;
}
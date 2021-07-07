#include <stdio.h>

#define BEGIN 0
#define END 300
#define STEP 20

double fahrenheit(int t);
double celsius(int t);

int main()
{
    int t;
    
    printf("Таблица температур (C -> F)\n");
    for (t = BEGIN; t <= END; t += STEP) {
        printf("%6d %6.2f\n", t, fahrenheit(t));
    }
    
    printf("Таблица температур (F -> C)\n");
    for (t = BEGIN; t <= END; t += STEP) {
        printf("%6d %6.2f\n", t, celsius(t));
    }

    return 0;
}

double fahrenheit(int t) {
    return 32 + 9.0 / 5.0 * t;
}

double celsius(int t) {
    return 5.0 / 9.0 * (t - 32);
}
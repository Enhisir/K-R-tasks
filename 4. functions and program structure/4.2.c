#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

int __getline(char [], int);
double atof(char []);


int main()
{
    char line[MAXLINE];
    __getline(line, MAXLINE);
    printf("%.8f", atof(line));
    return 0;
}

int __getline(char line[], int len)
{
    int c, i;
    for (i = 0; i < len - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

double atof(char s[])
{
    double val, power;
    int i, sign;
    double exp_val, exp_sign, exp_power;

    for (i = 0; isspace(s[i]); ++i)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        ++i;
    }
    for (val = 0.0; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
    };

    if (s[i] == '.') {
        ++i;
    }
    for (power = 1.0; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    if (s[i] == 'e') {
        ++i;
    }
    exp_sign = (s[i] == '-') ? 0.1 : 10;
    if (s[i] == '+' || s[i] == '-') {
        ++i;
    }
    for (exp_power = 0.0; isdigit(s[i]); ++i) {
        exp_power = 10.0 * exp_power + (s[i] - '0');
    }

    exp_val = 1.0;
    for (i = 0; i < exp_power; ++i) {
        exp_val *= exp_sign;
    }

    return val * sign / power * exp_val;
}
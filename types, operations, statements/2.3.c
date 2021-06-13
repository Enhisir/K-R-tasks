#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int htoi(const char[]);

int main() {
    char line[] = "0x129C"; // 4764
    printf("hex-string %s is %d", line, htoi(line));
    return 0;
}

int htoi(const char line[]) {
    int k;
    int i = 0;
    int result = 0;
    int len = strlen(line);

    char c = tolower(line[1]);

    if (line[0] == '0' && c == 'x')
        i += 2;

    for (i; i < len; ++i) {
        c = tolower(line[i]);
        k = (int)pow(16, len - i - 1);
        
        if (c >= 'a' && c <= 'f')
            result += (c - 'a' + 10) * k;
        else if (c >= '0' && c <= '9')
            result += (c - '0') * k;
    }
    return result;
}

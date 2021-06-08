#include <stdio.h>
#include <limits.h>

int main() {
    printf("char variables vary from %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char variables vary from %ud to %u\n", 0, UCHAR_MAX);
    printf("short variables vary from %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short variables vary from %u to %u\n", 0, USHRT_MAX);
    printf("int variables vary from %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int variables vary from %u to %u\n", 0, UINT_MAX);
    printf("long variables vary from %d to %d\n", LONG_MIN, LONG_MAX);
    printf("unsigned char variables vary from %lu to %lu\n", 0, ULONG_MAX);
    return 0;
}
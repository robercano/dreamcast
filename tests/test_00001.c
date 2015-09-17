#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv)
{
    long n = strtol("123456", NULL, 0);
    printf("%d\n", n);

    uint32_t a = 232234243;
    uint32_t b = 34592234;
    printf("%d\n", a/b);
    return 0;
}

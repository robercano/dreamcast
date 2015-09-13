#include <stdio.h>

int main(int argc, char **argv)
{
    long n = strtol("12345678", NULL, 0);
    printf("%d\n", n);
    return 0;
}

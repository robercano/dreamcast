#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv)
{
    if (argc > 1) {
        long n = strtol(argv[1], NULL, 0);
        printf("%d\n", n);
    } else {
        printf("no args\n\n");
    }
    return 0;
}

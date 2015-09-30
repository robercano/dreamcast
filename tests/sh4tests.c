#include <stdio.h>
#include <stdint.h>
#include <math.h>

void usage()
{
    fprintf(stderr, "sh4tests <iterations> <string>\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "    iterations: Number of iterations for some of the tests\n");
    fprintf(stderr, "    string: String used for some of the tests\n");
    fprintf(stderr, "\n");
    exit(1);
}

int main(int argc, char **argv)
{
    int n, i;
    char *s;

    if (argc < 3) {
        usage();
    }

    n = strtol(argv[1], NULL, 0);
    s = argv[2];

    /* printf tests */
    for (i=0; i<n; ++i) {
        printf("%d\n", i*i*2);
    }
    return 0;
}

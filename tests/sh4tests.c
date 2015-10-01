#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void usage()
{
    printf("sh4tests <iterations> <string>\n");
    printf("\n");
    printf("    iterations: Number of iterations for some of the tests\n");
    printf("    string: String used for some of the tests\n");
    printf("\n");
}

#define TEST(str) printf("[%s]\n", str)
#define RUN(expr) printf("[Line %d] %s -> ", __LINE__, #expr); expr;
#define LOOP(limit) for (i=0; i<limit; ++i) { printf("Iter-%d ", i);
#define ENDLOOP }

int main(int argc, char **argv)
{
    int n, i;
    char *s;
    char tmp[256];
    void *p=(void*)0xdeadbeef;

    if (argc < 3) {
        usage();
        return 1;
    }
    s = argv[2];

    /* pre-printf tests */
    TEST("pre-printf");
    RUN(printf("string\n"));
    RUN(printf("%s\n", s));
    RUN(printf("%d\n", 45));
    RUN(printf("%d\n", 45098));
    RUN(printf("%d\n", (int32_t)INT_MAX));
    RUN(printf("%u\n", (uint32_t)INT_MAX+1));
    RUN(printf("%u\n", (uint32_t)UINT_MAX));

    /* Test strtol */
    TEST("strtol");
    RUN(printf("%ld\n", strtol("678", NULL, 0)));
    RUN(printf("%ld\n", strtol("0x4567", NULL, 0)));
    RUN(printf("%ld\n", strtol("0777", NULL, 0)));
    RUN(printf("%ld\n", strtol(argv[1], NULL, 0)));

    n = strtol(argv[1], NULL, 0);

    /* Dynamic printf */
    TEST("printf");

    LOOP(n)
        RUN(printf("%d\n", i*i*2));
    ENDLOOP;
    LOOP(n)
        RUN(printf("%.2f\n", 1000.0/i/i));
    ENDLOOP
    LOOP(n)
        RUN(printf("%x\n", i+i*45));
    ENDLOOP
    RUN(printf("%s%s\n", s, s));
    RUN(printf("%s%d%x%.2f%x%u%lu\n", s, n, n*n, 1024.0/n/n/n, 879875, (unsigned)n*n, (unsigned long)n*765*n));
    RUN(printf("%p\n", p));

    /* snprintf tests */
    TEST("snprintf");

    RUN(
        snprintf(tmp, 256, "Testing snprintf %d", n);
        printf("%s\n", tmp);
       );
    RUN(
        snprintf(tmp, 256, "This is the string: %s", s);
        printf("%s\n", tmp);
       );

    /* strlen */
    TEST("strlen");

    RUN(printf("%lu\n", strlen(s)));
    RUN(printf("%lu\n", strlen("Testing strlen")));
    RUN(printf("%lu\n", strlen("THis is a quite long string, man, quite, quite long string!!!!!!!!")));

    /* memcmp */
    char a[1024], b[1024];
    RUN (
        for (i=0; i<256; ++i) {
            a[i] = n*i;
            b[i] = n*i;
        }
        printf("%d\n", memcmp(a, b, 256)==0);
        );

    RUN(
        for (i=0; i<256; ++i) {
            a[i] = n*i;
            b[i] = n*i;
        }
        a[255] = 45;
        b[255] = 46;
        printf("%d\n", memcmp(a, b, 256)<0);
       );

    RUN(
        a[255] = 46;
        b[255] = 45;
        printf("%d\n", memcmp(a, b, 256)>0);
       );

    /* memmove */
    TEST("memmove");

    RUN(
        for (i=0; i<256; ++i) {
            a[i] = n*(i+1);
            b[i] = n*i;
        }
        printf("%d\n", memcmp(a, b, 256)!=0);
        printf("%d\n", a==memmove(a, b, 256));
        printf("%d\n", memcmp(a, b, 256)==0);
       );
    RUN(
        for (i=0; i<1024; ++i) {
            a[i] = n*(i+1);
            if (i<256) {
                b[i] = n*(i+1);
            } else {
                b[i] = n*i;
            }
        }
        printf("%d\n", memcmp(a, b, 256)==0);
        printf("%d\n", memcmp(a, b, 1024)!=0);
        printf("%d\n", a==memmove(a+256, b+256, 768));
        printf("%d\n", memcmp(a, b, 1024)==0);
       );

    /* fp */
    float f1 = (float)n, f2 = (float)n*2;
    RUN(printf("%f\n", f1));
    RUN(printf("%f\n", f2));
    RUN(printf("%f\n", f1/12.9898));
    RUN(printf("%f\n", f2/12.9898));

    return 0;
}

#include <stdio.h>

int main()
{
    int i;
    int j=0;

    for (i=0; i<=100000; i++) {
        j+=i;
    }
    printf("%d\n", j);
    return j;
}

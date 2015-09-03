#include <stdio.h>
int main()
{
    unsigned int i,j,count=0, n=20000;

    for(i=0;i<=1000000000;i++) {
       j+=i;
       j*=2;
    }

    return j;
}

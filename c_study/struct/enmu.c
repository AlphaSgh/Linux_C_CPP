#include <stdlib.h>
#include <stdio.h>

enum week
{
    MON = 1,
    TUS,
    THR,
    WES,
    FRI,
    SAT,
    SUN
};

int main(void)
{
    enum week a = FRI;
    printf("FRI = %d\n", a);
    exit(0);
}
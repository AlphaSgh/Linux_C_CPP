#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415926

int main(void)
{
    //存储类型 auto static register(建议型，一般不适用) extern(说明型) 
    int r = 5;
    double c = 2 * PI * r;
    double s = PI * r * r;
    printf("c = %.2f, s = %.2f\n", c, s);
    exit(0);
}
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define NAMESIZE 32

struct simple_st
{
    int i, j;
    float f;
    char ch;
};

struct birthday_st
{
    int year;
    int month;
    int day;
};

struct student_st
{
    int id;
    char name[NAMESIZE];
    struct birthday_st birth;
    int math;
    int chinese;
};

union test_un
{
    int i;
    float f;
    // double d;
    char ch;
};

union
{
    struct
    {
        uint16_t i;
        uint16_t j;
    } y;
    uint32_t x;
    
} a;


int main(void)
{
    a.x = 0x11223344;
    printf("%#x\n", a.y.i + a.y.j);
    #if 0
    union test_un a;
    union test_un* p = &a;
    a.f = 34.33f;
    printf("%zd\n", sizeof(a));
    printf("%.2f\n", p->f);
    #endif
    #if 0
    struct simple_st a = {123, 456, 12.34, 'A'};
    printf("%d %d %.2f %c\n", a.i, a.j, a.f, a.ch);
    struct birthday_st bir = {1999, 02, 01};
    struct student_st stu1 = {200200, "sgh", bir, 90, 90};
    struct student_st stu2 = {200201, "sgh", bir, 90, 90};
    struct student_st stu_arr[2] = {stu1, stu2};
    struct student_st* p = stu_arr;
    printf("sizeof(struct) = %zd\n", sizeof(stu_arr));
    printf("sizeof(point) = %zd\n", sizeof(p));
    for (size_t i = 0; i < sizeof(stu_arr) / sizeof(*stu_arr); i++)
    {
        printf("%d %s %d-%d-%d %d %d\n", (p + i)->id, (p + i)->name, (p + i)->birth.year, (p + i)->birth.month, (p + i)->birth.day, (p + i)->math, (p + i)->chinese);
    }
    #endif
    exit(0);
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NAMESIZE 32

struct student_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};

void stu_set(struct student_st* p, struct student_st* q)
{
    p->id = q->id;
    strncpy(p->name, q->name, strlen(q->name));
    p->math = q->math;
    p->chinese = q->chinese;
}
void stu_show(struct student_st* p)
{
    printf("%d %s %d %d\n", p->id, p->name, p->math, p->chinese);
}
void stu_change_name(struct student_st* p, const char* name)
{
    strncpy(p->name, name, strlen(name));
}
int main(void)
{
    struct student_st stu, tmp;
    printf("enter the stu\n");
    scanf("%d %s %d %d", &tmp.id, tmp.name, &tmp.math, &tmp.chinese);
    stu_set(&stu, &tmp);
    stu_show(&stu);
    char newname[32];
    printf("enter the new name:\n");
    scanf("%s", newname);
    stu_change_name(&stu, newname);
    stu_show(&stu);
    exit(0);
}
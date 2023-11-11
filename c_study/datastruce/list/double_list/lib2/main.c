#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <llist.h>

#define NAMESIZE 32

typedef struct stu_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
} student;

static void print_student(const void *s)
{
    const student *stu = s;
    printf("id: %2d name: %s math: %2d chinese: %2d\n", stu->id, stu->name, stu->math, stu->chinese);
}
static int id_cmp(const void *key, const void *record)
{
    const int *k = key;
    const student *stu = record;
    // printf("%s:%d\n",__FUNCTION__, (*k) - stu->id);
    return ((*k) - stu->id);
}
static int name_cmp(const void *key, const void *record)
{
    const char *k = key;
    const student *stu = record;
    // printf("%s: %s %s\n",__FUNCTION__, (k), stu->name);
    return strcmp(k, stu->name);
}
static int math_cmp(const void *key, const void *record)
{
    const int *k = key;
    const student *stu = record;
    // printf("%s:%d\n",__FUNCTION__, (*k) - stu->math);
    return ((*k) - stu->math);
}
static int chinese_cmp(const void *key, const void *record)
{
    const int *k = key;
    const student *stu = record;
    // printf("%s:%d\n",__FUNCTION__, (*k) - stu->chinese);
    return ((*k) - stu->chinese);
}
int main(void)
{
    LLIST *handler;
    student temp;
    handler = llist_create(sizeof(student));
    for (size_t i = 0; i < 10; i++)
    {
        temp.id = i;
        snprintf(temp.name, NAMESIZE, "student%zd", i);
        temp.math = rand() % 100;
        temp.chinese = rand() % 100;
        // llist_insert(handler, &temp, LLIST_FORWARD);
        llist_insert(handler, &temp, LLIST_BACKWARD);
    }
    
    llist_travel(handler, print_student);
    printf("\n\n");
    // int stu_id;
    // printf("please enter the student id: ");
    // scanf("%d", &stu_id);
    // student *stu;
    // stu = llist_find(handler, &stu_id, id_cmp);
    // if (stu == NULL)
    // {
    //     printf("the student of id = %d is not found\n", stu_id);
    // }
    // else
    // {
    //     print_student(stu);
    // }
    student *stu1;
    char *f_name = "student3";
    stu1 = malloc(sizeof(*stu1));
    int res = llist_fetch(handler, f_name, name_cmp, stu1);  
    printf("res = %d\n\n", res);
    print_student(stu1);  
    llist_travel(handler, print_student);
    llist_destory(handler);

    exit(0);
}
#ifndef __SQLSTACK_H__
#define __SQLSTACK_H__

#define MAXSIZE 5
#define datatype int

typedef struct sqstack_st
{
      datatype data[MAXSIZE];
      int top;
} sqlstack;

sqlstack *st_create(void);

int st_isempty(sqlstack *);

int st_push(sqlstack *, datatype *);
int st_pop(sqlstack *, datatype *);
int st_top(sqlstack *, datatype *);

void st_travel(sqlstack *);
void st_destory(sqlstack *);

#endif
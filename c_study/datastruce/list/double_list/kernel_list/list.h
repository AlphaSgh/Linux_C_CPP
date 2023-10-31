#ifndef __LINUX_LIST_H__
#define __LINUX_LIST_H__

struct list_head
{
      struct list_head *prev;
      struct list_head *next;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }
 
#define LIST_HEAD(name) \
     struct list_head name = LIST_HEAD_INIT(name)



static inline void __list_add(struct list_head *new1, struct list_head *prev, struct list_head *next)
{
    next->prev = new1;
    new1->next = next;
    new1->prev = prev;
    prev->next = new1;
}


static inline void list_add(struct list_head *new1, struct list_head *head)
{
      __list_add(new1, head, head->next);
}

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({              \
     const typeof(((type *)0)->member) *__mptr = (void *)(ptr);                   \
     ((type *)((char *)__mptr - offsetof(type, member))); })

#define list_entry(ptr, type, member) container_of(ptr, type, member)


#define __list_for_each(pos, head) \
      for (pos = (head)->next; pos != (head); pos = pos->next)
#endif
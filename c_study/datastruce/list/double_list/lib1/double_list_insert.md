```c
// p -- q -- m
q->prev = p;
q->next = p.next;
q->prev->next = q;
q->next->prev = q;

// m -- q -- p
q->next = p;
q->prev = p->prev;
q->prev->next = q;
q->next->prev = q;
```
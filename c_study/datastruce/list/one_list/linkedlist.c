#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

linkedlist* list_create()
{
    linkedlist *head;
    head = malloc(sizeof(*head));
    if (head == NULL)
    {
        return NULL;
    }
    head->next = NULL;
    return head;
}

int list_insert_at(linkedlist *head, int index, datatype *data)
{
    if (head == NULL)
    {
        return -1;
    }
    
    linkedlist *temp = head, *newnode;
    for (size_t i = 0; i < index && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp)
    {
        newnode = malloc(sizeof(*newnode));
        if (newnode == NULL)
        {
            return -2;
        }
        newnode->data = *data;
        newnode->next = temp->next;
        temp->next = newnode;
        return 0;
    }
    else
    {
        return -3;
    }
    
}
int list_order_insert(linkedlist *head, datatype *data)
{
    if (head == NULL)
    {
        return -1;
    }
    linkedlist *newnode;
    newnode = malloc(sizeof(*newnode));
    newnode->data = *data;
    linkedlist *temp = head;
    while (temp->next != NULL && temp->next->data < *data)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return 0;
}

int list_delete_at(linkedlist *head, int index)
{
    if (head == NULL)
    {
        return -1;
    }
    linkedlist *temp = head;
    for (size_t i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    linkedlist *f = temp->next;
    temp->next = temp->next->next;
    free(f);
    return 0;
}
int list_delete(linkedlist *head, datatype *data)
{
    if (head == NULL)
    {
        return -1;
    }
    linkedlist *temp = head, *pre = head, *cur = head->next;
    int i = 0;
    while (temp->next != NULL)
    {
        if (temp->next->data == *data)
        {
            linkedlist *f = temp->next;
            temp->next = temp->next->next;
            free(f);
            i++;
            continue;
        }
        temp = temp->next; 
    }
    printf("i = %d\n", i);
    return i; // delete node nums
}

int list_isempty(linkedlist *head)
{
    if (head->next == NULL)
    {
        return 0;
    }
    return 1;
}

void list_show(linkedlist *head)
{
    if (head == NULL)
    {
        return;
    }
    linkedlist *temp = head;
    temp = temp->next;
    while (temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}
void list_destory(linkedlist **head)
{
    if (*head == NULL)
    {
        return;
    }
    linkedlist *temp, *cur = (*head)->next;
    while (cur != NULL)
    {
        temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(*head);
}
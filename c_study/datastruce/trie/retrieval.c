#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FNAME   "log"
#define SIZE    128
#define BUFFERSIZE 256
typedef struct node_st
{
    struct node_st *ch[26];
    char desc[SIZE];
} Tree;
int get_word(FILE *fp, char *key, char *desc)
{
    char buf[BUFFERSIZE];
    char *retp;

    retp = fgets(buf, BUFFERSIZE, fp);
    if (retp == NULL)
    {
        return -1;
    }
    size_t i = 0;
    for ( ; i < SIZE - 1 && buf[i] != ':'; i++)
    {
        key[i] = buf[i];
    }
    key[i] = '\0';
    i++;
    size_t j = 0;
    for ( ; j < SIZE - 1 && buf[i] != '\0'; i++, j++)
    {
        desc[j] = buf[i];
    }
    desc[j] = '\0';
    return 0;
}
struct node_st *newnode()
{
    struct node_st *node;
    node = malloc(sizeof(*node));
    if (node == NULL)
    {
        return NULL;
    }
    node->desc[0] = '\0';
    for (size_t i = 0; i < 26; i++)
    {
        node->ch[i] = NULL;
    }
    return node;
    
}
int insert(struct node_st **root, char *key, char *desc)
{
    if (*root == NULL)
    {
        *root = newnode();
        if (*root == NULL)
        {
            return -1;
        }
        
    }
    if (*key == '\0')
    {
        strcpy((*root)->desc, desc);
        return 0;
    }
    
    return insert((*root)->ch + (*key - 'a'), key + 1, desc);
    
}
char *find(struct node_st *root, char *key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (*key == '\0')
    {
        return root->desc;
    }
    return find(root->ch[*key - 'a'], key + 1);
}
int main()
{
    FILE *fp;
    struct node_st *tree;
    char desc[SIZE];
    char key[SIZE];
    fp = fopen(FNAME, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "fopen():error\n");
        exit(1);
    }
    int ret;
    while (1)
    {
        ret = get_word(fp, key, desc);
        if (ret == -1)
        {
            break;
        }
        insert(&tree, key, desc);
    }
    char *datap = NULL;
    datap = find(tree, "pig");

    if (datap == NULL)
    {
        printf("can find\n");
    }
    else
    {
        puts(datap);
    }
    
    fclose(fp);
    exit(0);
}

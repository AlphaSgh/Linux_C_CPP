#include <stdlib.h>
#include <stdio.h>
#include <queue.h>
#define NAMESIZE 32

/**
 * 树中的节点所存放的值
*/
typedef struct student_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
}Student;
/**
 * 树的节点
*/
typedef struct node_st
{
    Student data;
    struct node_st *left, *right;
}Tree;

/**
 * 打印树中的节点的值
*/
void print_s(Student *stu)
{
    printf("id: %d name: %s math: %d chinese: %d\n", stu->id, stu->name, stu->math, stu->chinese);
}
/**
 * 向树中插入节点
*/
int insert(Tree **root, Student *data)
{
    Tree *node;
    if (*root == NULL)
    {
        node = malloc(sizeof(*node));
        if (node == NULL)
        {
            return -1;
        }
        else
        {
            node->data = *data;
            node->left = NULL;
            node->right = NULL;
            *root = node;
            return 0;
        }
        
    }
    
    if (data->id <= ((*root)->data).id)
    {
        return insert(&(*root)->left, data);
    }
    else
    {
        return insert(&(*root)->right, data);
    }
}
/**
 * 在树中查找节点
*/
Student *find(Tree *root, int id)
{
    if (root == NULL)
    {
        return NULL;
    }
    
    if (id == root->data.id)
    {
        return &root->data;
    }
    if (id < root->data.id)
    {
        return find(root->left, id);
    } 
    else
    {
        return find(root->right, id);
    }
    
}
/**
 * 获取树的节点个数
*/
static int get_high(Tree *root)
{ 
    if (root == NULL)
    {
        return 0;
    }
    return get_high(root->left) + 1 + get_high(root->right);
}
/**
 * 获取左子树中最左边的节点
*/
static Tree *find_min(Tree *root)
{
    if (root->left == NULL)
    {
        return root;
    }
    return find_min(root->left);
}
/**
 * 树进行左旋
*/
static void turn_left(Tree **root)
{
    Tree *cur = *root;
    *root = cur->right;
    cur->right = NULL;
    find_min(*root)->left = cur;
}
/**
 * 获取右子树中最右边的节点
*/
static Tree *find_max(Tree *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    return find_max(root->right);
}
/**
 * 树进行右旋
*/
static void turn_right(Tree **root)
{
    Tree *cur = *root;
    *root = cur->left;
    cur->left = NULL;
    find_max(*root)->right = cur;
}
/**
 * 对数进行平衡，生成平衡二叉树
*/
void balance(Tree **root)
{
    if (*root == NULL)
    {
        return;
    }
    while (1)
    {
        int sub = get_high((*root)->left) - get_high((*root)->right);
        if (sub >= -1 && sub <= 1)
            break;
        if (sub < -1)
        {
            turn_left(root);
        }
        else
        {
            turn_right(root);
        }
    }
    balance(&(*root)->left);
    balance(&(*root)->right);
}
void delete(Tree **root, int id) 
{
    Tree **node = root;
    Tree *cur = NULL;
    while (*node != NULL && (*node)->data.id != id)
    {
        if (id < (*node)->data.id)
        {
            node = &(*node)->left;
        }
        else
        {
            node = &(*node)->right;
        }
    }
    if (*node == NULL)
    {
        return;
    }
    cur = *node;
    if (cur->left == NULL)
    {
        *node = cur->right;
    }
    else
    {
        *node = cur->left;
        find_max(cur->left)->right = cur->right;
    }
    free(cur);
}
/**
 * 二叉树的遍历前中后序遍历
*/
void travel(Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    print_s(&root->data);
    travel(root->left);
    travel(root->right);
}
/**
 * 二叉树的层序遍历
*/
void travel_ceng(Tree *root)
{
    int ret;
    QUEUE *queue;
    Tree *cur;
    queue = queue_create(sizeof(Tree *));
    if (queue == NULL)
    {
        return;
    }
    queue_add(queue, &root);
    while (1)
    {
        ret = queue_remove(queue, &cur);
        if (ret == -1)
        {
            break;
        }
        print_s(&cur->data);
        if (cur->left != NULL)
        {
            queue_add(queue, &cur->left);
        }
        if (cur->right != NULL)
        {
            queue_add(queue, &cur->right);
        }
    }
    queue_destory(queue);
}
int main(void)
{
    int arr[] = {1,2,3,7,6,5,9,8,4};
    Tree *tree = NULL;
    Student tmp;
    for (size_t i = 0; i < sizeof(arr) / sizeof(*arr); i++)
    {
        tmp.id = arr[i];
        snprintf(tmp.name, NAMESIZE, "stu%d", arr[i]);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;
        insert(&tree, &tmp);
    }
    int tmpid = 19;
    Student *tmpStu = find(tree, tmpid);
    if (tmpStu == NULL)
    {
        printf("the student is not find\n");
    }
    else
    {
        print_s(tmpStu);
    }
    printf("\n");
    travel(tree);
    printf("\n");
    balance(&tree);
    travel(tree);
    printf("\n");
    travel_ceng(tree);
    int deleteId = 5;
    delete(&tree, deleteId);
    travel(tree);
    printf("\n");
    balance(&tree);
    travel(tree);
    exit(0);
}
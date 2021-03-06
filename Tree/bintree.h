#include <stdio.h>
#include <stdlib.h>

#define N 100
char *a = "ABC##D#E##F##";     /*存放扩充二叉树的前序序列*/
//char *a="ABC##D##EF#G###";          /*扩充二叉树序树t的前序序列*/
typedef struct node /*二叉树结构定义*/
{
    char data;
    struct node *lchild, *rchild;
} binnode;


/*函数createbintree (根据扩充二叉树的前序序列(字符串a)
 * 建立二叉树t的存储结构*/
binnode *createbintree() {
    char ch = *a++;
    binnode *t;
    if (ch == '#')
        t = NULL;
    else {
        t = (binnode*) malloc(sizeof(binnode));
        t->data = ch;
        t->lchild = createbintree();
        t->rchild = createbintree();
    }
    return t;
}


/*顺序栈定义*/
typedef struct {
    binnode *data[N];
    int top;
    int tag[N];
} seqstack;

void init(seqstack *s)   /*初始化空栈*/
{
    s->top = -1;
}

int empty(seqstack *s)   /*判断栈是否为空*/
{
    if (s->top > -1) return 0;
    else return 1;
}

int full(seqstack *s)   /*判断栈是否为满*/
{
    if (s->top == N - 1) return 1;
    else return 0;
}

void push(seqstack *s, binnode *x)   /*进栈*/
{
    if (!full(s)) {
        s->top++;
        s->data[s->top] = x;
    }
}

binnode *pop(seqstack *s)            /*出栈*/
{
    if (!empty(s)) {
        s->top--;
        return s->data[s->top + 1];
    }
}

void preorder(binnode *t){ //前序遍历的递归算法
    if (t)
    {
        printf("%c",t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}
void inorder(binnode *t)
{
    if (t)
    {
        inorder(t->lchild);
        printf("%c",t->data);
        inorder(t->rchild);
    }
}
void postorder(binnode *t)
{
    if (t)
    {
        postorder(t->lchild);
        postorder(t->rchild);
        printf("%c",t->data);
    }
}

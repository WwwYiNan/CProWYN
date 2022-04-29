#include "stdio.h"
#include "stdlib.h"

typedef char BiElemType;
typedef struct BiTNode{
    BiElemType c;//data值
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

typedef struct tag{
    BiTree p;//树的某一个结点的地址值
    struct tag *pnext;
}tag_t,*ptag_t;
//栈的相关数据结构
#define MaxSize 50
typedef BiTree ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;
}SqStack;
//队列相关的数据结构
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode,*PLinkNode;
typedef struct {
    LinkNode *front,*rear;
}LinkQueue;

void InitQueue(LinkQueue &Q)
{
    Q.rear = Q.front = 0;
}
bool IsEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear)
        return true;
    return false;
}
//入队
bool EnQueue(LinkQueue *Q,ElemType x)
{
    PLinkNode s = (PLinkNode) malloc(sizeof (LinkNode));
    if(!s) return false;
    s->data = x;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear =s;
    return true;
}
//出队
bool DeQueue(LinkQueue *Q,ElemType &x)
{
    PLinkNode p;
    if(IsEmpty(*Q))
        return false;
    p = Q->front->next;
    x = p->data;
    Q->front->next = p->next;
    if(Q->rear = p) Q->rear = Q->front;
    free(p);
    return true;
}

//初始化栈
void InitStack(SqStack &S){
    S.top = -1;//代表栈为空
}
//判断栈是否为空
bool StackEmpty(SqStack S)
{
    if (-1 == S.top)
        return true;
    return false;
}
//出栈
bool Pop(SqStack &S,ElemType &x)
{
    if(StackEmpty(S)) return false;
    x = S.data[S.top --];
}
//入栈
bool Push(SqStack &S,ElemType x)
{
    if(S.top == MaxSize-1) return false;

    S.data[++S.top] = x;
    return true;//返回true表示入栈成功
}

//前序遍历（递归实现）
void preOrder(BiTree p)
{
    if(p != NULL)
    {
        putchar(p->c);//等价于visit函数
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}
//中序遍历（递归实现）
void InOrder(BiTree p)
{
    if(p != NULL)
    {
        InOrder(p->lchild);
        putchar(p->c);
        InOrder(p->rchild);
    }
}
//中序遍历（非递归实现）,执行效率更高
void InOrder2(BiTree T)
{
    SqStack S;
    InitStack(S);
    BiTree p=T;
    while(p || !StackEmpty(S))
    {
        if(p)
        {//不断压栈的过程找到了最左边的节点
            Push(S,p);
            p = p->lchild;
        }else{
            Pop(S,p);
            putchar(p->c);
            p=p->rchild;
        }
    }

}
//后序遍历（递归实现）
void PostOrder(BiTree p)
{
    if(p != NULL)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        putchar(p->c);
    }
}
//层次遍历，层序遍历，广度优先遍历
void LevelOrder(BiTree T)
{
    LinkQueue Q;//辅助队列
    InitQueue(Q);//初始化队列
    BiTree p;
    EnQueue(&Q,T);//树根入队
    while (!IsEmpty(Q))
    {
        DeQueue(&Q,p);
        putchar(p->c);
        if(p->lchild != NULL) EnQueue(&Q,p->lchild);
        if(p->rchild != NULL) EnQueue(&Q,p->rchild);
    }

}
int main()
{
    BiTree pnew;//接收新节点
    int i,j,pos;
    char c;
    BiTree tree = NULL;//树根
    ptag_t phead=NULL,ptail=NULL,listpnew,pcur;//队列头队列尾
    //abcdefg
    while(scanf("%c",&c)!=EOF)
    {
        if (c == '\n') break;
        //calloc申请空间并对空间进行初始化，赋值为0
        pnew = (BiTree) calloc(1,sizeof(BiTNode));
        pnew ->c = c;
        listpnew = (ptag_t) calloc(1,sizeof(tag_t));//给队列结点申请空间
        listpnew->p = pnew;
        if (NULL == tree)
        {
            tree = pnew;//树的根
            phead = listpnew;//队列头
            ptail = listpnew;//队列尾
            pcur = listpnew;
            continue;
        }else{
             ptail ->pnext = listpnew;//新结点放入链表，通过尾插法
             ptail = listpnew;
        }//pcur始终指向要插入的结点的位置
        if(NULL == pcur->p->lchild)
            pcur->p->lchild = pnew;//把新结点放到要插入结点的左边
        else if(NULL == pcur->p->rchild) {
            pcur->p->rchild = pnew;//把新结点放到要插入结点的右边
            pcur = pcur->pnext;//左右都放了结点后，pcur指向队列的下一个结点
        }
    }
    // abcdefghij
    //先打印结点--->打印左节点--->打印右节点
    printf("---------前（先）序遍历--------\n");
    preOrder(tree);
    //先打印左节点----打印父亲节点----打印右节点
    printf("\n---------中序遍历--------\n");
    InOrder(tree);
    InOrder2(tree);
    //先打印左节点----打印右节点----打印父亲节点
    printf("\n---------后序遍历--------\n");
    PostOrder(tree);
//    LevelOrder(tree);


    return 0;
}

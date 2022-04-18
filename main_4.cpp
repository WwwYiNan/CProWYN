//输入
//4 3 4 -5 2  6 1  -2 0
//3 5 20  -7 4  3 1
//输出
//5 20 -4 4 -5 2 9 1 -2 0

#include "stdio.h"
#include "stdlib.h"
typedef int ElemType;

typedef struct LNode{
    ElemType coef;//系数 coefficient
    ElemType expon;//指数 exponent
    struct LNode * next;
}LNode ,* LinkList;
void Attach(int c, int e, LinkList * rear);//将新读入的系数和指数加到多项式的末尾
LinkList ReadList();//读入多项式
LinkList AddList(LinkList P1, LinkList P2);//计算两个多项式之和
void PrintList(LinkList P);
int main()
{
    LinkList P1 = ReadList();
    LinkList P2 = ReadList();
    LinkList PA = AddList(P1, P2);
    PrintList(PA);
}
void Attach(ElemType c, ElemType e, LinkList * rear)
{
    LinkList input = (LinkList)malloc(sizeof(struct LNode));
    //申请新节点并赋初值
    input->coef = c;
    input->expon = e;
    input->next = NULL;
    (*rear)->next = input;
    *rear = input; //修改末尾指针，因为是修改指针，故此处使用指针的指针
}
//获取多项式
LinkList ReadList()
{
    LinkList P1, rear, t;
    int N;//多项式项数
    ElemType c,e;//用来暂存系数和指数
    P1 = (LinkList)malloc(sizeof(struct LNode));//申请头节点
    //申请头节点是为了方便使用Attach函数时，不用区分rear是空还是非空，有了头节点都是非空，插入方便
    P1->next = NULL;

    rear = P1;//尾指针指向头节点
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d %d",&c, &e);
        Attach(c, e, &rear);
    }
    t = P1;
    P1 = P1->next;
    free(t);//头节点方便插入的使命完成，释放头节点
    return P1;
}
//加法计算
LinkList AddList(LinkList P1, LinkList P2)
{
    LinkList t1,t2,rear,t;
    t1 = P1;
    t2 = P2;
    LinkList P = (LinkList)malloc(sizeof(struct LNode));
    P->next = NULL;
    rear = P;
    while(t1 && t2)
    {
        if(t1->expon == t2->expon)//如果指数相同则进行相加
        {
            if(t1->coef + t2->coef)//如果系数相加不为零，则将计算结果加入P中
            {
                Attach(t1->coef + t2->coef, t1->expon, &rear);
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        else if(t1->expon > t2->expon)//找到指数大的加入到P中
        {

            Attach(t1->coef, t1->expon, &rear);
            t1 = t1->next;
        }
        else
        {
            Attach(t2->coef, t2->expon, &rear);
            t2 = t2->next;
        }
    }
    while(t1)//如果t1还有多余节点，则继续加入
    {
        Attach(t1->coef, t1->expon, &rear);
        t1 = t1->next;
    }
    while(t2)//如果t2还有多余节点，则继续加入
    {
        Attach(t2->coef, t2->expon, &rear);
        t2 = t2->next;
    }
    t = P;
    P = P->next;
    free(t);//释放头节点
    return P;
}
//打印
void PrintList(LinkList P)
{
    int flag = 0;
    if(!P)
    {
        printf("0 0\n");
        return;
    }
    while(P)
    {
        if(!flag)
            flag = 1;
        else
            printf(" ");
        printf("%d %d",P->coef, P->expon);
        P = P->next;
    }
    printf("\n");
}
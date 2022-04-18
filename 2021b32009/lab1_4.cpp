#include "stdio.h"
#include "stdlib.h"
#include "SLinkNode.h"
void insert(SLinkNode* &L ,ElemType x)
{
    SLinkNode *p,*q,*s;//要插入的数据s，位于p和q之间
    s = (SLinkNode*) malloc(sizeof (node));
    s ->data = x;
    p = L->next;
    q = L;
    while(p && p ->data <x)
    {
        q = p;
        p = p->next;
    }
    q->next =s;
    s ->next = p;

}
int main()
{   ElemType x;
    SLinkNode *L;
    ElemType a[]={90,80,70,60,50,40,30,20,10,5};
    CreateListF(L,a,10); /*头插入法建立带头结点的单链表，请补充完整*/
    DispList (L);					/*输出原链表*/
    printf("请输入要插入的值：");
    scanf("%d",&x);
    insert(L,x);		/*将输入的值插入到带头结点的单链表适当位置*/
    DispList (L);					/*输出数据插入后的单链表*/;
    DestroyList(L);           /*释放带头结点的单链表*/
    return 0;
}


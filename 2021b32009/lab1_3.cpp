#include "stdio.h"
#include "stdlib.h"
#include "SlinkNode.h"
/*以单链表  head->1->2->3->4->NULL为例）：
1、断开head->1的指针
2、将2放到1前，此时   2->1->NULL
3、将3放到2前，此时   3->2->1->NULL
4、将4放到3前，此时   4->3->2->1->NULL
5、重新添加头结点head，实现逆置：head->4->3->2->1->NULL*/
void reverse(SLinkNode * &L)
{
    SLinkNode *p = L->next,*q,*t;
    q = NULL;t = NULL;
    L -> next = NULL;   //断开头结点
    while(p != NULL) //从第一个节点起，将后边的结点一次放到最前面
    {
        t = p->next;
        p->next = q;
        q = p;
        p = t;
    }
    L->next = q; //重新链接上头结点
}
int main()
{   ElemType x;
    SLinkNode *L;
    ElemType a[]={22,5,39,89,20,15,94,57,83,67};
    CreateListR(L,a,10); /*尾插入法建立带头结点的单链表，请补充完整*/
    DispList (L);					/*输出原链表*/
    reverse(L);			    /*倒置单链表*/
    DispList (L);					/*输出倒置后的链表*/
    DestroyList(L);           /*释放带头结点的单链表*/
    return 0;
}


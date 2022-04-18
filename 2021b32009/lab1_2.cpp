#include "SlinkNode.h"

void del(SLinkNode &L)
{
    SLinkNode *p = L.next,*q;
    while(p->next !=NULL)
    {
        if (p->data ==p->next->data)
        {
            q = p->next;
            p->next = q ->next;
            free(q);
        }
        else
            p =p->next;
    }
}
int main()
{
    SLinkNode* L;
    ElemType a[] = {3,3,4,4,5,6,7,8,9};
    CreateListR(L,a,9);
    DispList(L);
    del(*L);
    DispList(L);
}


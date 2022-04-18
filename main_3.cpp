#include "stdio.h"
#include "stdlib.h"

typedef int ElemType;
typedef struct DNode{  //双链表节点类型
    ElemType data;
    struct DNode *prior,*next;//前驱指针,后继指针
} DNode,*DLinkList;
//头插
DLinkList Dlist_head_insert(DLinkList &DL)
{
    DNode *s;
    int x;
    DL = (DLinkList) malloc(sizeof(DNode));//带头结点的链表
    DL ->next = NULL;
    DL ->prior = NULL;
    scanf("%d",&x);//从标准输入读取数据
    // 3 4 5 6 7 9999
    while(x!= 9999)
    {
        s = (DLinkList) malloc(sizeof(DNode));//申请一个空间，强制类型转换
        s ->data = x;
        s ->next = DL ->next;
        if(DL ->next != NULL)
            DL->next->prior = s;
        s ->prior = DL;//要插入的结点指向头结点
        DL ->next = s;
        scanf("%d",&x);
    }
    return DL;
}
//尾插
DLinkList Dlist_tail_insert(DLinkList &DL)
{
    int x;
    DL = (DLinkList) malloc(sizeof(DNode));//带头节点的链表
    DNode *s,*r = DL;//r代表尾指针
    DL ->prior = NULL;
    scanf("%d",&x);
    while(x != 9999)
    {
        s = (DNode *) malloc(sizeof(DNode));
        s ->data = x;
        r ->next = s;
        s ->prior = r;
        r = s;//r指向新的表尾结点
        scanf("%d",&x);
    }
    r ->next = NULL;
    return DL;
}
//按序号查找节点值
DNode *GetElem(DLinkList L, int i) {
    int j = 1;
    DNode *p = L->next;
    if (0 == i)
        return L; //i是零就返回头结点
    if (i < 1)
        return NULL; //i是负值就返回空
    while (p && j < i) {
        p = p->next; //让p指向下一个节点
        j++;
    }
    return p;
}

//按值查找
DLinkList LocateElem(DLinkList L, ElemType e) {
    DLinkList p = L->next;
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}
//新结点插入第i个位置
bool DListFrontInsert(DLinkList DL,int i,ElemType e)
{
    DLinkList p = GetElem(DL,i-1);
    if(NULL == p)
        return false;
    DLinkList s = (DLinkList) malloc(sizeof(DNode));
    s ->data =e;
    s ->next = p ->next;
    p ->next->prior = s;
    s ->prior = p;
    p ->next = s;
    return true;
}
//删除第i个结点
bool DListDelete(DLinkList DL,int i)
{
    DLinkList  p = GetElem(DL,i-1);
    if (NULL == p)
        return false;
    DLinkList q;
    q = p ->next;
    if(NULL == q)//删除的元素不存在
        return false;
    p ->next = q ->next;//断链
    if (q->next != NULL)
        q ->next ->prior = p;
    free(q);//释放对应结点q的空间
    return DL;
}


//链表打印
void PrintDList(DLinkList DL)
{
    DL = DL ->next;
    while(DL != NULL)
    {
        printf("%3d",DL->data);
        DL = DL ->next;
    }
    printf("\n");
}


int main()
{
    DLinkList DL;
    DLinkList search;//用来存储拿到的某一个节点
//    DLinkList search;
    //3 4 5 6 7 9999
//    Dlist_head_insert(DL); //头插
    Dlist_tail_insert(DL); //尾插
    printf("尾插输入后的结果：");
    PrintDList(DL);

    search = GetElem(DL, 2); //按位置查找
    if (search != NULL) {
        printf("按序号查找成功\n");
        printf("%d\n", search->data);
    }
    search = LocateElem(DL, 6); //按值查找
    if (search != NULL) {
        printf("按值查找成功\n");
        printf("%d\n", search->data);
    }
    DListFrontInsert(DL,2,9);
    printf("在第二个位置插入9：");
    PrintDList(DL);
    DListDelete(DL,1);
    printf("删除第一个位置的元素：");
    PrintDList(DL);

}
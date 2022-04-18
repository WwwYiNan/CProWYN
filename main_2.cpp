#include "stdio.h"
#include "stdlib.h"

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;//指向下一个节点
} LNode, *LinkList;

//头插法新建链表
LinkList CreateList1(LinkList &L) {
    LNode *s;
    int x;
    L = (LinkList) malloc(sizeof(LNode));//带头结点的链表
    L->next = NULL; //L->data 里边没放东西
    scanf("%d", &x);//从标准输入读取数据
    // 3 4 5 6 7 999
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));//申请一个空间，强制类型转换
        s->data = x; //把读取到的值，给新空间中的data成员
        s->next = L->next; //让新节点的next指针指向原有的头部节点（链表的第一个元素）
        L->next = s;//让s作为第一个元素
        scanf("%d", &x);//读取标准输入
    }
    return L;
}

//尾插法新建链表
LinkList CreateList2(LinkList &L) {
    int x;
    L = (LinkList) malloc(sizeof(LNode));//带头结点的链表
    LNode *s, *r = L;
    //3 4 5 6 7 9999
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;//让尾部节点指向新节点
        r = s;//r指向新的表尾节点
        scanf("%d", &x);
    }
    r->next = NULL;//尾节点的next指针赋值为NULL
    return L;
}

//按序号查找节点值
LNode *GetElem(LinkList L, int i) {
    int j = 1;
    LNode *p = L->next;
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
LinkList LocateElem(LinkList L, ElemType e) {
    LinkList p = L->next;
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}

//新节点插入第i个位置
bool ListFrontInsert(LinkList L, int i, ElemType e) {
    LinkList p = GetElem(L, i - 1);
    if (NULL == p)
        return false; //i不对
    LinkList s = (LNode *) malloc(sizeof(LNode));//为新插入的结点申请空间
    s->data = e; //要插入的值放入空间
    s->next = p->next; //插入步骤
    p->next = s;
    return true;
}

//删除第i个结点
bool ListDelete(LinkList L, int i) {
    LinkList p = GetElem(L, i - 1);//查找删除位置的前驱元素
    if (NULL == p)
        return false; //要删除的位置不存在
    LinkList q = p->next;
    p->next = q->next; //断链
    free(q); //释放对应结点的空间
    q = NULL; //为了避免野指针
    return true;

}

//打印链表
void PrintList(LinkList L) {
    L = L->next;
    while (L != NULL) {
        printf("%-3d", L->data);
        L = L->next;
    }
    printf("\n");
}

int main() {
    LinkList L; //链表头，是结构体指针类型
    LinkList search;//用来存储拿到的某一个节点
//    CreateList1(L);//头插法
    CreateList2(L);//尾插法
    PrintList(L);
    search = GetElem(L, 2); //按位置查找
    if (search != NULL) {
        printf("按序号查找成功\n");
        printf("%d\n", search->data);
    }
    search = LocateElem(L, 6); //按值查找
    if (search != NULL) {
        printf("按值查找成功\n");
        printf("%d\n", search->data);
    }
    ListFrontInsert(L, 2, 99);
    PrintList(L);
    ListDelete(L, 3);
    PrintList(L);


    return 0;
}

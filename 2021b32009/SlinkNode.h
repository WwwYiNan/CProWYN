#include <malloc.h>
#include <stdio.h>
typedef int ElemType;
typedef struct node
{	ElemType data;		//数据域
	struct node *next;	//指针域
} SLinkNode;				//单链表类型
void InitList(SLinkNode *&L)				//L作为引用型参数
{	L=(SLinkNode *)malloc(sizeof(SLinkNode));	//创建头结点*L
	L->next=NULL;
}
void DestroyList(SLinkNode *&L)
{	SLinkNode *pre=L,*p=pre->next;
	while (p!=NULL)
	{	free(pre);
		pre=p; p=p->next;	//pre、p同步后移
	}
	free(pre);
}
void DispList(SLinkNode *L)		//输出单链表
{	SLinkNode *p=L->next;
	while (p!=NULL)
	{	printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
//采用头插法建表的算法
void CreateListF(SLinkNode *&L,ElemType a[],int n)
{	SLinkNode *s;  int i;
	L=(SLinkNode *)malloc(sizeof(SLinkNode));		//创建头结点
	L->next=NULL;			//头结点的next域置空，表示一个空单链表
	for (i=0;i<n;i++)		//遍历a数组所有元素
	{	s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=a[i];		//创建存放a[i]元素的新结点*s
		s->next=L->next;	//将*s插在头结点之后
		L->next=s;
	}
}
//采用尾插法建表的算法
void CreateListR(SLinkNode *&L,ElemType a[],int n)
{	SLinkNode *s,*tc;  int i;
	L=(SLinkNode *)malloc(sizeof(SLinkNode));	//创建头结点
	tc=L;						//tc始终指向尾结点,开始时指向头结点
	for (i=0;i<n;i++)
	{	s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=a[i];			//创建存放a[i]元素的新结点*s
		tc->next=s;				//将*s插入*tc之后
		tc=s;
	}
	tc->next=NULL;				//尾结点next域置为NULL
}


#include <malloc.h>
#include <stdio.h>
typedef int ElemType;
typedef struct node
{	ElemType data;		//������
	struct node *next;	//ָ����
} SLinkNode;				//����������
void InitList(SLinkNode *&L)				//L��Ϊ�����Ͳ���
{	L=(SLinkNode *)malloc(sizeof(SLinkNode));	//����ͷ���*L
	L->next=NULL;
}
void DestroyList(SLinkNode *&L)
{	SLinkNode *pre=L,*p=pre->next;
	while (p!=NULL)
	{	free(pre);
		pre=p; p=p->next;	//pre��pͬ������
	}
	free(pre);
}
void DispList(SLinkNode *L)		//���������
{	SLinkNode *p=L->next;
	while (p!=NULL)
	{	printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
//����ͷ�巨������㷨
void CreateListF(SLinkNode *&L,ElemType a[],int n)
{	SLinkNode *s;  int i;
	L=(SLinkNode *)malloc(sizeof(SLinkNode));		//����ͷ���
	L->next=NULL;			//ͷ����next���ÿգ���ʾһ���յ�����
	for (i=0;i<n;i++)		//����a��������Ԫ��
	{	s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=a[i];		//�������a[i]Ԫ�ص��½��*s
		s->next=L->next;	//��*s����ͷ���֮��
		L->next=s;
	}
}
//����β�巨������㷨
void CreateListR(SLinkNode *&L,ElemType a[],int n)
{	SLinkNode *s,*tc;  int i;
	L=(SLinkNode *)malloc(sizeof(SLinkNode));	//����ͷ���
	tc=L;						//tcʼ��ָ��β���,��ʼʱָ��ͷ���
	for (i=0;i<n;i++)
	{	s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=a[i];			//�������a[i]Ԫ�ص��½��*s
		tc->next=s;				//��*s����*tc֮��
		tc=s;
	}
	tc->next=NULL;				//β���next����ΪNULL
}


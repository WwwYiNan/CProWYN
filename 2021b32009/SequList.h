#include <stdio.h>
#define MaxSize 100
typedef int ElemType;			//����˳���������Ԫ��Ϊint����
typedef struct
{	ElemType data[MaxSize];		//���˳����Ԫ��
	int length;					//˳����ʵ�ʳ���
} SqList;						//˳�������
void InitList(SqList &L)	//����LҪ�ش���ֵ�Σ���������������
{
	L.length=0;
}
void DestroyList(SqList L)
{
}
void AAA(SqList &L) {
    for (int k = 0; k < L.length-1; ++k) {
            for (int i = k + 1; i < L.length; ++i) {
                if (L.data[k] == L.data[i]){
                    for (int j = i; j <L.length ; ++j) {
                        L.data[j] = L.data[j + 1];
                    }
                    L.length--;
            }
        }
    }
}
void DispList(SqList L)
{	int i;
	for (i=0;i<L.length;i++)
		printf("%d ",L.data[i]);
	printf("\n");
}
void CreateList(SqList &L,ElemType a[],int n)
{
	int i,k=0;						//k�ۼ�˳���L�е�Ԫ�ظ���
	for (i=0;i<n;i++)
	{
		L.data[k]=a[i];				//��L�����һ��Ԫ��
		k++;						//L��Ԫ�ظ�����1
	}
	L.length=k;						//����L�ĳ���
}

#include <stdio.h>
#define MaxSize 100
typedef int ElemType;			//假设顺序表中所有元素为int类型
typedef struct
{	ElemType data[MaxSize];		//存放顺序表的元素
	int length;					//顺序表的实际长度
} SqList;						//顺序表类型
void InitList(SqList &L)	//由于L要回传给值参，所以用引用类型
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
	int i,k=0;						//k累计顺序表L中的元素个数
	for (i=0;i<n;i++)
	{
		L.data[k]=a[i];				//向L中添加一个元素
		k++;						//L中元素个数增1
	}
	L.length=k;						//设置L的长度
}

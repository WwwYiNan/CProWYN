#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;//顺序表中元素的类型
//静态分配
typedef struct {
 ElemType data[MaxSize]; //定义的数组，用来存元素
 int length;  //当前顺序表中有多少个元素
}SqList;
//动态分配
#define InitSize 100
//在指定位置插入一个数
bool ListInsert(SqList &L,int i,ElemType e)
{
 if (i<1 || i>L.length + 1)//判断要插入的位置是否合法
  return false;
 if (L.length >= MaxSize)//超出空间了
  return false;
 for (int j = L.length; j >= i; j--)
 {
  L.data[j] = L.data[j - 1];
 }
 L.data[i - 1] = e;
 L.length++;
 return true;
}
//删除
bool ListDelete(SqList& L, int i,ElemType &e)
{
 if (i<1 || i>L.length)//判断要删除的位置是否合法
  return false;
 if (L.length == 0)//顺序表中无元素，无需删除
  return false;
 e = L.data[i - 1];//获取顺序表中对应的元素，赋值给e
 for (int j = i; j < L.length; j++)
  L.data[j - 1] = L.data[j];
 L.length--;
 return true;

}
//查找
int LocateElem(SqList L, ElemType e)
{
 for (int j = 0; j < L.length; j++)
  if (L.data[j] == e)
   return j + 1;
 return 0;
}
//打印
void PrintList(SqList& L)
{
 for (int i = 0; i < L.length; i++)
  printf("%3d",L.data[i]);
 printf("\n");
}

int main()
{
 SqList L;
 bool ret;
 ElemType del;//用来存要删除的元素
 //首先手动在顺序表中赋值
 L.data[0] = 1;
 L.data[1] = 2;
 L.data[2] = 3;
 L.length = 3;//总计三个元素
 //插入
 ret = ListInsert(L, 2, 60);
 if (ret)
 {
  printf("插入成功\n");
  PrintList(L);
 }
 else {
  printf("插入失败\n");
 }
 //删除
 ret = ListDelete(L, 3,del);
 if (ret)
 {
  printf("\n删除成功\n");
  PrintList(L);
  printf("删除元素值为%d\n", del);
 }
 else {
  printf("删除失败\n");
 }
 //查找
 int elem_pos;
 elem_pos = LocateElem(L, 1);
 if (elem_pos)
 {
  printf("\n查找成功\n");
  printf("元素位置为%d\n", elem_pos);
 }
 else
  printf("\n查找失败\n");

 return 0;
 }
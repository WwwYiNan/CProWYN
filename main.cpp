#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;//˳�����Ԫ�ص�����
//��̬����
typedef struct {
 ElemType data[MaxSize]; //��������飬������Ԫ��
 int length;  //��ǰ˳������ж��ٸ�Ԫ��
}SqList;
//��̬����
#define InitSize 100
//��ָ��λ�ò���һ����
bool ListInsert(SqList &L,int i,ElemType e)
{
 if (i<1 || i>L.length + 1)//�ж�Ҫ�����λ���Ƿ�Ϸ�
  return false;
 if (L.length >= MaxSize)//�����ռ���
  return false;
 for (int j = L.length; j >= i; j--)
 {
  L.data[j] = L.data[j - 1];
 }
 L.data[i - 1] = e;
 L.length++;
 return true;
}
//ɾ��
bool ListDelete(SqList& L, int i,ElemType &e)
{
 if (i<1 || i>L.length)//�ж�Ҫɾ����λ���Ƿ�Ϸ�
  return false;
 if (L.length == 0)//˳�������Ԫ�أ�����ɾ��
  return false;
 e = L.data[i - 1];//��ȡ˳����ж�Ӧ��Ԫ�أ���ֵ��e
 for (int j = i; j < L.length; j++)
  L.data[j - 1] = L.data[j];
 L.length--;
 return true;

}
//����
int LocateElem(SqList L, ElemType e)
{
 for (int j = 0; j < L.length; j++)
  if (L.data[j] == e)
   return j + 1;
 return 0;
}
//��ӡ
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
 ElemType del;//������Ҫɾ����Ԫ��
 //�����ֶ���˳����и�ֵ
 L.data[0] = 1;
 L.data[1] = 2;
 L.data[2] = 3;
 L.length = 3;//�ܼ�����Ԫ��
 //����
 ret = ListInsert(L, 2, 60);
 if (ret)
 {
  printf("����ɹ�\n");
  PrintList(L);
 }
 else {
  printf("����ʧ��\n");
 }
 //ɾ��
 ret = ListDelete(L, 3,del);
 if (ret)
 {
  printf("\nɾ���ɹ�\n");
  PrintList(L);
  printf("ɾ��Ԫ��ֵΪ%d\n", del);
 }
 else {
  printf("ɾ��ʧ��\n");
 }
 //����
 int elem_pos;
 elem_pos = LocateElem(L, 1);
 if (elem_pos)
 {
  printf("\n���ҳɹ�\n");
  printf("Ԫ��λ��Ϊ%d\n", elem_pos);
 }
 else
  printf("\n����ʧ��\n");

 return 0;
 }
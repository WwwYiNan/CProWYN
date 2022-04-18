#include "stdio.h"
#include "stdlib.h"

#define MaxSize 5
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front,rear;//队列头 队列尾
}SqQueue;
//初始化
void InitQueue(SqQueue &Q)
{
    Q.rear = Q.front = 0;
}
bool isEmpty(SqQueue Q)
{
    if(Q.front == Q.rear)
        return true;
    return false;
}
//入队
bool EnQueue(SqQueue &Q,ElemType x)
{
    if((Q.rear+1)%MaxSize == Q.front)
        return false;
    Q.data[Q.rear+1] = x;
    Q.rear = (Q.rear+1) % MaxSize;//向后移动一格
    return true;
}
//队列长度
int  QueueLength(SqQueue Q){
    return (Q.rear-Q.front+MaxSize)%MaxSize;
}
//打印队列
void PrintQueue(SqQueue Q)
{
    while(Q.front != Q.rear)
    {
        printf("%3d",Q.data[Q.front+1]);
        Q.front = Q.front+1;
    }
    printf("\n");
}
//出队
bool DeQueue(SqQueue &Q,ElemType &x)
{
    if(isEmpty(Q))
        return false;
    x = Q.data[Q.front+1];//先进先出
    Q.front = (Q.front+1) % MaxSize;
    return true;
}




int main()
{
    SqQueue Q;
    ElemType element;
    bool flag;
    InitQueue(Q);
    flag = isEmpty(Q);
    if(flag)
        printf("队列为空\n");

    EnQueue(Q,3);
    EnQueue(Q,4);
    printf("当前队列为：");
    PrintQueue(Q);
    EnQueue(Q,5);
    flag = EnQueue(Q,6);
    if(flag)
        printf("入队成功~~~\n");
    else
        printf("入队失败！！\n");
    flag = EnQueue(Q,7);
    if(flag)
        printf("入队成功~~~\n");
    else
        printf("入队失败！！\n");
    //打印队列
    printf("当前队列为：");
    PrintQueue(Q);
    printf("当前队列长度为%d\n",QueueLength(Q));
    //出队
    flag = DeQueue(Q,element);
    if(flag)
        printf("出队成功~~~，元素值为%d\n",element);
    else
        printf("出队失败！！\n");
    flag = DeQueue(Q,element);
    if(flag)
        printf("出队成功~~~，元素值为%d\n",element);
    else
        printf("出队失败！！\n");



    return 0;
}

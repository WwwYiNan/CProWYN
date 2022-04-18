#include "stdio.h"
#include "stdlib.h"

#define MaxSize 100
typedef int QElemType;
typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front, rear;
} LinkQueue;


/* 构造一个空队列Q */
void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (QueuePtr) malloc(sizeof(QNode));
    Q.front->next = NULL;
}

/* 求队列的长度 */
int QueueLength(LinkQueue Q) {
    int i = 0;
    QueuePtr p;
    p = Q.front;
    while (Q.rear != p) {
        i++;
        p = p->next;
    }
    return i;
}

bool EnQueue(LinkQueue &Q, QElemType e) {
    QueuePtr s = (QueuePtr) malloc(sizeof(QNode));
    if (!s)
        return false;
    s->data = e;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
    return true;
}

bool DeQueue(LinkQueue &Q, QElemType &e) {
    QueuePtr p;
    if (Q.front == Q.rear)
        return false;
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return true;
}

/* 从队头到队尾依次对队列Q中每个元素输出 */
void PrintQueue(LinkQueue Q) {
    QueuePtr p;
    p = Q.front->next;
    while (p) {
        printf("%3d", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int i;
    QElemType element;
    bool flag;
    LinkQueue Q;
    InitQueue(Q);
    printf("成功地构造了一个空队列!\n");
    printf("队列的长度为%d\n", QueueLength(Q));
    EnQueue(Q, -5);
    EnQueue(Q, 5);
    EnQueue(Q, 10);
    flag = EnQueue(Q, 7);
    if (flag)
        printf("入队成功~~~\n");
    else
        printf("入队失败！！\n");
    printf("插入4个元素(-5,5,10,7)后,队列的长度为%d\n", QueueLength(Q));
    printf("队列的元素依次为：");
    PrintQueue(Q);
    flag = DeQueue(Q, element);
    if (flag)
        printf("出队成功~~~，元素值为%d\n", element);
    else
        printf("出队失败！！\n");
    PrintQueue(Q);

    return 0;
}


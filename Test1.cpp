#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
typedef int datatype;
typedef struct QNode {
    datatype data;
    struct QNode *next;
} QNode;

typedef struct qptr {
    QNode *front; //队头指针
    QNode *rear;  //队尾指针
} LinkQueue;

int ShowMenu();

int ShowMenu1();

int InitQueue(LinkQueue *&Q) {

    Q = new LinkQueue;
    Q->front = NULL;
    Q->rear = NULL;
    return 1;

}

int QueueEmpty(LinkQueue *Q) {

    if (Q->front == NULL && Q->rear == NULL) {
        return 1;
    } else {
        return 0;
    }

}

int InQueue(LinkQueue *Q, datatype x) {

    QNode *p = new QNode;
    p->data = x;
    p->next = NULL;
    if (Q->front == NULL) Q->front = Q->rear = p;
    else {
        Q->rear->next = p;
        Q->rear = p;
    }
    return 1;

}

int OutQueue(LinkQueue *Q, datatype &x) {

    QNode *p;
    if (Q->front == NULL)
        return 0;
    p = Q->front;
    x = p->data;
    if (Q->front == Q->rear && Q->front != NULL) {
        Q->front = NULL;
        Q->rear = NULL;
        return 1;
    } else {
        Q->front = p->next;
        delete p;
        return 1;
    }

}

int ShowQueue(LinkQueue *Q) {
    QNode *p = Q->front;
    if (Q->front == NULL) return 0;
    else
        while (p) {
            printf("%d\n", p->data);
            p = p->next;
        }

}

int main() {
    LinkQueue *Q[4];
    int n, m, k, a;
    int count1 = -1, count2 = -1, count3 = -1, count4 = -1;
    //InitQueue(Q);
    while (1) {
        ShowMenu();
        scanf("%d", &n);
        if (n == 1) {//排队
            ShowMenu1();
            scanf("%d", &m);
            if (m == 1) {//内科
                InitQueue(Q[0]);
                printf("请输入病历号：\n");
                scanf("%d", &k);
                if (InQueue(Q[0], k) == 1) {
                    count1++;
                    printf("挂号成功请等候，您前面排队人数%d\n", count1);

                }
            } else if (m == 2) {
                InitQueue(Q[1]);
                printf("请输入病历号：\n");
                scanf("%d", &k);
                if (InQueue(Q[1], k) == 1) {
                    count2++;
                    printf("挂号成功请等候，您前面排队人数%d\n", count2);

                }
            } else if (m == 3) {
                InitQueue(Q[2]);
                printf("请输入病历号：\n");
                scanf("%d", &k);
                if (InQueue(Q[2], k) == 1) {
                    count3++;
                    printf("挂号成功请等候，您前面排队人数%d\n", count3);

                }
            } else if (m == 4) {
                InitQueue(Q[3]);
                printf("请输入病历号：\n");
                scanf("%d", &k);
                if (InQueue(Q[3], k) == 1) {
                    count4++;
                    printf("挂号成功请等候，您前面排队人数%d\n", count4);

                }
            }

        } else if (n == 2) {//就诊
            ShowMenu1();
            scanf("%d", &a);
            if (a == 1) {//内科
                if (count1 < 0) printf("该诊室尚无人排队\n");
                else {
                    if (OutQueue(Q[0], k) == 1)
                        count1--;
                    printf("请%d病人到内科看病\n", k);
                }

            } else if (a == 2) {
                if (count2 < 0) printf("该诊室尚无人排队\n");
                else {
                    if (OutQueue(Q[1], k) == 1)
                        count2--;
                    printf("请%d病人到内科看病\n", k);
                }

            } else if (a == 3) {
                if (count3 < 0) printf("该诊室尚无人排队\n");
                else {
                    if (OutQueue(Q[2], k) == 1)
                        count3--;
                    printf("请%d病人到内科看病\n", k);
                }

            } else if (a == 4) {
                if (count4 < 0) printf("该诊室尚无人排队\n");
                else {
                    if (OutQueue(Q[3], k) == 1)
                        count4--;
                    printf("请%d病人到内科看病\n", k);
                }

            }
        } else if (n == 3) {//查看排队
            ShowMenu1();
            scanf("%d", &a);
            if (a == 1) {
                if (count1 < 0) printf("该诊室尚无人排队\n");
                else {
                    count1++;
                    printf("该诊室排队人数%d：\n", count1);
                    ShowQueue(Q[0]);
                }
            } else if (a == 2) {
                if (count2 < 0) printf("该诊室尚无人排队\n");
                else {
                    count2++;
                    printf("该诊室排队人数%d：\n", count2);
                    ShowQueue(Q[1]);
                }

            } else if (a == 3) {
                if (count3 < 0) printf("该诊室尚无人排队\n");
                else {
                    count3++;
                    printf("该诊室排队人数%d：\n", count3);
                    ShowQueue(Q[2]);
                }

            } else if (a == 4) {
                if (count4 < 0) printf("该诊室尚无人排队\n");
                else {
                    count4++;
                    printf("该诊室排队人数%d：\n", count4);
                    ShowQueue(Q[3]);
                }

            }

        } else {
            break;
        }
    }

}

int ShowMenu() {

    printf("*****     排队系统     *****\n");

    printf("1 排队\n");

    printf("2 就诊\n");

    printf("3 查看排队\n");

    printf("4 下班\n");

    printf("*****     排队系统     *****\n");

    return 1;

}

int ShowMenu1() {

    printf("请选择诊室：\n");

    printf("1 内科 2 外科 3 五官科 4 口腔科\n");

    return 1;

}
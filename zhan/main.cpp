#include "stdlib.h"
#include "stdio.h"

#define MaxSize 50
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;
//初始化栈
void InitStack(SqStack &S){
   S.top = -1;//代表栈为空
}
//判断栈是否为空
bool StackEmpty(SqStack S)
{
    if (-1 == S.top)
        return true;
    return false;
}
bool Push(SqStack &S,ElemType x)
{
    if(S.top == MaxSize-1) return false;

    S.data[++S.top] = x;
    return true;//返回true表示入栈成功
}
//获取栈顶元素
bool GetTop(SqStack S,ElemType &x)
{
    if(StackEmpty(S)) return false;
    x = S.data[S.top];
    return true;
}
//遍历栈中元素
void PrintStack(SqStack S)
{
    int i = 0;
    while(S.data[i++] != NULL){
        printf("%d\t",S.data[i-1]);
    }
    printf("\n");
}
//弹出栈顶元素
bool Pop(SqStack &S,ElemType &x)
{
    if(StackEmpty(S)) return false;
    x = S.data[S.top --];
}

//判断是否是回文
bool Huiwen(char *chars)
{
    SqStack S;
    InitStack(S);
    int i;
    for(i=0;chars[i]!='\0';i++)
        Push(S,chars[i]);
    for(i=0;chars[i]!='\0';i++)
    {
        ElemType e;
        Pop(S,e);
        if(e!=chars[i])
            return false;
    }
    return true;
}


int main() {
    char str[10];
    scanf("%s", str);
    if (Huiwen(str))
        printf("%s是回文词\n", str);
    else
        printf("%s不是回文词\n", str);
    return 0;
}
/*    SqStack S;//先进后出 FILO
    bool flag;
    ElemType m;//存储栈顶元素
    InitStack(S);//初始化
    flag = StackEmpty(S);
    if(flag)
        printf("栈是空的\n");
    //入栈
    Push(S,3);
    Push(S,4);
    Push(S,5);
    //查看栈中元素
    PrintStack(S);
    flag = GetTop(S,m);
    if(flag)
        printf("拿出的栈顶元素为%d\n",m);
    else
        printf("ERROR！！！");

    //出栈
    flag = Pop(S,m);
    flag = Pop(S,m);
    flag = Pop(S,m);
    if(flag)
        printf("弹出的元素为%d\n",m);
    else
        printf("ERROR！！！");
    flag = Pop(S,m);
    if(flag)
        printf("弹出的元素为%d\n",m);
    else
        printf("ERROR！！！");

    return 0;
}
*/
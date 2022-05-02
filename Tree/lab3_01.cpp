#include "bintree.h"
void preorder1(binnode *t)
{
    seqstack s;//顺序栈s
    s.top=0;
    while((t) || (s.top!=0)) //当前处理的子树不为空或栈不为空则循环
    {
        if(t)
        {
            printf("%c ",t->data);
            push(&s,t);
            t=t->lchild;
        }
        else
        {
            t=pop(&s);
            t=t->rchild;
        }
    }
}

int main()
{   binnode *t;
    t=createbintree();   /*建立二叉树t的存储结构*/
    printf("二叉树的前序序列为(前序非递归遍历)：\n");
    preorder1(t);       /*前序非递归遍历二叉树*/
    printf("\n");
    return 0;
}

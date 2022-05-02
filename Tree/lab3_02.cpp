#include "bintree.h"
/* 	函数Depth，功能：求结点x所在的层次   */
int Depth(binnode *t,char x)
{
    int num1,num2,n;//num1,num2分别记录在左子树，右子树中查找到x的层数,n记录最终返回的结果层数
    if(t==NULL)
    {
        return 0;
    }
    else
    {
        if(t->data==x)
        {
            return 1;
        }
        num1=Depth(t->lchild,x);
        num2=Depth(t->rchild,x);
        n=num1+num2; //num1和num2之中必有一个为0
        if(num1!=0||num2!=0) //找到了x ，往回数
        {
            n++;
        }
    }
    return n;
}

int main()
{  binnode *root;
    char x;
    int k=0;
    root=createbintree();
    printf("请输入树中的1个结点值：\n");
    scanf("%c",&x);
    k=Depth(root,x);
    printf("%c结点的层次为%d\n",x,k);
}

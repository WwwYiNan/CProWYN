#include "bintree.h"

//1．	在bintree.h头文件中，设计算法binnode *createbintree()：
// 根据扩充二叉树的前序序列（字符串a）建立二叉树t；
// 将根据扩充二叉树的前序序列（字符串a）建立二叉树的t，在实验报告中画出。
//binnode *createbintree()
//{
//    //请将代码补充完整
//}
//2. 在bintree.h头文件中分别编写算法
// void preorder(binnode *t)、void inorder(binnode *t)、
// void postorder(binnode *t)
// 用以实现二叉树t的递归前序遍历、递归中序遍历、递归后序遍历。
// 编写测试程序test.c，验证第1、2题中4个函数的正确性。

//测试程序test.c用于验证相关函数的正确性：
int main()
{   binnode *t;
    t=createbintree();   /*建立二叉树t的存储结构*/
    printf("二叉树的前序序列为(前序递归遍历)：\n");
    preorder(t);       /*前序递归遍历二叉树*/
    printf("\n");
    printf("二叉树的中序序列为(中序递归遍历)：\n");
    inorder(t);       /*中序递归遍历二叉树*/
    printf("\n");
    printf("二叉树的后序序列为(后序递归遍历)：\n");
    postorder(t);       /*后序递归遍历二叉树*/
    printf("\n");
    return 0;
}




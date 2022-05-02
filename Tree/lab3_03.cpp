#include "bintree.h"

/*请将本函数补充完整，并进行测试*/
void change(binnode *t) {
    binnode *p;
    if (t) {
        p = t->lchild; //交换
        t->lchild = t->rchild;
        t->rchild = p;
        change(t->lchild); //继续递归
        change(t->rchild);
    }
}

int main() {
    binnode *root;
    root = createbintree();
    change(root);
    printf("二叉树的左右子树均交换后，前序序列为：\n");
    preorder(root);
    printf("\n");
}

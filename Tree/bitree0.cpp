#include "stdio.h"
#include "stdlib.h"
typedef struct node//type of node of binary-tree=bitree
{
    char d;//data
    struct node *l;//pointer to left child
    struct node *r;//pointer to right child
}bt;//my type of bitree
bt* create()
{
    bt *t;
    char x;
    scanf("%c",&x);
    if(x=='#') return NULL;
    else {
        t=(bt *)malloc(sizeof(bt));
        t->d=x;
        t->l=create();
        t->r=create();
        return t;
     }
}
void frontTranver(bt *p)
{
    if(p==NULL) return;
    else {
        printf("%c:self=%p leftson=%p rightson=%p\n",p->d,p,p->l,p->r);
        frontTranver(p->l);
        frontTranver(p->r);
     }
}
void middleTranver(bt *p)
{
    if(p==NULL) return;
    else {
        frontTranver(p->l);
        printf("%c:self=%p leftson=%p rightson=%p\n",p->d,p,p->l,p->r);
        frontTranver(p->r);
     }
}


void rearTranver(bt *p)
{
    if(p==NULL) return;
    else {
        frontTranver(p->l);
        frontTranver(p->r);
        printf("%c:self=%p leftson=%p rightson=%p\n",p->d,p,p->l,p->r);
     }
}

#define DIST 5;
#define PP printf("\n");for(int iii=0;iii<pos;iii++) printf(" ")
void frontShow(bt *p,int pos)
{
    if(p==NULL) {printf("#");return;}
    else
    {
        printf("%c",p->d);
        pos+=DIST;
        /*if(p->l) */printf("----");
        frontShow(p->l,pos);
        /*if(p->r) */PP;printf("+----");
        frontShow(p->r,pos);
        printf("\n");
    }
}


bt *find(bt *p,char x){
   bt *f;
   if(p->d==x) return p;
   else  if(p->l!=NULL && (f=find(p->l,x))!=NULL) return f;
   else  if(p->r!=NULL && (f=find(p->r,x))!=NULL) return f;
   else return NULL;
   }
   
main()
{
    bt *p,*f;
    p=create();
    frontShow(p,-5);
    frontTranver(p);
    f=find(p,'D');
    printf("finding:%p",f);
    printf("\nfound: %c:self=%p leftson=%p rightson=%p\n",f->d,f,f->l,f->r);
    printf("\n");
}



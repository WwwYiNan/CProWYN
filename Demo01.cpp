#include "stdio.h"


int main(){
    int a = 'a';
    int *p=&a;
    printf("%d\n",p);
    printf("%d\n",&p);

}
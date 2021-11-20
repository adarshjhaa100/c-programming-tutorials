#include<stdio.h>

// call by value, in this case, a copy of variable is made in Stack
int calculateSum(int a, int b){
    return a+b;
}

// call by reference: address of values are passed(pointers to be specific, which is discussed in pointers.c)
void calculateSumByRef(int *a, int *b){
    *b=*a+*b;   //dereferencing to access value
}


int main(void){
    int a=2,b=4;
    // printf("%d", calculateSum(2,4));
    
    calculateSumByRef(&a,&b); //pass address
    printf("\n%d", b);
    return 0;
}
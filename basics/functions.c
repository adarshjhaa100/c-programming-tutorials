#include<stdio.h>
#include<stdarg.h>

// call by value, in this case, a copy of variable is made in Stack
int calculateSum(int a, int b){
    return a+b;
}

// call by reference: address of values are passed(pointers to be specific, which is discussed in pointers.c)
void calculateSumByRef(int *a, int *b){
    *b=*a+*b;   //dereferencing to access value
}

// function with variable arglist
void var_arglist(int nvars,...){
    va_list valist;
    
    va_start(valist, nvars);

    for(int i=0;i<nvars; i++){
        printf("var %d = %d\n", i, va_arg(valist,int));
    }

    va_end(valist);
}



int main(void){
    int a=2,b=4;
    // printf("%d", calculateSum(2,4));
    
    calculateSumByRef(&a,&b); //pass address
    printf("\n%d", b);
    var_arglist(5,2,3,4,5,1);
    return 0;
}
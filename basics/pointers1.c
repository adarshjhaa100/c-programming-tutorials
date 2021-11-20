#include<stdio.h>


int main(void){

    //pointer points to address of a variable
    int variable=10;
    int* ptrvar=&variable;
    int **ptrdouble=&ptrvar; // can chain pointers 

    printf("%x\n",ptrvar); // p is format for pointer address
    printf("%x\n",ptrdouble);
    
    printf("program will creash after assinging value to null ptr's location");
    
    int *ptrnull=NULL; // null pointer, a special type of pointer that points to nothing
    *ptrnull= 32; // this is illegal as originally the pointer wasn't pointing to any location
    printf("hello");
    printf("Hello%xn", ptrnull);

    return 0;
}